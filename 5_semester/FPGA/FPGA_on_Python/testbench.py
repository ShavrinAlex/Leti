from random import randrange
from led_blinker import led_blinker
from myhdl import block, Signal, always, delay, intbv

@block
def testbench():
    input, led = [Signal(intbv(0)) for i in range(2)]
    lb = led_blinker(input, led)
    print("input led")
    @always(delay(10))
    def gen():
        input.next = randrange(2)
        print("%s %s" % (input, led))
    return lb, gen


tb = testbench()
tb.config_sim(trace=True)
tb.run_sim(50)
