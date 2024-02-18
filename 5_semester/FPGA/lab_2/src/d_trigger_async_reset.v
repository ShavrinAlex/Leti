module d_trigger_async_reset(
    input wire D,
    input wire clock,
    input wire async_reset,
    output reg Q
);

always @(posedge clock or posedge async_reset) begin
    if(async_reset == 1'b1) begin
        Q <= 1'b0; 
    end else begin
        Q <= D; 
    end
end 
endmodule 