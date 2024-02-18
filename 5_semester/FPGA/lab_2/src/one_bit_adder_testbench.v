module one_bit_adder_testbench();
reg a, b, carry_in;
wire sum, carry_out;

one_bit_adder oba(
    .a(a),
    .b(b),
    .carry_in(carry_in),
    .sum(sum),
    .carry_out(carry_out)
);

initial begin
    $monitor("|a=%b|b=%b|carry_in=%b|sum=%b|carry_out=%b|", a, b, carry_in, sum, carry_out);
    //Case 1
    a = 0;
    b = 0;
    carry_in = 0;
    #100

    //Case 2
    a = 0;
    b = 0;
    carry_in = 1;
    #100

    //Case 3
    a = 0;
    b = 1;
    carry_in = 0;
    #100

    //Case 4
    a = 0;
    b = 1;
    carry_in = 1;
    #100

    //Case 5
    a = 1;
    b = 0;
    carry_in = 0;
    #100

    //Case 6
    a = 1;
    b = 0;
    carry_in = 1;
    #100

    //Case 7
    a = 1;
    b = 1;
    carry_in = 0;
    #100

    //Case 8
    a = 1;
    b = 1;
    carry_in = 1;
    #100
    $finish;
end
endmodule