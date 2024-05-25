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
    
    def clear_program_data(self):
        self.program.clear_datas()
    
    #def test_subject1(self):
    #    self.expected_output = "Resources: 10 F1, 100 F2, 10 F3, 0 F4\n\nOat: 0 units at $200/unit\nWheat: 10.00 units at $200/unit\nCorn: 0 units at $200/unit\nBarley: 0 units at $200/unit\nSoy: 0 units at $200/unit\n\nTotal production value: $2000.00\n"
    #    with patch('sys.stdout', new = StringIO()) as fake_out:
    #        self.program.engine()
    #        self.assertEqual(fake_out.getvalue(), self.expected_output)
    #    self.clear_program_data()

    #def test_subject2(self):
    #    self.expected_output = "Resources: 45 F1, 41 F2, 21 F3, 63 F4\n\nOat: 0 units at $198/unit\nWheat: 20.00 units at $259/unit\nCorn: 8.50 units at $257/unit\nBarley: 1.00 units at $231/unit\nSoy: 18.25 units at $312/unit\n\nTotal production value: $13289.50\n"
    #    with patch('sys.stdout', new = StringIO()) as fake_out:
    #        self.program.engine()
    #        self.assertEqual(fake_out.getvalue(), self.expected_output)
    #    self.clear_program_data()

    def test_no_args(self):
        self.expected_output = ""
        self.init_program([])
        with self.assertRaises(SystemExit) as cm:
            self.program.engine()
        self.assertEqual(cm.exception.code, 84)
        self.clear_program_data()
    
    def test_too_many_args(self):
        self.expected_output = ""
        self.init_program(["10", "100", "10", "0", "200", "200", "200", "200", "200", "200"])
        with self.assertRaises(SystemExit) as cm:
            self.program.engine()
        self.assertEqual(cm.exception.code, 84)
        self.clear_program_data()

    
    def test_negative_args(self):
        self.expected_output = ""
        self.init_program(["10", "100", "-10", "0", "200", "-200", "200", "200", "-200"])
        with self.assertRaises(SystemExit) as cm:
            self.program.engine()
        self.assertEqual(cm.exception.code, 84)
        self.clear_program_data()

    
    def test_nonsensical_args(self):
        self.expected_output = ""
        self.init_program(["10", "c", "10", "0", "b", "200", "a", "200", "200"])
        with self.assertRaises(SystemExit) as cm:
            self.program.engine()
        self.assertEqual(cm.exception.code, 84)
        self.clear_program_data()


if "__main__" == __name__:
    unittest.main()