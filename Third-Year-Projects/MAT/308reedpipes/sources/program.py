#!/usr/bin/env python3

import sys

class Program:
    def __init__(self, args) -> None:
        self.args = args
        self.usage = "USAGE\n./308reedpipes r0 r5 r10 r15 r20 n\nDESCRIPTION\n\tr0\tradius (in cm) of pipe at the 0cm abscissa\n\tr5\tradius (in cm) of pipe at the 5cm abscissa\n\tr10\tradius (in cm) of pipe at the 10cm abscissa\n\tr15\tradius (in cm) of pipe at the 15cm abscissa\n\tr20\tradius (in cm) of pipe at the 20cm abscissa\n\tn\tnumber of points needed to display the radius"
        self.r0 = 0
        self.r5 = 0
        self.r10 = 0
        self.r15 = 0
        self.r20 = 0
        self.n_interpolation_points = 0
        self.abscissas = [0, 5, 10, 15, 20]
        self.new_abscissas = []
        self.vect_result = [0] * len(self.abscissas)
        self.abscissa_results = []
        self.radius_results = []
    
    def init_args(self) -> None:
        self.r0 = float(self.args[0])
        self.r5 = float(self.args[1])
        self.r10 = float(self.args[2])
        self.r15 = float(self.args[3])
        self.r20 = float(self.args[4])
        self.n_interpolation_points = int(self.args[5])
        self.new_abscissas = [self.r0, self.r5, self.r10, self.r15, self.r20]
        self.abscissa_results = [0] * self.n_interpolation_points
        self.radius_results = [0] * self.n_interpolation_points

    def check_args(self) -> None:
        if len(self.args) != 6:
            sys.exit(84)  
        for i in range(len(self.args)):
            try:
                tmp = float(self.args[i])
                if tmp <= 0:
                   sys.exit(84)  
            except:
                sys.exit(84) 
        self.init_args();

    def compute(self) -> None:

        n = len(self.abscissas)
        x_diff = [self.abscissas[i] - self.abscissas[i - 1] for i in range(1, n)]
        y_diff = [3 * (self.new_abscissas[i + 1] - self.new_abscissas[i]) / x_diff[i] - 3 * (self.new_abscissas[i] - self.new_abscissas[i - 1]) / x_diff[i - 1] for i in range(1, n - 1)]
        lower_diagonal, upper_diagonal, intermediate, coefs = [0] * n, [0] * n, [0] * n, [0] * n
        linear_coef, cubic_coef = [0] * (n - 1), [0] * (n - 1)
        lower_diagonal[0], upper_diagonal[0], intermediate[0] = 1, 0, 0

        for i in range(1, n - 1):
            lower_diagonal[i] = 2 * (self.abscissas[i + 1] - self.abscissas[i - 1]) - x_diff[i - 1] * upper_diagonal[i - 1]
            upper_diagonal[i] = x_diff[i] / lower_diagonal[i]
            intermediate[i] = (y_diff[i - 1] - x_diff[i - 1] * intermediate[i - 1]) / lower_diagonal[i]

        lower_diagonal[n - 1], intermediate[n - 1], coefs[n - 1] = 1, 0, 0

        for i in range(n - 2, -1, -1):
            coefs[i] = intermediate[i] - upper_diagonal[i] * coefs[i + 1]
            linear_coef[i] = (self.new_abscissas[i + 1] - self.new_abscissas[i]) / x_diff[i] - x_diff[i] * (coefs[i + 1] + 2 * coefs[i]) / 3
            cubic_coef[i] = (coefs[i + 1] - coefs[i]) / (3 * x_diff[i])

        for i in range(self.n_interpolation_points):
            self.abscissa_results[i] = self.abscissas[0] + (self.abscissas[n - 1] - self.abscissas[0]) * i / (self.n_interpolation_points - 1)
            idx = 0
            for j in range(n - 1):
                if self.abscissas[j] <= self.abscissa_results[i] <= self.abscissas[j + 1]:
                    idx = j
                    break
            self.radius_results[i] = self.new_abscissas[idx] + linear_coef[idx] * (self.abscissa_results[i] - self.abscissas[idx]) + coefs[idx] * (self.abscissa_results[i] - self.abscissas[idx]) ** 2 + cubic_coef[idx] * (self.abscissa_results[i] - self.abscissas[idx]) ** 3

        self.vect_result[2] = ((6 * (self.new_abscissas[3] - 2 * self.new_abscissas[2] + self.new_abscissas[1]) / 50) - ((6 * (self.new_abscissas[2] - 2 * self.new_abscissas[1] + self.new_abscissas[0]) / 50) + (6 * (self.new_abscissas[4] - 2 * self.new_abscissas[3] + self.new_abscissas[2]) / 50)) / 4) * 4 / 7
        self.vect_result[1] = (6 * (self.new_abscissas[2] - 2 * self.new_abscissas[1] + self.new_abscissas[0]) / 50) / 2 - 0.25 * self.vect_result[2]
        self.vect_result[3] = (6 * (self.new_abscissas[4] - 2 * self.new_abscissas[3] + self.new_abscissas[2]) / 50) / 2 - 0.25 * self.vect_result[2]

        return None

    def prints(self) -> None:
        print("vector result: [", end="")
        for i in range(len(self.vect_result)):
            print(("%.1f" % self.vect_result[i]) if round(self.vect_result[i], 1) != 0 else ("%.1f" % 0), end="")
            if i != len(self.vect_result) - 1:
                print(", ", end="");
        print("]")

        for i in range(self.n_interpolation_points):
            print("abscissa: %.1f cm\tradius: %.1f cm" % (self.abscissa_results[i], self.radius_results[i]))

        return None

    def engine(self, is_print=True) -> None:
        if len(self.args) != 0 and self.args[0] == "-h":
            print(self.usage)
            sys.exit(0)
        self.check_args()
        self.compute()
        if is_print == True:
            self.prints()

def main():
    tmp = sys.argv
    if  tmp[0] == "./308reedpipes": tmp.pop(0)
    program = Program(sys.argv)
    program.engine()

if '__main__' == __name__:
    main()
