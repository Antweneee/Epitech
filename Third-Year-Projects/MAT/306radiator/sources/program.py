#!/usr/bin/env python3

import sys
import math

ROUND = 0.001

class Program:
    def __init__(self, args) -> None:
        self.args = args
        self.usage = "USAGE\n\t./306radiator n ir jr [i j]\n\nDESCRIPTION]\n\tn\t size of the room\n\t(ir, jr)\tcoordinates of the radiator\n\t(i, j)\t coordinates of a point in the room"
        self.n = 0
        self.ir = 0
        self.jr = 0
        self.i = 0
        self.j = 0
        self.matrix = []
        self.vectorX = []
        self.vectorY = []
        self.h = 0.5
        self.hF = 1 / (self.h * self.h)
        self.fxResult = -300
        self.coeff = [1, 1, -4, 1, 1]
        self.result = []
        self.cibledTemp = 0.0

    def clearDatas(self):
        self.args = []
        self.n = 0
        self.ir = 0
        self.jr = 0
        self.i = 0
        self.j = 0
        self.matrix = []
        self.vectorX = []
        self.vectorY = []
        self.h = 0.5
        self.hF = 1 / (self.h * self.h)
        self.fxResult = -300
        self.coeff = [1, 1, -4, 1, 1]
        self.result = []
        self.cibledTemp = 0.0

    def __checkargs(self) -> bool:
        self.nbargs = len(self.args)

        if self.nbargs == 0:
            return False
        if self.nbargs == 3 or self.nbargs == 5:
            for i in range(0, self.nbargs):
                try:
                    int(self.args[i])
                except:
                    return False
            self.n = int(self.args[0])
            if self.n <= 2:
                return False
            if self.nbargs == 3:
                try:
                    self.ir = int(self.args[1])
                    self.jr = int(self.args[2])
                except:
                    return False
                if self.ir > self.n or self.jr > self.n:
                    return False
                if self.ir * self.n + self.jr > self.n ** 2:
                    return False
                if self.ir < 1 or self.ir > self.n - 2 or self.jr < 1 or self.jr > self.n - 2:
                    return False
            if self.nbargs == 5:
                try:
                    self.ir = int(self.args[1])
                    self.jr = int(self.args[2])
                    self.i = int(self.args[3])
                    self.j = int(self.args[4])
                except:
                    return False
                if self.ir > self.n or self.jr > self.n or self.i > self.n or self.j > self.n:
                    return False
                if self.i * self.n + self.j > self.n ** 2:
                    return False
                if self.i < 1 or self.i > self.n - 2 or self.j < 1 or self.j > self.n - 2:
                    return False
        else:
            return False
        return True

    def printMatrix(self) -> None:
        for i in range(len(self.matrix)):
            for j in range(len(self.matrix)):
                if j != len(self.matrix[i]) - 1:
                    print((int(self.matrix[i][j])),"\t", end="", sep="")
                else:
                    print((int(self.matrix[i][j])),)
        print("")

    def printResult(self) -> None:
        for x in self.vectorX:
            print(round(x + ROUND, 1))

    def printCibledTemp(self):
        print(round(self.vectorX[self.i * self.n + self.j] + ROUND, 1))

    def initMatrix(self):
        self.matrix = [[0 if i != j else 1 for j in range(self.n * self.n)] for i in range(self.n * self.n)]
        self.vectorX = [0 for _ in range(self.n * self.n)]
        self.vectorY = [0 for _ in range(self.n * self.n)]

    def startSystem(self, i) -> None:
        if i == self.n - 1:
            return None
        self.matrix[i * self.n][i * self.n] = 1
        self.startSystem(i + 1)

    def assign(self, point, i, j, coeff) -> None:
        point[(i - 1) * self.n + j] = self.coeff[0] * coeff
        point[i * self.n + j - 1]   = self.coeff[1] * coeff
        point[i * self.n + j]       = self.coeff[2] * coeff
        point[i * self.n + j + 1]   = self.coeff[3] * coeff
        point[(i + 1) * self.n + j] = self.coeff[4] * coeff
        return point

    def handleMatrix(self, i, j) -> None:
        if j == self.n - 1:
            return None
        self.matrix[i * self.n + j] = self.assign(self.matrix[i * self.n + j], i, j, self.hF)
        self.handleMatrix(i, j + 1)

    def midSystem(self, i) -> None:
        if i == self.n - 1:
            return None
        self.handleMatrix(i, 1)
        self.midSystem(i + 1)

    def endSystem(self, i) -> None:
        if i == self.n + 1:
            return None
        if i < self.n:
            self.matrix[(i + 1) * self.n - 1][(i + 1) * self.n - 1] = 1
        self.matrix[(self.n * self.n) - i][(self.n * self.n) - i] = 1
        self.endSystem(i + 1)

    def computeVectorX(self):
        for i in range(self.n * self.n):
            inter = 0
            for j in range(self.n * self.n):
                inter += self.matrix[i][j] * self.vectorX[j] if i != j else 0
                self.vectorX[i] = (self.vectorY[i] - inter) / self.matrix[i][i]
        return None

    def manageVectorX(self, it):
        if it == 0:
            self.vectorY[self.ir * self.n + self.jr] = -300
        if it == 100:
            return None
        self.computeVectorX()
        self.manageVectorX(it + 1)

    def operations(self) -> bool:
        self.startSystem(1)
        self.midSystem(1)
        self.endSystem(1)
        self.manageVectorX(0)
        return True

    def engine(self) -> None:
        if len(self.args) != 0 and  self.args[0] == "-h":
            print(self.usage)
            sys.exit(0)
        if self.__checkargs() == False:
            sys.exit(84)
        self.initMatrix()
        tmp = self.operations()
        if tmp == True and self.nbargs == 3:
            self.printMatrix()
            self.printResult()
        elif tmp == True and self.nbargs == 5:
            self.printCibledTemp()
        else:
            sys.exit(84)

def main():
    tmp = sys.argv
    if  tmp[0] == "./306radiator": tmp.pop(0)
    program = Program(sys.argv)
    program.engine()

if '__main__' == __name__:
    main()