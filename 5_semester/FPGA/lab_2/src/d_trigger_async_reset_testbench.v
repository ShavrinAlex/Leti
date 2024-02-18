module d_trigger_async_reset_testbench();
reg D, clock, async_reset;
wire Q;

d_trigger_async_reset dtar(
    .D(D),
    .clock(clock),
    .async_reset(async_reset),
    .Q(Q)
);

initial begin
    $monitor("|D=%b|clock=%b|async_reset=%b|Q=%b|", D, clock, async_reset, Q);

    D = 1;
    clock = 0;
    async_reset = 0;
    #4
    async_reset = 1;
    #4
    async_reset = 0;
    #3
    $finish;
end

// Генератор тактовых импульсов
always begin
    #2  clock = ~clock;
end

endmodule