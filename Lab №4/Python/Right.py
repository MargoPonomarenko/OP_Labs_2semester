from TTriangle import *


class Right(TTriangle):
    angle1 = 0.0

    def __init__(self, point1, point2, side1):
        super().__init__(point1, point2, side1, 90)
        self.side1 = side1
        self.angle = 90

        self.side2 = round(point1.distance_to(point2), 2)
        self.angle1 = round((math.atan(side1 / self.side2) * 180 / 3.14), 2)

    def calculate_area(self):
        return round((self.side1 * self.side2 / 2), 2)

    def info(self):
        output = ''
        output += 'Данi про прямокутний трикутник:\n'
        i = 1
        for point in self.coordinates_list:
            output += 'x' + str(i) + ' = ' + str(point.x) + '; y' + str(i) + ' = ' + str(point.y) + '\n'
            i += 1
        output += 'side1 = ' + str(self.side1) + '; side2 = ' + str(self.side2) + '\n'
        output += 'angle = ' + str(self.angle) + '; angle1 = ' + str(self.angle1) + '\nПлоща трикутника = '
        output += str(Right.calculate_area(self)) + '\n'
        return output
