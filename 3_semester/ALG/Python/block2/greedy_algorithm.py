#python

def prog(stations, required_areas, result):
    while required_areas:
        best_station = None
        best_area_covered = set()
        for current_station, current_area_covered in stations.items():
            new_area_covered = required_areas & current_area_covered
            if len(best_area_covered) < len(new_area_covered):
                best_station = current_station
                best_area_covered = new_area_covered
        required_areas -= best_area_covered
        result.add(best_station)

if __name__ == "__main__":
    # get data
    areas = set(input().split(','))
    N = int(input())
    stations = {}
    for _ in range(N):
        data = input()
        key = int(data.split(':')[0])
        value = set((data.split(':')[1]).split(','))
        stations[key] = value
    
    # calculating
    result = set()
    prog(stations, areas, result)
    result = list(result)
    result.sort()

    # answer
    print(*result, sep=',')
