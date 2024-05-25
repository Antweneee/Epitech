#!/usr/bin/env python3

import os
import sys
import csv
import math

class Program:
    def __init__(self, args) -> None:
        self.args = args
        self.usage = "USAGE\n./309pollution n file x y\nDESCRIPTION\n\tn number of points on the grid axis\n\tfile csv file containing the data points x;y;p\n\tx abscissa of the point whose pollution level we want to know\n\ty ordinate of the point whose pollution level we want to know"
        self.n = 0
        self.filename = ""
        self.x = 0.0
        self.y = 0.0
        self.points = []
        self.matrix = []
        self.pollution_level = 0

    def init_args(self) -> None:
        self.matrix = [[0] * self.n for _ in range(self.n)]

        for _, elem in enumerate(self.points):
            self.matrix[elem[0]][elem[1]] = elem[2]

        return None

    def check_args(self) -> None:
        if len(self.args) != 4:
            sys.exit(84)

        try:
            self.n = int(self.args[0])
            if self.n < 0:
                sys.exit(84)
        except:
            sys.exit(84)

        try:
            self.filename = self.args[1]
        except:
            sys.exit(84)


        try: 
            if os.path.getsize(self.filename) <= 0:
                sys.exit(84)
        except:
            sys.exit(84)


        try:
            with open(self.filename, 'r') as file:
                reader = csv.reader(file, delimiter=';')
                for row in reader:
                    if len(row) != 3:
                        sys.exit(84)
                    x, y, p = map(int, row)
                    if x < 0 or y < 0 or p < 0:
                        sys.exit(84)
                    self.points.append([x, y, p])
        except:
            sys.exit(84)

        for array in self.points:
            for i in range(len(array) - 1):
                try:
                    elem = int(array[i])
                    if elem < 0 or elem >= self.n:
                        sys.exit(84)
                except:
                    sys.exit(84)
            try:
                last = int(array[-1])
                if last < 0:
                    sys.exit(84)
            except:
                sys.exit(84)

        try:
            self.x = float(self.args[2])
            if self.x < 0:
                sys.exit(84)
        except:
            sys.exit(84)

        try:
            self.y = float(self.args[3])
            if self.y < 0:
                sys.exit(84)
        except:
            sys.exit(84)
        return None

    def compute(self) -> None:
        self.pollution_level = sum([getBezierSurface(self.n - 1, self.x, self.y, i, j) * self.matrix[i][j] for i in range(self.n) for j in range(self.n)])
        return None

    def prints(self) -> None:
        print("{:.2f}".format(self.pollution_level))
        return None

    def engine(self) -> None:
        if len(self.args) != 0 and self.args[0] == "-h":
            print(self.usage)
            sys.exit(0)
        self.check_args()
        self.init_args()
        self.compute()
        self.prints()

def getCombinations(n, k):
    return math.factorial(n) / (math.factorial(k) * math.factorial(n - k))

def getBezierFormula(n, p, k):
    return pow(p / n, k) * pow(1 - (p / n), n - k)

def getBezierSurface(n, x, y, i, j):
    return getCombinations(n, i) * getCombinations(n, j) * getBezierFormula(n, x, i) * getBezierFormula(n, y, j)

def main():
    tmp = sys.argv
    if  tmp[0] == "./309pollution": tmp.pop(0)
    program = Program(sys.argv)
    program.engine()

if '__main__' == __name__:
    main()
