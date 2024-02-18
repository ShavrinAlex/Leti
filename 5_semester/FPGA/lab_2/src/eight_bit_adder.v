module eight_bit_adder(
    input wire [7:0] a,
    input wire [7:0] b,
    output wire [7:0] sum,
    output wire carry_out
);
wire [7:0] carry;
assign carry_out = carry[7];
for (genvar i = 0; i < 8; i = i + 1) begin
    if (i == 0) begin
        one_bit_adder oba(
            .a(a[i]),
            .b(b[i]),
            .carry_in(1'b0),
            .sum(sum[i]),
            .carry_out(carry[i])
        );
    end else begin
        one_bit_adder oba(
            .a(a[i]),
            .b(b[i]),
            .carry_in(carry[i-1]),
            .sum(sum[i]),
            .carry_out(carry[i])
        );
    end
end
endmodule