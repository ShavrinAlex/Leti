module alo#(parameter len_a = 4, parameter len_b = 4)(
    input wire clock,
    input wire [3:0] operation_code,
    input wire [len_a - 1:0] a,
    input wire [len_b - 1:0] b,
    output reg [(len_a > len_b ? len_a : len_b):0] result
);
reg [3:0] ram [0:6];
integer i;
initial begin
    result <= 0;
    for (i = 0; i < 7; i = i + 1) begin
        ram[i] <= i;
    end
end
always @(posedge clock) begin
    case(operation_code)
        ram[0]: result <= a + b;
        ram[1]: result <= a - b;  
        ram[2]: result <= a & b; 
        ram[3]: result <= a | b; 
        ram[4]: result <= a < b ? 1 : 0; 
        ram[5]: result <= a == b ? 1 : 0;
        ram[6]: result <= a ^ b;  
        default: result <= a + b;
    endcase
end

endmodule