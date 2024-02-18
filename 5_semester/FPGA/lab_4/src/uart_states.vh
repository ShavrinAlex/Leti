// Состояния UART

`define RESET           3'b001  // сброс
`define IDLE            3'b010  // индикатор не активного передатчика
`define START           3'b011  // начало передачи
`define TRANSMITTING    3'b100  // передаются данные
`define STOP            3'b101  // конец передачи