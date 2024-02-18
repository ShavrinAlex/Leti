module seven_segment_indicator_switcher_testbench();
wire [3:0] code;
reg switch;
wire [6:0] segments;

seven_segment_indicator_switcher ssis(
    .code(code),
    .switch(switch),
    .segments(segments)
);

initial begin
    $monitor("|code=%b|segments=%b", code, segments);
    switch = 1'b0;
    #21
    $finish;
end

always begin
    #2 switch = ~switch;
end

endmodule