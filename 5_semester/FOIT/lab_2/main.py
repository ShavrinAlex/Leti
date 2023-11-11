from matplotlib import pyplot as plt
from matplotlib import cm
import numpy as np
import copy
from math import sqrt


DIMENSION_SIZE = 1250
DELTA = 0.05

X = np.linspace(-6, 6, DIMENSION_SIZE)
Y = np.linspace(-6, 6, DIMENSION_SIZE)

# Variant 19

POTENTIAL_1 = 6
POTENTIAL_2 = 5
SERCHING_POTENTIAL = 4

def external_electrode(x, y):
    return x**2 + y**2 - 25

def first_inner_edlectrode(x, y):
    return abs(-1.8 + x)**2 + 0.3*abs(1.8 + y)**2 - 0.6

def second_inner_edlectrode(x, y):
    return abs(1.8 + x)**1.5 + 0.5*abs(-1.8 + y)**1.5 - 0.8


def fill_potential_grid(potential_grid, potential_grid_electrode):
    for y in range(1, DIMENSION_SIZE-1):
        for x in range(1, DIMENSION_SIZE-1):
            external = external_electrode(X[x], Y[y])
            first_inner = first_inner_edlectrode(X[x], Y[y])
            second_inner = second_inner_edlectrode(X[x], Y[y])

            if (abs(external) < DELTA):
                potential_grid[y][x] = 0
                potential_grid_electrode[y][x] = True 
                   
            elif (abs(first_inner) < DELTA):
                potential_grid[y][x] = POTENTIAL_1
                potential_grid_electrode[y][x] = True
                  
            elif (abs(second_inner) < DELTA):
                potential_grid[y][x] = POTENTIAL_2
                potential_grid_electrode[y][x] = True
                  
def draw_electrodes(mesh):
    x = []
    y = []
    for i in range(len(mesh)):
        for j in range(len(mesh[i])):
            if mesh[i][j]:
                x.append(j)
                y.append(i)

    fig, ax = plt.subplots()
    ax.scatter(x, y, color='green')

def draw_potential_grid(solve):
    fig, ax = plt.subplots(subplot_kw={"projection": "3d"})
    x_values, y_values = np.meshgrid(X, Y)
    x_values = np.array(x_values, dtype=float)
    y_values = np.array(y_values, dtype=float)
    ax.plot_surface(x_values, y_values, np.array(solve, dtype=float), cmap=cm.coolwarm,
                    linewidth=0, antialiased=False)

def draw_potentiales(equipotential_1, equipotential_2):
    fig, ax = plt.subplots()
    ax.plot(equipotential_1[0], equipotential_1[1], linestyle="none", marker="o")
    ax.plot(equipotential_2[0], equipotential_2[1], linestyle="none", marker="o")

def draw_electrodes_and_equipotentiales(equipotential_1, equipotential_2, electrodes):
    fig2, ax2 = plt.subplots()
    x = []
    y = []
    for i in range(len(electrodes)):
        for j in range(len(electrodes[i])):
            if electrodes[i][j]:
                x.append(X[j])
                y.append(Y[i])
    ax2.plot(x, y, linestyle="none", marker="o")
    ax2.plot(equipotential_1[0], equipotential_1[1], linestyle="none", marker="o")
    ax2.plot(equipotential_2[0], equipotential_2[1], linestyle="none", marker="o")

def get_equipotential(potential_grid):
    equipotential = [[], []]
    for y in range(1, DIMENSION_SIZE -1):
        for x in range(1, DIMENSION_SIZE-1):
            if abs(potential_grid[y][x] - SERCHING_POTENTIAL) < DELTA:
                equipotential[0].append(X[x])
                equipotential[1].append(Y[y])
    return equipotential

def separate_equipotential(equipotential):
    first_equipotential = [[], []]
    second_equipotential =[[], []]
    for i in range(len(equipotential[0])):
        if equipotential[0][i] < equipotential[1][i]:
            first_equipotential[0].append(equipotential[0][i])
            first_equipotential[1].append(equipotential[1][i])
        else:
            second_equipotential[0].append(equipotential[0][i])
            second_equipotential[1].append(equipotential[1][i])
    return first_equipotential, second_equipotential

