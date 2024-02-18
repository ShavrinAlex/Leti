`timescale 1ns/1ps

module pwm_with_module_testbench();
reg clock = 0;
wire led;

pwm_with_module pwm(
    .clock(clock),
    .led(led)
);

always begin
    #5 clock <= ~clock;
end

initial #11000 $finish;

initial begin
    $dumpfile("pwm_with_module_dumb.vcd");
    $dumpvars(0, pwm_with_module_testbench);
end
endmodule