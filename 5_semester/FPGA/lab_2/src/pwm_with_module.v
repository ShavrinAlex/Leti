module pwm_with_module(
    input clock,
    output led
);

reg[7:0] counter = 0;
wire [7:0] duty_cycle;
reg [7:0] start_duty_value = 20;

duty_generator dg(
    .in(start_duty_value),
    .out(duty_cycle)
);

assign led = (counter <= duty_cycle) ? 1 : 0;

always @(posedge clock) begin 
    if(clock) begin 
        if(counter < 100) begin
            counter <= counter+1;
        end else begin
            counter <= 0;
        end
    end
end
endmodule