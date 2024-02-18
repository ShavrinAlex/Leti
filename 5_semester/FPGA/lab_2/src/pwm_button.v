module frequency_divider(
    input wire clock_in,
    output reg clock_out
);
reg [27:0] counter = 1;

always @(posedge clock_in) begin
    counter = counter + 1;
    if (counter == 28'd13_500_000 / 200) begin
        counter <= 1;
        clock_out <= ~clock_out;
    end
end
endmodule

module pwm_button(
    input clock,
    input button,
    output led
);

reg[7:0] counter = 0;
reg [7:0] duty_cycle = 0;
assign led = (counter <= duty_cycle) ? 1 : 0;

always @(posedge clock ) begin
    if(counter < 100) begin
        counter <= counter+1;
    end else begin
        counter <= 0;
    end
end
always @(negedge button) begin 
   if(duty_cycle >= 100) begin
        duty_cycle <= 0;
    end else begin
        duty_cycle <= duty_cycle + 25;
    end
end
endmodule

module test(
    input clk,
    input btn,
    output led
);
wire w;
frequency_divider f(
    .clock_in(clk),
    .clock_out(w)
);
pwm_button pb(
    .clock(w),
    .button(btn),
    .led(led)
);
endmodule