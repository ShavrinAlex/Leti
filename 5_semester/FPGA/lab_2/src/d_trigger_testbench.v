module d_trigger_testbench();
reg D, clock;
wire Q;

d_trigger dt(
    .D(D),
    .clock(clock),
    .Q(Q)
);

initial begin
    $monitor("|D=%b|clock=%b|Q=%b|", D, clock, Q);

    D = 1'b0;
    clock = 1'b0;
    #4
    D = 1'b1;
    #4
    D = 1'b0;
    #3
    $finish;
end

// Генератор тактовых импульсов
always begin
    #2  clock = ~clock;
end

endmodule