/* Это 3-х битовый суммирующий счетчик */

module another_counter (
input wire clock , // Запуск входа счетчика 
input wire reset , // Синхронный сброс с активным высоким уровнем сигнала
input wire enable , // Разрешающий сигнал для счетчика с активным высоким уровнем
output reg [2:0]counter // 3-х битовый вектор выхода счетчика
);

always @ (clock)
begin : MY_COUNTER
  if (reset == 1'b1) begin
    counter <= 3'b000;
  end
  else if (enable == 1'b1) begin
    counter <= counter + 1;
  end
end
endmodule