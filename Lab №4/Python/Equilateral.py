from TTriangle import *


class Equilateral(TTriangle):

    def __init__(self, point1, point2):
        super().__init__(point1, point2, point1.distance_to(point2), 60)
        self.side3 = round(point1.distance_to(point2), 2)
        self.side1 = self.side2 = self.side3
        self.angle = 60

    def calculate_area(self):
        return round((self.side3 ** 2 * math.sqrt(3) / 4), 2)

    def info(self):
        output = ''
        output += '\nДанi про рiвностороннiй трикутник:\n'
        i = 1
        for point in self.coordinates_list:
            output += 'x' + str(i) + ' = ' + str(point.x) + '; y' + str(i) + ' = ' + str(point.y) + '\n'
            i += 1
        output += 'side1 = side2 = side3 = ' + str(self.side3) + '\nangle = ' + str(self.angle) + '\nПлоща трикутника = '
        output += str(Equilateral.calculate_area(self)) + '\n'
        return output

