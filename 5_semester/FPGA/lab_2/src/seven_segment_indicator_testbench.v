module seven_segment_indicator_testbench();
reg [3:0] code;
wire [6:0] segments;

seven_segment_indicator ssi(
    .code(code),
    .segments(segments)
);

initial begin
    $monitor("|code=%b|segments=%b", code, segments);
    code = 4'b0;
    #21
    $finish;
end

always begin
    #2 code = code + 1;
end

endmodule