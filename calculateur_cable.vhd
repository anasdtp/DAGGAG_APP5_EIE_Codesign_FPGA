library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity calculateur_cable is
  port (
    clk        : in  std_logic;
    reset_n    : in  std_logic;
    start      : in  std_logic;
    op_sel     : in  std_logic_vector(1 downto 0); -- 00:add 01:sub 10:amp x2 11:att /2
    data_ir    : in  std_logic_vector(7 downto 0);
    data_jr    : in  std_logic_vector(7 downto 0);
    result     : out std_logic_vector(7 downto 0);
    overflow   : out std_logic;
    data_ready : out std_logic
  );
end entity;

architecture rtl of calculateur_cable is
  signal res_reg : unsigned(7 downto 0) := (others => '0');
  signal ovf_reg : std_logic := '0';
  signal rdy_reg : std_logic := '0';
begin
  process(clk, reset_n)
    variable a8  : unsigned(7 downto 0);
    variable b8  : unsigned(7 downto 0);
    variable ext : unsigned(8 downto 0);
  begin
    if reset_n = '0' then
      res_reg <= (others => '0');
      ovf_reg <= '0';
      rdy_reg <= '0';
    elsif rising_edge(clk) then
      rdy_reg <= '0';
      if start = '1' then
        a8 := unsigned(data_ir);
        b8 := unsigned(data_jr);
        ovf_reg <= '0';

        case op_sel is
          when "00" =>
            ext := resize(a8, 9) + resize(b8, 9);
            if ext > to_unsigned(255, 9) then
              res_reg <= to_unsigned(255, 8);
              ovf_reg <= '1';
            else
              res_reg <= ext(7 downto 0);
            end if;

          when "01" =>
            if a8 >= b8 then
              res_reg <= a8 - b8;
            else
              res_reg <= (others => '0');
              ovf_reg <= '1';
            end if;

          when "10" =>
            ext := shift_left(resize(a8, 9), 1);
            if ext > to_unsigned(255, 9) then
              res_reg <= to_unsigned(255, 8);
              ovf_reg <= '1';
            else
              res_reg <= ext(7 downto 0);
            end if;

          when others =>
            res_reg <= shift_right(a8, 1);
        end case;

        rdy_reg <= '1';
      end if;
    end if;
  end process;

  result     <= std_logic_vector(res_reg);
  overflow   <= ovf_reg;
  data_ready <= rdy_reg;
end architecture;
