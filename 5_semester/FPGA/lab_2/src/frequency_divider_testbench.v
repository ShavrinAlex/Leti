`timescale 1ns/1ps

module frequency_divider_testbench();
reg clock_in;
reg [4:0] n;
integer step;
wire clock_out;
wire [4:0] counter;

frequency_divider fd(
    .clock_in(clock_in),
    .n(n),
    .clock_out(clock_out),
    .counter(counter)
);

initial begin
    $dumpfile("frequency_divider_dump.vcd");
    $dumpvars(0, frequency_divider_testbench);
    $monitor("%d|clock_in=%b|clock_out=%b|counter=%d|", step, clock_in, clock_out, counter);

    step = 0;
    clock_in = 1'b0;
    n = 5'b11010;

    #181
    $finish;
end

// Генератор тактовых импульсов
always begin
    #2  
    step <= step + 1;
    clock_in <= ~clock_in;
    
end
endmodule