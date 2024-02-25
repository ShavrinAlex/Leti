from myhdl import block, always_comb

@block
def led_blinker(input, led):
    @always_comb
    def on_off_led():
        if input == 1:
            led.next = 1
        else:
            led.next = 0
    return on_off_led
