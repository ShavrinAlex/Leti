module eight_bit_adder_testbench();
reg [7:0] a, b;
wire [7:0] sum;
wire carry_out;

eight_bit_adder eba(
    .a(a),
    .b(b),
    .sum(sum),
    .carry_out(carry_out)
);

initial begin
    $monitor("|a=%b|b=%b|sum=%b|carry_out=%b|", a, b, sum, carry_out);
    //Case 1
    a = 8'b10000001;
    b = 8'b10000000;
    #100

    //Case 2
    a = 8'b01000000;
    b = 8'b01000001;
    #100
    
    //Case 3
    a = 8'b01010101;
    b = 8'b01010101;
    #100
    
    //Case 4
    a = 8'b01111111;
    b = 8'b00000001;
    #100
    
    //Case 5
    a = 8'b11111111;
    b = 8'b00000001;
    #100
    $finish;
end
endmodule