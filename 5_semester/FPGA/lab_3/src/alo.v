module alo#(parameter len_a = 4, parameter len_b = 4)(
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

always @(operation_code) begin
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

module test(
    input wire button_operation,
    input wire button_result,
    output wire led
);
parameter len_a = 4;
parameter len_b = 4;
parameter len_result = len_a > len_b ? len_a : len_b;
reg [3:0] operation_code = 0;
reg [len_a - 1:0] a = 4'b1101;
reg [len_b - 1:0] b = 4'b0001;
reg cur_index;
assign led = cur_index;
wire [len_result:0] result;

alo#(len_a, len_b) my_alo(
    .operation_code(operation_code),
    .a(a),
    .b(b),
    .result(result)
);

integer i = 0;

always @(negedge button_operation) begin
    operation_code <= operation_code + 1;
    if (operation_code > 6) begin
        operation_code <= 0;
    end
end

always @(negedge button_result) begin
    if (i > len_result) begin
        i = 0;
    end
    cur_index = result[i];
    i = i + 1;
end
endmodule