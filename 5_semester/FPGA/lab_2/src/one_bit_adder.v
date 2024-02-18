module one_bit_adder(
    input wire a,
    input wire b,
    input wire carry_in,
    output wire sum,
    output wire carry_out
);

assign sum = a ^ b ^ carry_in;
assign carry_out = (a && b) || (carry_in && (a ^ b));

endmodule