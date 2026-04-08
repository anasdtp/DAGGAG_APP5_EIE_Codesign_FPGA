library ieee;
use ieee.std_logic_1164.all;

entity CONTROLE is
  port (
    CLOCK_50        : in  std_logic;
    KEY             : in  std_logic_vector(0 downto 0);
    SW              : in  std_logic_vector(3 downto 0);
    LED             : out std_logic_vector(7 downto 0);

    VCC3P3_PWRON_n  : out std_logic;
    IR_LED_ON       : out std_logic;

    LTC_ADC_CONVST  : out std_logic;
    LTC_ADC_SCK     : out std_logic;
    LTC_ADC_SDI     : out std_logic;
    LTC_ADC_SDO     : in  std_logic
  );
end entity;

architecture rtl of CONTROLE is
  component clock_div2 is
    port (
      clk_in  : in  std_logic;
      reset_n : in  std_logic;
      clk_out : out std_logic
    );
  end component;

  component pulse_gen is
    generic (
      CLK_HZ   : positive := 25000000;
      PULSE_HZ : positive := 2000
    );
    port (
      clk     : in  std_logic;
      reset_n : in  std_logic;
      pulse   : out std_logic
    );
  end component;

  component capteurs_sol is
    port (
      clk          : in  std_logic;
      reset_n      : in  std_logic;
      data_capture : in  std_logic;
      data_readyr  : out std_logic;
      data0r       : out std_logic_vector(7 downto 0);
      data1r       : out std_logic_vector(7 downto 0);
      data2r       : out std_logic_vector(7 downto 0);
      data3r       : out std_logic_vector(7 downto 0);
      data4r       : out std_logic_vector(7 downto 0);
      data5r       : out std_logic_vector(7 downto 0);
      data6r       : out std_logic_vector(7 downto 0);
      ADC_CONVSTr  : out std_logic;
      ADC_SCK      : out std_logic;
      ADC_SDIr     : out std_logic;
      ADC_SDO      : in  std_logic
    );
  end component;

  component calculateur_cable is
    port (
      clk        : in  std_logic;
      reset_n    : in  std_logic;
      start      : in  std_logic;
      op_sel     : in  std_logic_vector(1 downto 0);
      data_ir    : in  std_logic_vector(7 downto 0);
      data_jr    : in  std_logic_vector(7 downto 0);
      result     : out std_logic_vector(7 downto 0);
      overflow   : out std_logic;
      data_ready : out std_logic
    );
  end component;

  signal clk_25m           : std_logic;
  signal data_capture_sig  : std_logic;
  signal sensor_ready      : std_logic;
  signal sensor_ready_d    : std_logic := '0';
  signal calc_start        : std_logic := '0';

  signal data0_sig         : std_logic_vector(7 downto 0);
  signal data1_sig         : std_logic_vector(7 downto 0);
  signal data2_sig         : std_logic_vector(7 downto 0);
  signal data3_sig         : std_logic_vector(7 downto 0);
  signal data4_sig         : std_logic_vector(7 downto 0);
  signal data5_sig         : std_logic_vector(7 downto 0);
  signal data6_sig         : std_logic_vector(7 downto 0);

  signal calc_data_i       : std_logic_vector(7 downto 0);
  signal calc_data_j       : std_logic_vector(7 downto 0);
  signal calc_result       : std_logic_vector(7 downto 0);
  signal calc_overflow     : std_logic;
  signal calc_ready        : std_logic;
begin
  -- Sensor board power enable
  VCC3P3_PWRON_n <= '0';
  IR_LED_ON <= '1';

  -- 50 MHz -> 25 MHz to stay below capteurs_sol 40 MHz limit
  u_div2: clock_div2
    port map (
      clk_in  => CLOCK_50,
      reset_n => KEY(0),
      clk_out => clk_25m
    );

  -- Generate data_capture pulse at 2 kHz
  u_pulse: pulse_gen
    generic map (
      CLK_HZ   => 25000000,
      PULSE_HZ => 2000
    )
    port map (
      clk     => clk_25m,
      reset_n => KEY(0),
      pulse   => data_capture_sig
    );

  u_capteurs: capteurs_sol
    port map (
      clk          => clk_25m,
      reset_n      => KEY(0),
      data_capture => data_capture_sig,
      data_readyr  => sensor_ready,
      data0r       => data0_sig,
      data1r       => data1_sig,
      data2r       => data2_sig,
      data3r       => data3_sig,
      data4r       => data4_sig,
      data5r       => data5_sig,
      data6r       => data6_sig,
      ADC_CONVSTr  => LTC_ADC_CONVST,
      ADC_SCK      => LTC_ADC_SCK,
      ADC_SDIr     => LTC_ADC_SDI,
      ADC_SDO      => LTC_ADC_SDO
    );

  -- SW(2)=0: use sensor0 and sensor1, SW(2)=1: use sensor2 and sensor3
  calc_data_i <= data0_sig when SW(2) = '0' else data2_sig;
  calc_data_j <= data1_sig when SW(2) = '0' else data3_sig;

  -- One-cycle start on sensor_ready rising edge (enabled by SW(3))
  process(clk_25m, KEY(0))
  begin
    if KEY(0) = '0' then
      sensor_ready_d <= '0';
      calc_start <= '0';
    elsif rising_edge(clk_25m) then
      sensor_ready_d <= sensor_ready;
      if (sensor_ready = '1' and sensor_ready_d = '0' and SW(3) = '1') then
        calc_start <= '1';
      else
        calc_start <= '0';
      end if;
    end if;
  end process;

  u_calc: calculateur_cable
    port map (
      clk        => clk_25m,
      reset_n    => KEY(0),
      start      => calc_start,
      op_sel     => SW(1 downto 0),
      data_ir    => calc_data_i,
      data_jr    => calc_data_j,
      result     => calc_result,
      overflow   => calc_overflow,
      data_ready => calc_ready
    );

  -- LED mapping: easy bench debug
  LED(7) <= calc_ready;
  LED(6) <= calc_overflow;
  LED(5 downto 0) <= calc_result(5 downto 0);
end architecture;
