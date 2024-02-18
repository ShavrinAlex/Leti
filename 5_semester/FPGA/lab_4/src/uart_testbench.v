`timescale 1 ns / 100 ps
`define SENTENCE_LEN 11

module uart_tb();
    reg clk = 0;
    // rx interface
    reg rxEn = 1;
    wire [7:0] out;
    wire rxDone;
    wire rxBusy;
    wire rxErr;

    // tx interface
    reg txEn = 1;
    reg txStart = 1;
    reg [7:0] in;
    wire txDone;
    wire txBusy;
    
    wire tx_rx_pipe;
    reg [7:0] sentence [0:`SENTENCE_LEN-1];

    uart u (
        .clk(clk),
        .rx(tx_rx_pipe),
        .rxEn(rxEn),
        .out(out),
        .rxDone(rxDone),
        .rxBusy(rxBusy),
        .rxErr(rxErr),
        .tx(tx_rx_pipe),
        .txEn(txEn),
        .txStart(txStart),
        .in(in),
        .txDone(txDone),
        .txBusy(txBusy)
    );

    // simulation init
    initial begin 
        sentence[0] = 8'h68;    // 'h68 - код символа 'h' в шестнадцатеричной системе
        sentence[1] = 8'h65;    // 'h65 - код символа 'e' в шестнадцатеричной системе
        sentence[2] = 8'h6C;    // 'h6C - код символа 'l' в шестнадцатеричной системе
        sentence[3] = 8'h6C;    // 'h6C - код символа 'l' в шестнадцатеричной системе
        sentence[4] = 8'h6F;    // 'h6F - код символа 'o' в шестнадцатеричной системе
        sentence[5] = 8'h20;    // 'h20 - код символа пробела в шестнадцатеричной системе
        sentence[6] = 8'h77;    // 'h77 - код символа 'w' в шестнадцатеричной системе
        sentence[7] = 8'h6F;    // 'h6F - код символа 'o' в шестнадцатеричной системе
        sentence[8] = 8'h72;    // 'h72 - код символа 'r' в шестнадцатеричной системе
        sentence[9] = 8'h6C;    // 'h6C - код символа 'l' в шестнадцатеричной системе
        sentence[10] = 8'h64;   // 'h64 - код символа 'd' в шестнадцатеричной системе
        in = sentence[0];
        $dumpfile("uart_dump.vcd");
        $dumpvars(0, uart_tb);
        $monitor("%d %c", out, out);  
    end
    
    integer i = 1;
    always @(posedge txDone) begin
        in = sentence[i];
        i = i + 1;
        if (i > 12) begin
            $finish();
        end
    end
    
    // clock generator
    always begin
        #1 clk = ~clk;
    end

endmodule