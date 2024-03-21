from math import cos, sin, pi, radians, asin, tan, sqrt
import matplotlib.pyplot as plt


def F1(y: float) -> float:
    return 1.4 + 0.3 * cos(0.8 * (y**4))

def Zf(y: float) -> float:
    return 12 + 3 * sin(17.951958020513104 * y)

def N1(y: float, w: float) -> float:
    return F1(y) * (1 - ((0.35 * 10**14) / w)**2)

def NewSin(n_1: float, n_2: float, sin_1: float) -> float:
    return (n_1 / n_2) * sin_1

def Dz(d: float, angle: float) -> float:
    return abs(d) * tan(abs(angle))

def get_end(R: float) -> (list, list):
    wave_x = []
    wave_y = []
    x = -R
    while x < R:
        x += 0.001
        wave_x.append(Zf(x))
        wave_y.append(x)
    return (wave_x, wave_y)

def make_chart(ray_z: list, ray_y: list, end_x: list, end_y: list, R: float) -> None:
    plt.xlabel("Z")
    plt.ylabel("Y")
    plt.title("Траектория волны")
    plt.ylim(-R, R)
    plt.plot(ray_z, ray_y)
    plt.plot(end_x, end_y)
    plt.show()

def solve(R: float, count_layers: int, y_0: float, alpha_0: float, n_1: float, w: float) -> (list, list, float):
    dy = (R * 2) / count_layers
    z = 0
    y = y_0
    ray_z = [z]
    ray_y = [y]
    alpha_1 = alpha_0
    n1 = n_1
    n2 = N1(y, w)
    alpha_2 = pi/2 - asin(NewSin(n1, n2, abs(sin(alpha_1))))
    ray_length = 0
    is_reflection = False
    if alpha_1 < 0:
        dy *= -1
    while abs(Zf(y) - z) >= 0.05:
        if is_reflection or abs(abs(y) - R) < 0.0005:
            alpha_2 = alpha_1
            dy *= - 1
        dz = Dz(dy, alpha_2)
        z += dz
        y += dy
        ray_length += sqrt(dz**2 + dy**2)
        ray_z.append(z)
        ray_y.append(y)
        n1 = n2
        alpha_1 = alpha_2
        n2 = N1(y, w)
        if NewSin(n1, n2, sin(alpha_1)) >= 1:
            is_reflection = True
            continue
        alpha_2 = asin(NewSin(n1, n2, sin(alpha_1)))
        is_reflection = False
    return (ray_z, ray_y, ray_length)


def main() -> None:
    # Вариант 19
    R = 1.8
    N_2 = 1
    W = 3.4 * (10**14)
    Y_0 = 0.5
    ALPHA_0 = radians(42)
    COUNT_LAYERS = 10000

    end_z, end_y = get_end(R)
    ray_z, ray_y, ray_length = solve(R, COUNT_LAYERS, Y_0, ALPHA_0, N_2, W)
    print(ray_length)
    make_chart(ray_z, ray_y, end_z, end_y, R)


if __name__ == "__main__":
    main()
