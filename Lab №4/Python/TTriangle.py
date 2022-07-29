import math


def equilateral(triangle):
    area = triangle.calculate_area()
    print(triangle.info())
    return area


def right(triangle):
    area = triangle.calculate_area()
    print(triangle.info())
    return area


def isosceles(triangle):
    perimeter = triangle.calculate_perimeter()
    print(triangle.info())
    return perimeter


# словник для визначення виду трикутника
TriangleType = {
    'Equilateral': equilateral,
    'Right': right,
    'Isosceles': isosceles
}


class Coordinates:

    def __init__(self, x, y):
        self.x = x
        self.y = y

    def distance_to(self, point):
        return math.sqrt((point.x - self.x) ** 2 + (point.y - self.y) ** 2)


class TTriangle:

    def __init__(self, point1, point2, side1, angle):
        self.angle = angle
        self.side1 = side1
        self.coordinates_list = []
        self.coordinates_list.append(point1)
        self.coordinates_list.append(point2)
        self.side3 = point1.distance_to(point2)
        self.side2 = math.sqrt(side1 ** 2 + self.side3 ** 2 - 2 * side1 * self.side3 * math.cos((angle * 3.14) / 180))

        # обчислення координат третьої вершини
        k = (self.side3 ** 2 + self.side2 ** 2 - side1 ** 2) / (2 * self.side3)
        h = math.sqrt(self.side2 ** 2 - k ** 2)
        if angle <= 90:
            x3 = round((point1.x + (k / self.side3) * (point2.x - point1.x) - (h / self.side3) * (point2.y - point1.y)), 2)
            y3 = round((point1.y + (k / self.side3) * (point2.y - point1.y) + (h / self.side3) * (point2.x - point1.x)), 2)
        else:
            x3 = round((point1.x + (k / self.side3) * (point2.x - point1.x) + (h / self.side3) * (point2.y - point1.y)), 2)
            y3 = round((point1.y + (k / self.side3) * (point2.y - point1.y) - (h / self.side3) * (point2.x - point1.x)), 2)
        point3 = Coordinates(x3, y3)
        self.coordinates_list.append(point3)

    def calculate_area(self):
        return 0

    def calculate_perimeter(self):
        return 0

    def info(self):
        return 0

