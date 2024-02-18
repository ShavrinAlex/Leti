/* Это 3-х битовый суммирующий счетчик */

module counter (
input wire clock , // Запуск входа счетчика 
input wire reset , //  сброс
input wire enable , // Разрешающий сигнал для счетчика
output reg [2:0]counter // 3-х битовый вектор выхода счетчика
);

always @ (posedge clock)
begin : MY_COUNTER
  if (reset == 1'b1) begin
    counter <= 3'b000;
  end
  else if (enable == 1'b1) begin
    counter <= counter + 1;
  end
end
endmodule
