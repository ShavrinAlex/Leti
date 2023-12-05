import matplotlib.pyplot as plt
import numpy as np


def read_file(file_name: str) -> list:
    """This function returns the array of numbers reading from file"""

    with open(file_name, 'r') as file:
       return list(map(float, file.readlines()))

def draw_signal(time: list, signal: list) -> None:
    """This function draw signal"""

    plt.title("s_вход(t)")
    plt.xlabel("t, c")
    plt.ylabel("s_вход")
    plt.plot(time, signal)
    plt.show()

def draw_amplitude(frequency: list, spectrum_module: list, stop_i: int) -> None:
    """This function draw amplitude"""

    plt.title("A_вход(ω)")
    plt.xlabel("ω, рад/c")
    plt.ylabel("A_вход")
    plt.plot(frequency[:stop_i], spectrum_module[:stop_i])
    plt.show()

def draw_afr(frequency: list, H: list, stop_i: int) -> None:
    """This function draw afr"""

    plt.title("|H(iω)|")
    plt.xlabel("ω, рад/c")
    plt.ylabel("|H|")
    plt.plot(frequency[1:stop_i], H[:stop_i-1])
    plt.show()

def calculate_stop_i(N: int, delta_f: float) -> tuple:
    """This function calculated frequency and stop i"""

    frequency = []
    stop_i = 0
    for i in range(N):
        if (2 * np.pi * delta_f * i > 100) and (stop_i == 0):
            stop_i = i + 1
        frequency.append(2 * np.pi * delta_f * i)
    return (frequency, stop_i)

def calculate_h(L1: float, L2: float, C1: float, C2: float, R1: float, R2: float, R3: float, R4: float, j: complex, omega):
    """This function calculated h"""

    Z_C1 = 1 / (j * omega * C1)
    Z_C2 = 1 / (j * omega * C2)
    Z_L1 = j * omega * L1
    Z_L2 = j * omega * L2
    r_output = R4 * (Z_C1 + R2 + Z_L2 + R3) / (Z_C1 + R2 + Z_L2 + R3 + R4 + Z_C2)
    r_parallel = ((R4 + Z_C2) * (Z_C1 + R2 + Z_L2 + R3)) / (R4 + Z_C2 + Z_C1 + R2 + Z_L2 + R3)
    r_input = R1 + Z_L1 + r_parallel
    return r_output / r_input




def main():
    '''This is main function'''
    # Вариант 19

    L1 = 13.8270732887564
    L2 = 0.657474811319873 	
    C1 = 1.13651394408746E-05
    C2 = 1.1966097884484E-05
    R1 = 117.127114792662
    R2 = 36.4097530756215
    R3 = 1043.22165993119
    R4 = 539.354514679385
    DELTA_T = 0.0196349540849362
    N = 8192
    FILE_NAME = "19.txt"

    j = complex(0, 1)
    delta_f = 1 / (DELTA_T * N)
    signal = read_file(FILE_NAME)

    spectrum_module = list(map(abs, np.fft.fft(signal)))
    frequency, stop_i = calculate_stop_i(N, delta_f)

    H = [abs(calculate_h(L1, L2, C1, C2, R1, R2, R3, R4, j, omega)) for omega in frequency[1:]]
    # w2 = 20 
    H_ans = abs(calculate_h(L1, L2, C1, C2, R1, R2, R3, R4, j, 20))

    time = [DELTA_T * i for i in range(N)]
    draw_signal(time, signal)
    draw_amplitude(frequency, spectrum_module, stop_i)
    draw_afr(frequency, H, stop_i)

    print(H_ans)



if __name__ == "__main__":
    main()
