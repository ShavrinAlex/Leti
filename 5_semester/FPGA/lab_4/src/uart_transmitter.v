// 8-bit UART Transmitter.
// Able to transmit 8 bits of serial data, one start bit, one stop bit.
// When transmit is complete {done} is driven high for one clock cycle.
// When transmit is in progress {busy} is driven high.
// Clock should be decreased to baud rate.
`include "uart_states.vh"
`define SENTENCE_LEN 11


module uart_transmitter(
    input  wire       clk,      // baud rate
    input  wire       enable,   // enable signal
    input  wire       start,    // start of transaction
    input  wire [7:0] in,       // data to transmit
    output reg        out,      // tx
    output reg        done,     // end on transaction
    output reg        busy      // transaction is in process
);
    /*wire [7:0] in;
    reg [7:0] sentence [0:`SENTENCE_LEN-1];
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
    integer i = 1;*/
    
    reg  [2:0] state  = `IDLE;
    reg  [7:0] data   = 8'b0;    // to store a copy of input data
    reg  [2:0] bitIdx = 3'b0;    // for 8-bit data
    wire [2:0] idx;
    
    assign idx = bitIdx;

    always @(posedge clk) begin
        case (state)
            //`RESET      : begin
            //    state   <= `IDLE;
            //end
            `IDLE       : begin
                out     <= 1'b1;        // drive line high for idle
                done    <= 1'b0;
                busy    <= 1'b0;
                bitIdx  <= 3'b0;
                data    <= 8'b0;
                if (start & enable) begin
                    data    <= in;      // save a copy of input data
                    state   <= `START;  // start transmitting
                end
            end
            `START       : begin
                out      <= 1'b0;       // send start bit (low)
                busy     <= 1'b1;
                state    <= `TRANSMITTING;
            end
            `TRANSMITTING: begin        // Wait 8 clock cycles for data bits to be sent
                out     <= data[idx];
                if (&bitIdx) begin
                    bitIdx  <= 3'b0;
                    state   <= `STOP;
                end else begin
                    bitIdx  <= bitIdx + 1'b1;
                end
            end
            `STOP       : begin         // Send out Stop bit (high)
                done    <= 1'b1;
                data    <= 8'b0;
                state   <= `IDLE;
            end
        endcase
    end
    /*
    always @(posedge done) begin
        in = sentence[i];
        i = i + 1;
        if (i > 12) begin
            
        end
    end
    */
endmodule
