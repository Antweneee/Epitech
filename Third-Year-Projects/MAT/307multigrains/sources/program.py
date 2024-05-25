#!/usr/bin/env python3

import sys
import math
from typing import Tuple, List

NUMBER_OF_ARGUMENTS     =   (9)
NUMBER_OF_FERTILIZERS   =   (4)
NUMBER_OF_PRICES        =   (5)
INDEX_Y                 =   (0)
INDEX_X                 =   (1)

class Program:
    def __init__(self, args) -> None:
        self.args = args
        self.usage = "USAGE\n\t./307multigrains n1 n2 n3 n4 po pw pc pb ps\n\nDESCRIPTION\n\tn1\tnumber of tons of fertilizer F1\n\tn2\tnumber of tons of fertilizer F2\n\tn3\tnumber of tons of fertilizer F3\n\tn4\tnumber of tons of fertilizer F4\n\tpo\tprice of one unit of oat\n\tpw\tprice of one unit of wheat\n\tpc\tprice of one unit of corn\n\tpb\tprice of one unit of barley\n\tps\tprice of one unit of soy"
        self.n1 = 0
        self.n2 = 0
        self.n3 = 0
        self.n4 = 0
        self.po = 0
        self.pw = 0
        self.pc = 0
        self.pb = 0
        self.ps = 0
        self.oat_unit = 0
        self.wheat_unit = 0
        self.corn_unit = 0
        self.barley_unit = 0
        self.soy_unit = 0
        self.oat_unit_price = 0
        self.wheat_unit_price = 0
        self.corn_unit_price = 0
        self.barley_unit_price = 0
        self.soy_unit_price = 0
        self.total_production = 0
        self.n_fertilizers = [0, 0, 0, 0]
        self.prices = [0, 0, 0, 0, 0]

    def print_args(self):
        print("n1:", self.n1)
        print("n2:", self.n2)
        print("n3:", self.n3)
        print("n4:", self.n4)
        print("po:", self.po)
        print("pw:", self.pw)
        print("pc:", self.pc)
        print("pb:", self.pb)
        print("ps:", self.ps)

    def clear_datas(self):
        self.args = []
        self.n1 = 0
        self.n2 = 0
        self.n3 = 0
        self.n4 = 0
        self.po = 0
        self.pw = 0
        self.pc = 0
        self.pb = 0
        self.ps = 0

    def check_args(self):
        if len(self.args) != NUMBER_OF_ARGUMENTS:
            sys.exit(84)
        try:
            self.n1 = int(self.args[0])
            if self.n1 < 0:
                sys.exit(84)
            self.n2 = int(self.args[1])
            if self.n2 < 0:
                sys.exit(84)
            self.n3 = int(self.args[2])
            if self.n3 < 0:
                sys.exit(84)
            self.n4 = int(self.args[3])
            if self.n4 < 0:
                sys.exit(84)
            self.po = int(self.args[4])
            if self.po < 0:
                sys.exit(84)
            self.pw = int(self.args[5])
            if self.pw < 0:
                sys.exit(84)
            self.pc = int(self.args[6])
            if self.pc < 0:
                sys.exit(84)
            self.pb = int(self.args[7])
            if self.pb < 0:
                sys.exit(84)
            self.ps = int(self.args[8])
            if self.ps < 0:
                sys.exit(84)
            self.n_fertilizers  = [self.n1, self.n2, self.n3, self.n4]
            self.prices         = [self.po, self.pw, self.pc, self.pb, self.ps]
        except:
            sys.exit(84)

    def print_result(self):
        print("Resources:", self.n1, "F1,", self.n2, "F2,", self.n3, "F3,", self.n4, "F4", end="\n\n")
        print("Oat: ", "%0.2f" % self.oat_unit if self.oat_unit != 0 else self.oat_unit , " units at $", self.po, "/unit", sep="")
        print("Wheat: ", "%0.2f" % self.wheat_unit if self.wheat_unit != 0 else self.wheat_unit, " units at $", self.pw, "/unit", sep="")
        print("Corn: ", "%0.2f" % self.corn_unit if self.corn_unit != 0 else self.corn_unit, " units at $", self.pc, "/unit", sep="")
        print("Barley: ", "%0.2f" % self.barley_unit if self.barley_unit != 0 else self.barley_unit, " units at $", self.pb, "/unit", sep="")
        print("Soy: ", "%0.2f" % self.soy_unit if self.soy_unit != 0 else self.soy_unit, " units at $", self.ps, "/unit", sep="", end="\n\n")
        print("Total production value: $", "%0.2f" % self.total_production if self.total_production != 0 else self.total_production, sep="")

    def compute(self):
        matrix = init_matrix(self.n_fertilizers, self.prices)
        res, matrix = simplex_algorithm(matrix)

        result = [0 for _ in range(NUMBER_OF_PRICES)]

        for i in range(NUMBER_OF_FERTILIZERS):
            if res[i] != -1:
                result[res[i]] = matrix[i][len(matrix[i]) - 1]

        self.oat_unit = result[0]
        self.wheat_unit = result[1]
        self.corn_unit = result[2]
        self.barley_unit = result[3]
        self.soy_unit = result[4]

        self.total_production = \
            self.oat_unit * self.po + \
            self.wheat_unit * self.pw + \
            self.corn_unit * self.pc + \
            self.barley_unit * self.pb + \
            self.soy_unit * self.ps

        return None

    def engine(self) -> None:
        if len(self.args) != 0 and self.args[0] == "-h":
            print(self.usage)
            sys.exit(0)
        self.check_args()
        self.compute()
        self.print_result()

