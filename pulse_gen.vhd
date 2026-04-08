library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity pulse_gen is
  generic (
    CLK_HZ   : positive := 25000000;
    PULSE_HZ : positive := 2000
  );
  port (
    clk     : in  std_logic;
    reset_n : in  std_logic;
    pulse   : out std_logic
  );
end entity;

architecture rtl of pulse_gen is
  constant DIVIDER : positive := CLK_HZ / PULSE_HZ;
  signal cnt       : unsigned(31 downto 0) := (others => '0');
begin
  process(clk, reset_n)
  begin
    if reset_n = '0' then
      cnt   <= (others => '0');
      pulse <= '0';
    elsif rising_edge(clk) then
      if cnt = to_unsigned(DIVIDER - 1, cnt'length) then
        cnt   <= (others => '0');
        pulse <= '1';
      else
        cnt   <= cnt + 1;
        pulse <= '0';
      end if;
    end if;
  end process;
end architecture;
