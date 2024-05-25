#!/usr/bin/env python3

from sources.program import Program

from io import StringIO
import unittest
from unittest.mock import patch

class TestCalculator(unittest.TestCase):
    @classmethod
    def setUpClass(self): ### run once before all test cases ###
        pass

    @classmethod
    def tearDownClass(self): ### run once after all test cases ###
        pass
    
    def init_program(self, args):
        self.program = Program(args)

    def test_no_args(self):
        self.init_program([])
        with self.assertRaises(SystemExit) as cm:
            self.program.engine()
        self.assertEqual(cm.exception.code, 84)

    def test_too_many_args(self):
        self.init_program([1.5, 2, 2, 2, 5, 11, 11])
        with self.assertRaises(SystemExit) as cm:
            self.program.engine()
        self.assertEqual(cm.exception.code, 84)

    def test_negative_args(self):
        self.init_program([1.5, -2, -2, 2, -5, 11])
        with self.assertRaises(SystemExit) as cm:
            self.program.engine()
        self.assertEqual(cm.exception.code, 84)

    def test_nonsensical_args1(self):
        self.init_program([1.5, "!", 2, 2, 5, 11])
        with self.assertRaises(SystemExit) as cm:
            self.program.engine()
        self.assertEqual(cm.exception.code, 84)

    def test_nonsensical_args2(self):
        self.init_program([1.5, "minus", 2, 2, 5, 11])
        with self.assertRaises(SystemExit) as cm:
            self.program.engine()
        self.assertEqual(cm.exception.code, 84)
    
    def test_first_basic(self):
        self.init_program([1.5, 2, 2, 2, 5, 11])
        self.program.engine(False)

        expected_vector_results = [0.0, 0.0, 0.0, 0.2, 0.0]
        expected_abscissa_results = [0.0, 2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0, 16.0, 18.0, 20.0]
        expected_radius_results = [1.5, 1.7, 1.9, 2.1, 2.1, 2.0, 1.8, 1.8, 2.4, 3.5, 5.0]

        vector_results = []

        for elem in self.program.vect_result:
            vector_results.append(round(elem, 1))

        abscissa_results = []

        for elem in self.program.abscissa_results:
            abscissa_results.append(round(elem, 1))

        radius_results = []

        for elem in self.program.radius_results:
            radius_results.append(round(elem, 1))

        self.assertEqual(expected_vector_results, vector_results)
        self.assertEqual(expected_abscissa_results, abscissa_results)
        self.assertEqual(expected_radius_results, radius_results)

    def test_second_basic(self):
        self.init_program([2, 3, 2, 4, 5, 13])
        self.program.engine(False)

        expected_vector_results = [0.0, -0.2, 0.3, -0.1, 0.0]
        expected_abscissa_results = [0.0, 1.7, 3.3, 5.0, 6.7, 8.3, 10.0, 11.7, 13.3, 15.0, 16.7, 18.3, 20.0]
        expected_radius_results = [2.0, 2.6, 3.0, 3.0, 2.6, 2.2, 2.0, 2.4, 3.2, 4.0, 4.5, 4.8, 5.0]

        vector_results = []

        for elem in self.program.vect_result:
            vector_results.append(round(elem, 1))

        abscissa_results = []

        for elem in self.program.abscissa_results:
            abscissa_results.append(round(elem, 1))

        radius_results = []

        for elem in self.program.radius_results:
            radius_results.append(round(elem, 1))

        self.assertEqual(expected_vector_results, vector_results)
        self.assertEqual(expected_abscissa_results, abscissa_results)
        self.assertEqual(expected_radius_results, radius_results)

if "__main__" == __name__:
    unittest.main()