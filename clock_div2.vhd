library ieee;
use ieee.std_logic_1164.all;

entity clock_div2 is
  port (
    clk_in  : in  std_logic;
    reset_n : in  std_logic;
    clk_out : out std_logic
  );
end entity;

architecture rtl of clock_div2 is
  signal ff : std_logic := '0';
begin
  process(clk_in, reset_n)
  begin
    if reset_n = '0' then
      ff <= '0';
    elsif rising_edge(clk_in) then
      ff <= not ff;
    end if;
  end process;

  clk_out <= ff;
end architecture;
