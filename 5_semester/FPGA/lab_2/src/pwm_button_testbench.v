`timescale 1ns/1ps

module pwm_button_testbench();
reg clock = 0;
reg button = 0;
wire led;

pwm_button pb(
    .clock(clock),
    .button(button),
    .led(led)
);

always begin
    #5 clock <= ~clock;
end

always begin
    #1000
    button <= 1;
    #1
    button <= 0;
end
initial #11000 $finish;

initial begin
    $dumpfile("pwm_button_dumb.vcd");
    $dumpvars(0, pwm_button_testbench);
end
endmodule