import matplotlib.pyplot as plt
import numpy as np
import wave
import struct


def draw_signal(time: list, signal: list) -> None:
    """This function draw signal"""

    plt.title("s_вход(t)")
    plt.xlabel("t, c")
    plt.ylabel("s_вход")
    plt.plot(time, signal)
    plt.show()


def draw_amplitude(frequency: list, spectrum_module: list) -> None:
    """This function draw amplitude"""

    plt.title("A_вход(ω)")
    plt.xlabel("ω, рад/c")
    plt.ylabel("A_вход")
    plt.plot(frequency, spectrum_module)
    plt.show()


def draw_afr(frequency: list, H_module: list) -> None:
    """This function draw afr"""

    plt.title("|H(iω)|")
    plt.xlabel("ω, рад/c")
    plt.ylabel("|H|")
    plt.plot(frequency, H_module)
    plt.show()


def read_file(file_name: str) -> list:
    """This function returns the array of numbers reading from file"""

    with open(file_name, 'r') as file:
       return [int(''.join(filter(str.isalnum, line)), base=2) for line in file.readlines()]


def normalize_signal(signal: list) -> list:
    """This function normalizes the signal"""

    minimum = min(signal)
    maximum = max(signal)
    average = (maximum - minimum) / 2 + minimum
    amplitude = (maximum - minimum) / 2

    return [((x - average) / amplitude) for x in signal]


def gain_signal(signal: list, gain_rate: int) -> list:
    """This function enhances the signal"""

    return [x * gain_rate for x in signal]

def create_wav(signal: list, filename: str) -> None:
    """This function create the wav audio file"""

    with wave.open(filename, mode="wb") as audio:
        audio.setnchannels(1)
        audio.setsampwidth(2)
        audio.setframerate(44100)
        normalized_signal = normalize_signal(signal)
        gained_signal = gain_signal(normalized_signal, 2 ** 15 - 1)
        for value in gained_signal:
            audio.writeframes(struct.pack('h', int(value)))


def calculate_h(j, w):
    """This function calculated h"""

    C = 1e-9
    R0 = 125
    Z_C = 1 / (j * w * C)
    R = [Z_C]
    r_input = 1
    n = 255

    for i in range(1, n):
        R.append((Z_C * (R0 + R[i - 1])) / (Z_C + R0 + R[i - 1]))

    for i in range(n):
        a = 1 + ((R0 + R[i]) / Z_C)
        r_input *= a

    r_input *= (R0 + (Z_C * (R0 + R[-1])) / (Z_C + R0 + R[-1]))
    r_output = Z_C

    return r_output / r_input


def main():
    """This is main function"""

    # Вариант 19
    DURATION = 3.25
    FILE_NAME = "signaldigit19.txt"

    j = complex(0, 1)
    input_signal = read_file(FILE_NAME)
    N = len(input_signal)
    dt = DURATION / N
    df = 1 / DURATION

    input_spectrum = np.fft.fft(input_signal)
    frequency = [df * i for i in range(N)]
    H = [calculate_h(j, w) for w in frequency[1:]]

    output_spectrum = [input_spectrum[i] * H[i-1] for i in range(1, N)]
    output_signal = [number.real for number in np.fft.ifft(output_spectrum)]

    time = [dt * i for i in range(N)]
    draw_signal(time=time, signal=input_signal)
    draw_signal(time=time[1:], signal=output_signal)
    draw_amplitude(frequency=frequency, spectrum_module=list(map(abs, input_spectrum)))
    draw_amplitude(frequency=frequency[1:], spectrum_module=list(map(abs, output_spectrum)))
    draw_afr(frequency=frequency[1:], H_module=list(map(abs, H)))

    create_wav(signal=input_signal, filename="input_audiosignal19.wav")
    create_wav(signal=output_signal, filename="output_audiosignal19.wav")


if __name__ == "__main__":
    main()
    #43+4