def clear_equipotential(equipotential, equip_func):
    clear_equipotential = [[], []]
    for i in range(len(equipotential[0])):
        if equip_func(equipotential[0][i], equipotential[1][i]) < 0:
            continue
        clear_equipotential[0].append(equipotential[0][i])
        clear_equipotential[1].append(equipotential[1][i])
    return clear_equipotential

def tsp_greedy(points):
    def calculate_distance(point_1, point_2):
        return sqrt((point_1[0] - point_2[0])**2 + (point_1[1] - point_2[1])**2)

    x_values, y_values = points
    x_values_arranged = [x_values.pop()]
    y_values_arranged = [y_values.pop()]

    for _ in range(len(x_values)):
        current_item = (x_values_arranged[-1], y_values_arranged[-1])
        nearest_item_index = 0

        for i in range(len(x_values)):
            x_nearest_item = x_values[nearest_item_index]
            y_nearest_item = y_values[nearest_item_index]

            if calculate_distance(current_item, (x_values[i], y_values[i])) < \
                    calculate_distance(current_item, (x_nearest_item, y_nearest_item)):
                nearest_item_index = i

        x_values_arranged.append(x_values.pop(nearest_item_index))
        y_values_arranged.append(y_values.pop(nearest_item_index))

    return x_values_arranged, y_values_arranged

def calculate_cycle_distance(cycle):
    x_values, y_values = cycle
    distance = 0
    for i in range(len(x_values)):
        distance += sqrt((y_values[i] - y_values[i - 1])**2 + ((x_values[i] - x_values[i - 1])**2))
    return distance

def solve(potential_grid, potential_grid_electrode, precision):
    max_difference = 1
    counter = 0
    while max_difference > precision:
        counter += 1
        max_difference = 0
        mesh_copy = copy.deepcopy(potential_grid)
        for i in range(1, DIMENSION_SIZE - 1):
            for j in range(1, DIMENSION_SIZE - 1):
                if potential_grid_electrode[i][j]:
                    continue

                mesh_copy[i][j] = (potential_grid[i][j - 1] + potential_grid[i][j + 1] +
                                    potential_grid[i - 1][j] + potential_grid[i + 1][j]) / 4
                max_difference = max(max_difference, abs(mesh_copy[i][j] - potential_grid[i][j]))

        potential_grid = mesh_copy
    draw_potential_grid(potential_grid)
    print("Laplas iteraations: ", counter)
    print("potential grid done")
    
    equipotential = get_equipotential(potential_grid)
    print("equipotential done")
    eq_2, eq_1 = separate_equipotential(equipotential)
    print("separate equipotential done")

    eq_2 = clear_equipotential(eq_2, second_inner_edlectrode)
    eq_1 = clear_equipotential(eq_1, first_inner_edlectrode)
    print("clear equipotential done")

    draw_potentiales(eq_1, eq_2)
    draw_electrodes_and_equipotentiales(eq_1, eq_2, potential_grid_electrode)

    cycle_1 = tsp_greedy(eq_1)
    cycle_2 = tsp_greedy(eq_2)
    print("equipotentials cycles done")
    dist = calculate_cycle_distance(cycle_1)
    print(dist)
    dist += calculate_cycle_distance(cycle_2)
    print(dist)




def main():
    potential_grid = np.zeros((DIMENSION_SIZE, DIMENSION_SIZE))
    potential_grid_electrode = [[False] * DIMENSION_SIZE for _ in range(DIMENSION_SIZE)]

    fill_potential_grid(potential_grid, potential_grid_electrode)
    draw_electrodes(potential_grid_electrode)

    solve(potential_grid, potential_grid_electrode, 0.01)
    
    plt.show()


if __name__ == "__main__":
    main()