module counter_testbench();
// Объявление вводов как регистров, а вывода как шины 
reg clock_in, reset_in, enable_in;
wire [2:0] counter_out;   
// Инициализация всех переменных
initial begin        
    $display ("time\t clk reset enable counter");	
    $monitor ("%g\t %b   %b     %b      %b", 
                $time, clock_in, reset_in, enable_in, counter_out);	
    clock_in = 0;          // Начальное значение тактов счетчика
    reset_in = 0;          // Задание начального значения сброса
    enable_in = 0;         // Задание начального сигнала разрешения
    #4   reset_in = 1;      // Активировать сброс
    #4   reset_in = 0;      // Деактивировать сброс
    #4   enable_in = 1;     // Активировать разрешение
    #36  enable_in = 0;     // Деактивировать разрешение
    #3   $finish;           // Завершить симуляцию
end
// Генератор тактовых импульсов
always begin
    #2  clock_in = ~clock_in; // Переключение вывода clock каждые 2 такта
end
// Подключаем проверяемое устройство
counter cnt(
.clock(clock_in),
.reset(reset_in),
.enable(enable_in),
.counter(counter_out)
);
endmodule
