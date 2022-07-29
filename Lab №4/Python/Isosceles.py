from TTriangle import *


class Isosceles(TTriangle):
    angle1 = 0.0

    def __init__(self, point1, point2, angle):
        super().__init__(point1, point2, point1.distance_to(point2), angle)
        self.angle = angle
        self.angle1 = 180 - (2 * angle)
        self.side2 = round(point1.distance_to(point2), 2)
        self.side3 = self.side2
        self.side1 = 2 * self.side2 * math.cos((angle * 3.14) / 180)
        self.side1 = round(self.side1, 2)

    def calculate_perimeter(self):
        return 2 * self.side2 + self.side1

    def info(self):
        output = ''
        output += 'Данi про рівнобедренний трикутник:\n'
        i = 1
        for point in self.coordinates_list:
            output += 'x' + str(i) + ' = ' + str(point.x) + '; y' + str(i) + ' = ' + str(point.y) + '\n'
            i += 1
        output += 'side1 = ' + str(self.side1) + '; side2 = side3 = ' + str(self.side2) + '\n'
        output += 'angle = ' + str(self.angle) + '; angle1 = ' + str(self.angle1) + '\nПериметр трикутника = '
        output += str(Isosceles.calculate_perimeter(self)) + '\n'
        return output

