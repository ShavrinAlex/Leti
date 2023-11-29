class HouseScheme:
    def __init__(self, count_rooms, living_space, comb_bath):
        if (type(count_rooms) is int) and (living_space >= 1) and (type(comb_bath) is bool):
            self.count_rooms = count_rooms
            self.living_space = living_space
            self.comb_bath = comb_bath
        else:
            raise ValueError('Invalid value')


class CountryHouse(HouseScheme):
    def __init__(self, count_rooms, living_space, comb_bath, count_floors, land_area):
        super().__init__(count_rooms, living_space, comb_bath)
        if (count_floors >= 1) and (type(land_area) is int):
            self.count_floors = count_floors
            self.land_area = land_area
        else:
            raise ValueError('Invalid value')

    def __str__(self):
        inf = f'Country House: Количество жилых комнат {self.count_rooms}, '\
                f'Жилая площадь {self.living_space}, '\
                f'Совмещенный санузел {self.comb_bath}, '\
                f'Количество этажей {self.count_floors}, '\
                f'Площадь участка {self.land_area}.'
        return inf

    def __eq__(self, other):
        if isinstance(other, CountryHouse):
            if (self.living_space == other.living_space) and (self.land_area == other.land_area) and (abs(self.count_floors - other.count_floors) <= 1):
                return True
            else:
                return False


class Apartment(HouseScheme):
    def __init__(self, count_rooms, living_space, comb_bath, floor, window_side):
        super().__init__(count_rooms, living_space, comb_bath)
        if (1 <= floor <= 15) and (window_side in ['N', 'S', 'W', 'E']):
            self.floor = floor
            self.window_side = window_side
        else:
            raise ValueError('Invalid value')

    def __str__(self):
        inf = f'Apartment: Количество жилых комнат {self.count_rooms}, '\
                f'Жилая площадь {self.living_space}, '\
                f'Совмещенный санузел {self.comb_bath}, '\
                f'Этаж {self.floor}, '\
                f'Окна выходят на {self.window_side}.'
        return inf


class CountryHouseList(list):
    def __init__(self, name):
        super().__init__()
        self.name = name
    
    def append(self, p_object):
        if isinstance(p_object, CountryHouse):
            super().append(p_object)
        else:
            raise TypeError(f'Invalid type {type(p_object)}')

    def total_square(self):
        total_living_space = 0
        for house in self:
            total_living_space += house.living_space
        return total_living_space

class ApartmentList(list):
    def __init__(self, name):
        super().__init__()
        self.name = name

    def extend(self, iterable):
        super().extend(filter(lambda i: isinstance(i, Apartment), iterable))

    def floor_view(self, floors, directions):
        suitable_apart = list(filter(lambda apart: (floors[0] <= apart.floor <= floors[1]) and (apart.window_side in directions), self))
        for apart in suitable_apart:
            print(f'{apart.window_side}: {apart.floor}')
