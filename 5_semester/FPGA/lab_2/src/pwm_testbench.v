`timescale 1ns/1ps

module pwm_testbench();
reg clock = 0;
reg [7:0] duty_cycle;
wire led;

pwm p(
    .clock(clock),
    .duty_cycle(duty_cycle),
    .led(led)
);

always begin
    #5 clock = ~clock;
end

initial begin
    duty_cycle = 32;
    #2550
    duty_cycle = 64;
    #2550
    duty_cycle = 128;
    #2550
    duty_cycle = 255;
    #2550
    duty_cycle = 128;
    #2550
    $finish;
end

initial begin
    $dumpfile("pwm_dumb.vcd");
    $dumpvars(0, pwm_testbench);
end
endmodule