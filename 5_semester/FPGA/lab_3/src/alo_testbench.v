module alo_testbench();

reg clock;
reg [3:0] operation_code;
reg [len_a - 1:0] a;
reg [len_b - 1:0] b;
wire [(len_a > len_b ? len_a : len_b):0] result;
parameter len_a = 4;
parameter len_b = 4;

alo#(len_a, len_b) my_alo(
    .clock(clock),
    .operation_code(operation_code),
    .a(a),
    .b(b),
    .result(result)
);

initial begin
    a = 4'b1101;
    b = 4'b0001;
    $monitor("|time=%0t|operation_code=%d|a=%b|b=%b|result=%b|", $time, operation_code, a, b, result);
    for (operation_code = 0; operation_code < 7; operation_code = operation_code + 1) begin 
        clock = 1;
        #5;
        clock = 0;
        #5;
    end
end

endmodule