def get_pivot_x_and_y(matrix):

    if len(matrix) <= 0 or len(matrix[0]) <= NUMBER_OF_PRICES:
        return None, None

    lprices = matrix[len(matrix) - 1][:NUMBER_OF_PRICES]
    if min(lprices) >= 0:
        return None, None

    x = lprices.index(min(lprices))
    y = -1

    m = math.inf

    for i in range(len(matrix) - 1):
        if matrix[i][x] > 0:
            ratio = matrix[i][len(matrix[0]) - 1] / matrix[i][x]
            if ratio < m:
                m = ratio
                y = i

    return y, x

def fill_matrix(n_fertilizers, matrix, it):
    if it == NUMBER_OF_FERTILIZERS:
        return matrix
    matrix[it] += [0] * NUMBER_OF_FERTILIZERS
    matrix[it][it + NUMBER_OF_PRICES] = 1
    matrix[it][NUMBER_OF_FERTILIZERS * 2] = n_fertilizers[it]
    return fill_matrix(n_fertilizers, matrix, it + 1)

def init_matrix(n_fertilizers, prices):

    matrix = [
        [1, 0, 1, 0, 2],
        [1, 2, 0, 1, 0],
        [2, 1, 0, 1, 0],
        [0, 0, 3, 1, 2],
        [-x for x in prices] + [0] * NUMBER_OF_PRICES
    ]

    return fill_matrix(n_fertilizers, matrix, 0)

def gauss_pivot(matrix, y, x):
    pivot = matrix[y][x]
    matrix[y] = [elem / pivot for elem in matrix[y]]
    for i in range(len(matrix)):
        if i == y:
            continue
        matrix[i] = [matrix[i][n] - matrix[i][x] * matrix[y][n] for n in range(len(matrix[0]))]
    return matrix

def manage_gauss_pivot(matrix, products, it):
    if it == NUMBER_OF_PRICES + 1:
        return products, matrix
    lpivot = get_pivot_x_and_y(matrix)
    if lpivot[INDEX_Y] == None or lpivot[INDEX_X] == None:
        return products, matrix
    matrix = gauss_pivot(matrix, lpivot[INDEX_Y], lpivot[INDEX_X])
    products[lpivot[INDEX_Y]] = lpivot[INDEX_X]
    return manage_gauss_pivot(matrix, products, it + 1)

def simplex_algorithm(matrix):
    products = [-1 for _ in range(NUMBER_OF_FERTILIZERS)]
    products, matrix = manage_gauss_pivot(matrix, products, 0)
    return products, matrix

def main():
    tmp = sys.argv
    if  tmp[0] == "./307multigrains": tmp.pop(0)
    program = Program(sys.argv)
    program.engine()

if '__main__' == __name__:
    main()