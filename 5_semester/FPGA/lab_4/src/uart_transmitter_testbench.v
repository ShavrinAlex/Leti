`timescale 1 ns / 100 ps
`define SENTENCE_LEN 11

module uart_transmitter_tb();
    reg       clk = 1;
    reg       en = 1;
    reg       start = 1;
    reg [7:0] in = 0;
    wire      out;
    wire      done;
    wire      busy;

    reg [7:0] sentence [0:`SENTENCE_LEN-1];
   

    uart_transmitter utx (
        .clk    ( clk    ),
        .enable ( en     ),
        .start  ( start  ),
        .in     ( in     ),
        .out    ( out    ),
        .done   ( done   ),
        .busy   ( busy   )
    );

    // simulation init
    initial begin 
/*
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
        for (integer i = 0; i < `SENTENCE_LEN; i = i+1) begin
            in = sentence[i];
            $display("%c %b", sentence[i], sentence[i]);
            #44*i; 
 
        end*/
        
        in = 8'h68;    // 'h68 - код символа 'h' в шестнадцатеричной системе
        #44 in = 8'h65;    // 'h65 - код символа 'e' в шестнадцатеричной системе
        #88 in = 8'h6C;    // 'h6C - код символа 'l' в шестнадцатеричной системе
        #132 in = 8'h6C;    // 'h6C - код символа 'l' в шестнадцатеричной системе
        #176 in = 8'h6F;    // 'h6F - код символа 'o' в шестнадцатеричной системе
        #220 in = 8'h20;    // 'h20 - код символа пробела в шестнадцатеричной системе
        #264 in = 8'h77;    // 'h77 - код символа 'w' в шестнадцатеричной системе
        #308 in = 8'h6F;    // 'h6F - код символа 'o' в шестнадцатеричной системе
        #352 in = 8'h72;    // 'h72 - код символа 'r' в шестнадцатеричной системе
        #396 in = 8'h6C;    // 'h6C - код символа 'l' в шестнадцатеричной системе
        #440 in = 8'h64;   // 'h64 - код символа 'd' в шестнадцатеричной системе
        #53 $finish();
        $dumpfile("test_dump.vcd");
        $dumpvars(0, uart_transmitter_tb);
        //$display("en start busy out done");
        //$monitor("%b %b %b %b %b", en, start, busy, out, done); 
    end
    // clock generator
    always begin
        #2 clk = ~clk;
    end

endmodule