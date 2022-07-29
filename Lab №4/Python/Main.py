from Triangles import *


def create_equilateral(triangle_vector, count):
    j = 0
    while j < count:
        print('Створення рiвностороннього трикутника...')
        x1 = int(input('x1 = '))
        y1 = int(input('y1 = '))
        x2 = int(input('x2 = '))
        y2 = int(input('y2 = '))
        c1 = Coordinates(x1, y1)
        c2 = Coordinates(x2, y2)
        new_object = Equilateral(c1, c2)
        triangle_vector.append(new_object)
        j += 1


def create_right(triangle_vector, count):
    j = 0
    while j < count:
        print('Створення прямокутного трикутника...')
        x1 = int(input('x1 = '))
        y1 = int(input('y1 = '))
        x2 = int(input('x2 = '))
        y2 = int(input('y2 = '))
        side = int(input('side = '))
        c1 = Coordinates(x1, y1)
        c2 = Coordinates(x2, y2)
        new_object = Right(c1, c2, side)
        triangle_vector.append(new_object)
        j += 1


def create_isosceles(triangle_vector, count):
    j = 0
    while j < count:
        print('Створення рiвнобедренного трикутника...')
        x1 = int(input('x1 = '))
        y1 = int(input('y1 = '))
        x2 = int(input('x2 = '))
        y2 = int(input('y2 = '))
        angle = int(input('angle = '))
        c1 = Coordinates(x1, y1)
        c2 = Coordinates(x2, y2)
        new_object = Isosceles(c1, c2, angle)
        triangle_vector.append(new_object)
        j += 1


n = int(input('Введіть кількість трикутників: '))
triangls = []

for i in range(0, 3):
    match i:
        case 0:
            create_equilateral(triangls, n // 3)
        case 1:
            create_right(triangls, n // 3)
        case 2:
            create_isosceles(triangls, n // 3 + n % 3)

area_syma = 0.0
perimeter_syma = 0.0

# підрахунок суми площ та периметрів
for triangl in triangls:
    result = TriangleType[type(triangl).__name__](triangl)
    match type(triangl).__name__:
        case 'Equilateral':
            area_syma += result
        case 'Right':
            area_syma += result
        case 'Isosceles':
            perimeter_syma += result

area_syma = round(area_syma, 2)
perimeter_syma = round(perimeter_syma, 2)
print('Сума площ =', area_syma)
print('Сума периметрів =', perimeter_syma)


