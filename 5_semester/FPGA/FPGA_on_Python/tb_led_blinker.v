module tb_led_blinker;

reg input;
wire led;

initial begin
    $from_myhdl(
        input
    );
    $to_myhdl(
        led
    );
end

led_blinker dut(
    input,
    led
);

endmodule
