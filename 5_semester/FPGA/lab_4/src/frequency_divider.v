module frequency_divider(
    input wire clock_in,
    input wire [4:0] n,
    output wire clock_out,
    output reg [4:0] counter
);

initial begin
    counter = 5'b00000;
end

reg clock_out_flag = 1'b0;
assign clock_out = clock_out_flag;

always @(clock_in) begin
    counter = counter + 1;
    if (counter == n) begin
        counter <= 5'b00000;
        clock_out_flag <= ~clock_out_flag;
    end
end
endmodule