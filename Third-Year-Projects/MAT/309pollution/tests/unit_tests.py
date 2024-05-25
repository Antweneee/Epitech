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

    def test_PDF_01(self):  #1
        self.expected_output = "0.00\n"
        self.init_program(["3", "files/file.csv", "0",  "2"])
        with patch('sys.stdout', new = StringIO()) as fake_out:
           self.program.engine()
           self.assertEqual(fake_out.getvalue(), self.expected_output)

    def test_PDF_02(self): #2
        self.expected_output = "28.20\n"
        self.init_program(["3", "files/file.csv", "0.6",  "2"])
        with patch('sys.stdout', new = StringIO()) as fake_out:
           self.program.engine()
           self.assertEqual(fake_out.getvalue(), self.expected_output)

    def test_PDF_03(self): #3
        self.expected_output = "56.55\n"
        self.init_program(["3", "files/file.csv", "1.3",  "2"])
        with patch('sys.stdout', new = StringIO()) as fake_out:
           self.program.engine()
           self.assertEqual(fake_out.getvalue(), self.expected_output)

    def test_PDF_04(self): #4
        self.expected_output = "33.94\n"
        self.init_program(["3", "files/file.csv", "1",  "1.5"])
        with patch('sys.stdout', new = StringIO()) as fake_out:
           self.program.engine()
           self.assertEqual(fake_out.getvalue(), self.expected_output)

    def test_PDF_05(self): #5
        self.expected_output = "26.11\n"
        self.init_program(["3", "files/file.csv", "0.8",  "0.8"])
        with patch('sys.stdout', new = StringIO()) as fake_out:
           self.program.engine()
           self.assertEqual(fake_out.getvalue(), self.expected_output)

    def test_no_args(self): #6
        self.init_program([])
        with self.assertRaises(SystemExit) as cm:
            self.program.engine()
        self.assertEqual(cm.exception.code, 84)

    def test_too_many_args(self): #7
        self.init_program(["3", "files/file.csv", "0.8",  "0.8", "0.8"])
        with self.assertRaises(SystemExit) as cm:
            self.program.engine()
        self.assertEqual(cm.exception.code, 84)

    def test_empty_file(self): #8
        self.init_program(["3", "files/empty.csv", "0.8",  "0.8"])
        with self.assertRaises(SystemExit) as cm:
            self.program.engine()
        self.assertEqual(cm.exception.code, 84)

    def test_invalid_coordonate(self): #9
        self.init_program(["3", "files/invalid_coordonate.csv", "0.8",  "0.8"])
        with self.assertRaises(SystemExit) as cm:
            self.program.engine()
        self.assertEqual(cm.exception.code, 84)

    def test_invalid_data(self): #10
        self.init_program(["3", "files/invalid_data.csv", "0.8",  "0.8"])
        with self.assertRaises(SystemExit) as cm:
            self.program.engine()
        self.assertEqual(cm.exception.code, 84)
    
    def test_invalid_file(self): #11
        self.init_program(["3", "files/invalid_file.csv", "0.8",  "0.8"])
        with self.assertRaises(SystemExit) as cm:
            self.program.engine()
        self.assertEqual(cm.exception.code, 84)
    
    def test_invalid_grid_size(self): #12
        self.init_program(["-7", "files/file.csv", "0.8",  "0.8"])
        with self.assertRaises(SystemExit) as cm:
            self.program.engine()
        self.assertEqual(cm.exception.code, 84)
    
    def test_nonsensical_argument1(self): #13
        self.init_program(["3", "files/file.csv", "aaaa",  "0.8"])
        with self.assertRaises(SystemExit) as cm:
            self.program.engine()
        self.assertEqual(cm.exception.code, 84)
    
    def test_nonsensical_argument2(self): #14
        self.init_program(["3", "files/file.csv", "0.8",  "aaaa"])
        with self.assertRaises(SystemExit) as cm:
            self.program.engine()
        self.assertEqual(cm.exception.code, 84)
    
    def test_not_enough_arguments1(self): #15
        self.init_program(["3", "0.8",  "0.8"])
        with self.assertRaises(SystemExit) as cm:
            self.program.engine()
        self.assertEqual(cm.exception.code, 84)
    
    def test_not_enough_arguments2(self): #16
        self.init_program(["3", "files/file.csv", "0.8"])
        with self.assertRaises(SystemExit) as cm:
            self.program.engine()
        self.assertEqual(cm.exception.code, 84)

if "__main__" == __name__:
    unittest.main()