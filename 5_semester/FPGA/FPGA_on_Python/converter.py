from myhdl import Signal, intbv
from led_blinker import led_blinker

def convert():
    input, led = [Signal(bool(0)) for i in range(2)]
    lb = led_blinker(input, led)
    lb.convert(hdl="Verilog")
convert()

