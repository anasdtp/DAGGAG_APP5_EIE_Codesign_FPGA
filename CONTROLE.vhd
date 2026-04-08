library ieee;
use ieee.std_logic_1164.all;

entity CONTROLE is
  port (
    CLOCK_50        : in  std_logic;
    KEY             : in  std_logic_vector(0 downto 0);
    SW              : in  std_logic_vector(3 downto 0);
    LED             : out std_logic_vector(7 downto 0);

    DRAM_CLK        : out std_logic;
    DRAM_CKE        : out std_logic;
    DRAM_ADDR       : out std_logic_vector(12 downto 0);
    DRAM_BA         : out std_logic_vector(1 downto 0);
    DRAM_CS_N       : out std_logic;
    DRAM_CAS_N      : out std_logic;
    DRAM_RAS_N      : out std_logic;
    DRAM_WE_N       : out std_logic;
    DRAM_DQ         : inout std_logic_vector(15 downto 0);
    DRAM_DQM        : out std_logic_vector(1 downto 0);

    VCC3P3_PWRON_n  : out std_logic;
    IR_LED_ON       : out std_logic;

    LTC_ADC_CONVST  : out std_logic;
    LTC_ADC_SCK     : out std_logic;
    LTC_ADC_SDI     : out std_logic;
    LTC_ADC_SDO     : in  std_logic
  );
end entity;

