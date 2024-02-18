module d_trigger(
    input wire D,
    input wire clock,
    output reg Q
);

always @(posedge clock) begin
    Q <= D;
end
endmodule