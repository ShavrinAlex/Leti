module pwm(
    input wire clock,
    input wire [7:0] duty_cycle,
    output wire led
);

reg[7:0] counter = 0;

assign led = (counter <= duty_cycle) ? 1 : 0;

always @(posedge clock) begin 
    if(clock) begin 
        if(counter < 255) begin
            counter <= counter + 1;
        end else begin
            counter <= 0;
        end
    end
end
endmodule