architecture rtl of CONTROLE is
  component nios_system_sdram is
    port (
      clk_clk               : in    std_logic;
      reset_reset_n         : in    std_logic;
      sdram_clk_clk         : out   std_logic;
      switches_export       : in    std_logic_vector(7 downto 0);
      leds_export           : out   std_logic_vector(7 downto 0);
      sdram_wire_addr       : out   std_logic_vector(12 downto 0);
      sdram_wire_ba         : out   std_logic_vector(1 downto 0);
      sdram_wire_cas_n      : out   std_logic;
      sdram_wire_cke        : out   std_logic;
      sdram_wire_cs_n       : out   std_logic;
      sdram_wire_dq         : inout std_logic_vector(15 downto 0);
      sdram_wire_dqm        : out   std_logic_vector(1 downto 0);
      sdram_wire_ras_n      : out   std_logic;
      sdram_wire_we_n       : out   std_logic;
      motor_left_export     : out   std_logic_vector(13 downto 0);
      motor_right_export    : out   std_logic_vector(13 downto 0);
      sensor_control_export : out   std_logic_vector(7 downto 0);
      sensor_status_export  : in    std_logic_vector(7 downto 0);
      sensor_data0_export   : in    std_logic_vector(7 downto 0);
      sensor_data1_export   : in    std_logic_vector(7 downto 0);
      sensor_data2_export   : in    std_logic_vector(7 downto 0);
      sensor_data3_export   : in    std_logic_vector(7 downto 0);
      sensor_data4_export   : in    std_logic_vector(7 downto 0);
      sensor_data5_export   : in    std_logic_vector(7 downto 0);
      sensor_data6_export   : in    std_logic_vector(7 downto 0);
      kp_export             : out   std_logic_vector(11 downto 0);
      kd_export             : out   std_logic_vector(11 downto 0);
      base_speed_export     : out   std_logic_vector(11 downto 0);
      start_sl_export       : out   std_logic;
      fin_sl_export         : in    std_logic;
      start_rot_export      : out   std_logic;
      dir_rot_export        : out   std_logic;
      fin_rot_export        : in    std_logic
    );
  end component;

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
  signal calc_start        : std_logic;

  signal switches_nios     : std_logic_vector(7 downto 0);
  signal leds_nios         : std_logic_vector(7 downto 0);

  signal sensor_control_sig : std_logic_vector(7 downto 0);
  signal sensor_status_sig  : std_logic_vector(7 downto 0);

  signal data0_to_nios     : std_logic_vector(7 downto 0);
  signal data1_to_nios     : std_logic_vector(7 downto 0);
  signal data2_to_nios     : std_logic_vector(7 downto 0);
  signal data3_to_nios     : std_logic_vector(7 downto 0);
  signal data4_to_nios     : std_logic_vector(7 downto 0);
  signal data5_to_nios     : std_logic_vector(7 downto 0);
  signal data6_to_nios     : std_logic_vector(7 downto 0);

  signal kp_sig            : std_logic_vector(11 downto 0);
  signal kd_sig            : std_logic_vector(11 downto 0);
  signal base_speed_sig    : std_logic_vector(11 downto 0);
  signal start_sl_sig      : std_logic;
  signal fin_sl_sig        : std_logic := '0';
  signal start_rot_sig     : std_logic;
  signal dir_rot_sig       : std_logic;
  signal fin_rot_sig       : std_logic := '0';

  signal motor_left_cmd    : std_logic_vector(13 downto 0);
  signal motor_right_cmd   : std_logic_vector(13 downto 0);

  signal start_sl_d        : std_logic := '0';
  signal calc_done_latched : std_logic := '0';
  signal calc_ovf_latched  : std_logic := '0';

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
  switches_nios <= "0000" & SW;
  LED <= leds_nios;

  -- Sensor board power enable
  VCC3P3_PWRON_n <= '0';
  IR_LED_ON <= '1';

  -- Nios/Qsys system generated by Platform Designer
  u_nios: nios_system_sdram
    port map (
      clk_clk               => CLOCK_50,
      reset_reset_n         => KEY(0),
      sdram_clk_clk         => DRAM_CLK,
      switches_export       => switches_nios,
      leds_export           => leds_nios,
      sdram_wire_addr       => DRAM_ADDR,
      sdram_wire_ba         => DRAM_BA,
      sdram_wire_cas_n      => DRAM_CAS_N,
      sdram_wire_cke        => DRAM_CKE,
      sdram_wire_cs_n       => DRAM_CS_N,
      sdram_wire_dq         => DRAM_DQ,
      sdram_wire_dqm        => DRAM_DQM,
      sdram_wire_ras_n      => DRAM_RAS_N,
      sdram_wire_we_n       => DRAM_WE_N,
      motor_left_export     => motor_left_cmd,
      motor_right_export    => motor_right_cmd,
      sensor_control_export => sensor_control_sig,
      sensor_status_export  => sensor_status_sig,
      sensor_data0_export   => data0_to_nios,
      sensor_data1_export   => data1_to_nios,
      sensor_data2_export   => data2_to_nios,
      sensor_data3_export   => data3_to_nios,
      sensor_data4_export   => data4_to_nios,
      sensor_data5_export   => data5_to_nios,
      sensor_data6_export   => data6_to_nios,
      kp_export             => kp_sig,
      kd_export             => kd_sig,
      base_speed_export     => base_speed_sig,
      start_sl_export       => start_sl_sig,
      fin_sl_export         => fin_sl_sig,
      start_rot_export      => start_rot_sig,
      dir_rot_export        => dir_rot_sig,
      fin_rot_export        => fin_rot_sig
    );

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

  -- Software-selectable operands:
  -- sensor_control(2)=0 -> operands from kp/kd PIOs
  -- sensor_control(2)=1 -> operands from sensor0/sensor1
  calc_data_i <= kp_sig(7 downto 0) when sensor_control_sig(2) = '0' else data0_sig;
  calc_data_j <= kd_sig(7 downto 0) when sensor_control_sig(2) = '0' else data1_sig;

  -- One-cycle start generated from start_sl rising edge (software pulse)
  process(clk_25m, KEY(0))
  begin
    if KEY(0) = '0' then
      start_sl_d <= '0';
      calc_start <= '0';
    elsif rising_edge(clk_25m) then
      start_sl_d <= start_sl_sig;
      if (start_sl_sig = '1' and start_sl_d = '0') then
        calc_start <= '1';
      else
        calc_start <= '0';
      end if;
    end if;
  end process;

  -- Latch status bits so software can poll safely
  process(clk_25m, KEY(0))
  begin
    if KEY(0) = '0' then
      calc_done_latched <= '0';
      calc_ovf_latched <= '0';
    elsif rising_edge(clk_25m) then
      if calc_start = '1' then
        calc_done_latched <= '0';
        calc_ovf_latched <= '0';
      elsif calc_ready = '1' then
        calc_done_latched <= '1';
        calc_ovf_latched <= calc_overflow;
      end if;
    end if;
  end process;

  u_calc: calculateur_cable
    port map (
      clk        => clk_25m,
      reset_n    => KEY(0),
      start      => calc_start,
      op_sel     => sensor_control_sig(1 downto 0),
      data_ir    => calc_data_i,
      data_jr    => calc_data_j,
      result     => calc_result,
      overflow   => calc_overflow,
      data_ready => calc_ready
    );

  -- Route hardware observables back to Nios PIO inputs
  data0_to_nios <= data0_sig;
  data1_to_nios <= data1_sig;
  data2_to_nios <= data2_sig;
  data3_to_nios <= data3_sig;
  data4_to_nios <= data4_sig;
  data5_to_nios <= data5_sig;
  data6_to_nios <= calc_result;

  sensor_status_sig <= "00000" & sensor_ready & calc_ovf_latched & calc_done_latched;
  fin_sl_sig <= calc_done_latched;
  fin_rot_sig <= '0';
end architecture;
