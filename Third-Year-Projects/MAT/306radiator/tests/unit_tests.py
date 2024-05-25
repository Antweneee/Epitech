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

    def init_class(self, args):
        self.program = Program(args)

    def test_subject_three_args(self):
        self.expected_output = "1\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n0\t1\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n0\t0\t1\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n0\t0\t0\t1\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n0\t0\t0\t0\t1\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\n0\t4\t0\t0\t4\t-16\t4\t0\t0\t4\t0\t0\t0\t0\t0\t0\n0\t0\t4\t0\t0\t4\t-16\t4\t0\t0\t4\t0\t0\t0\t0\t0\n0\t0\t0\t0\t0\t0\t0\t1\t0\t0\t0\t0\t0\t0\t0\t0\n0\t0\t0\t0\t0\t0\t0\t0\t1\t0\t0\t0\t0\t0\t0\t0\n0\t0\t0\t0\t0\t4\t0\t0\t4\t-16\t4\t0\t0\t4\t0\t0\n0\t0\t0\t0\t0\t0\t4\t0\t0\t4\t-16\t4\t0\t0\t4\t0\n0\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\t1\t0\t0\t0\t0\n0\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\t1\t0\t0\t0\n0\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\t1\t0\t0\n0\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\t1\t0\n0\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\t0\t1\n\n0.0\n0.0\n0.0\n0.0\n0.0\n21.9\n6.3\n0.0\n0.0\n6.3\n3.1\n0.0\n0.0\n0.0\n0.0\n0.0\n"
        self.init_class([4, 1, 1])
        with patch('sys.stdout', new = StringIO()) as fake_out:
            self.program.engine()
            self.assertEqual(fake_out.getvalue(), self.expected_output)
        self.program.clearDatas()

    def test_subject_five_args1(self):
        self.init_class([4, 1, 1, 2, 2])
        self.expected_output = "3.1\n"
        with patch('sys.stdout', new = StringIO()) as fake_out:
            self.program.engine()
            self.assertEqual(fake_out.getvalue(), self.expected_output)
        self.program.clearDatas()
    
    def test_subject_five_args2(self):
        self.init_class([5, 1, 2, 3, 2])
        self.expected_output = "3.3\n"
        with patch('sys.stdout', new = StringIO()) as fake_out:
            self.program.engine()
            self.assertEqual(fake_out.getvalue(), self.expected_output)
        self.program.clearDatas()

    def test_subject_five_args3(self):
        self.init_class([8, 4, 6, 3, 6])
        self.expected_output = "9.4\n"
        with patch('sys.stdout', new = StringIO()) as fake_out:
            self.program.engine()
            self.assertEqual(fake_out.getvalue(), self.expected_output)
        self.program.clearDatas()

    def test_subject_five_args4(self):
        self.init_class([12, 3, 9, 1, 6])
        self.expected_output = "2.5\n"
        with patch('sys.stdout', new = StringIO()) as fake_out:
            self.program.engine()
            self.assertEqual(fake_out.getvalue(), self.expected_output)
        self.program.clearDatas()
    
    def test_wrong_args_number1(self):
        self.expected_output = ""
        self.init_class([4, 2])
        with self.assertRaises(SystemExit) as cm:
            self.program.engine()
        self.assertEqual(cm.exception.code, 84)
        self.program.clearDatas()
    
    def test_to_many_args(self):
        self.expected_output = ""
        self.init_class([4, 1, 1, 2, 2, 2])
        with self.assertRaises(SystemExit) as cm:
            self.program.engine()
        self.assertEqual(cm.exception.code, 84)
        self.program.clearDatas()

    def test_wrong_args_number2(self):
        self.expected_output = ""
        self.init_class([4, 1, 1, 2])
        with self.assertRaises(SystemExit) as cm:
            self.program.engine()
        self.assertEqual(cm.exception.code, 84)
        self.program.clearDatas()
    
    def test_no_args(self):
        self.expected_output = ""
        self.init_class([])
        with self.assertRaises(SystemExit) as cm:
            self.program.engine()
        self.assertEqual(cm.exception.code, 84)
        self.program.clearDatas()

    def test_nonsensical_args1(self):
        self.expected_output = ""
        self.init_class(["aa", "bb", "cc"])
        with self.assertRaises(SystemExit) as cm:
            self.program.engine()
        self.assertEqual(cm.exception.code, 84)
        self.program.clearDatas()
    
    def test_nonsensical_args2(self):
        self.expected_output = ""
        self.init_class(["aa", "bb", "cc", "dd", "ee"])
        with self.assertRaises(SystemExit) as cm:
            self.program.engine()
        self.assertEqual(cm.exception.code, 84)
        self.program.clearDatas()

    def test_invalid_args1(self): #negative size
        self.expected_output = ""
        self.init_class([-4, 1, 1])
        with self.assertRaises(SystemExit) as cm:
            self.program.engine()
        self.assertEqual(cm.exception.code, 84)
        self.program.clearDatas()

    def test_invalid_args2(self): #out of range radiator ir
        self.expected_output = ""
        self.init_class([4, 5, 1])
        with self.assertRaises(SystemExit) as cm:
            self.program.engine()
        self.assertEqual(cm.exception.code, 84)
        self.program.clearDatas()

    def test_invalid_args3(self): #out of range radiator jr
        self.expected_output = ""
        self.init_class([4, 1, 5])
        with self.assertRaises(SystemExit) as cm:
            self.program.engine()
        self.assertEqual(cm.exception.code, 84)
        self.program.clearDatas()

    def test_invalid_args4(self): #negative radiator ir
        self.expected_output = ""
        self.init_class([4, -1, 1])
        with self.assertRaises(SystemExit) as cm:
            self.program.engine()
        self.assertEqual(cm.exception.code, 84)
        self.program.clearDatas()
    
    def test_invalid_args5(self): #negative radiator jr
        self.expected_output = ""
        self.init_class([4, 1, -1])
        with self.assertRaises(SystemExit) as cm:
            self.program.engine()
        self.assertEqual(cm.exception.code, 84)
        self.program.clearDatas()
    
    def test_invalid_args6(self): #out of range radiator ir jr
        self.expected_output = ""
        self.init_class([4, 5, 5])
        with self.assertRaises(SystemExit) as cm:
            self.program.engine()
        self.assertEqual(cm.exception.code, 84)
        self.program.clearDatas()
    
    def test_invalid_args7(self): #negative radiator ir jr
        self.expected_output = ""
        self.init_class([4, -5, -5])
        with self.assertRaises(SystemExit) as cm:
            self.program.engine()
        self.assertEqual(cm.exception.code, 84)
        self.program.clearDatas()
    
    def test_invalid_args8(self): #out of range point i
        self.expected_output = ""
        self.init_class([4, 1, 1, 5, 2])
        with self.assertRaises(SystemExit) as cm:
            self.program.engine()
        self.assertEqual(cm.exception.code, 84)
        self.program.clearDatas()
    
    def test_invalid_args9(self): #out of range point j
        self.expected_output = ""
        self.init_class([4, 1, 1, 2, 5])
        with self.assertRaises(SystemExit) as cm:
            self.program.engine()
        self.assertEqual(cm.exception.code, 84)
        self.program.clearDatas()
    
    def test_invalid_args10(self): #out of range point i j
        self.expected_output = ""
        self.init_class([4, 1, 1, 5, 5])
        with self.assertRaises(SystemExit) as cm:
            self.program.engine()
        self.assertEqual(cm.exception.code, 84)
        self.program.clearDatas()
    
    def test_invalid_args11(self): #negative point i
        self.expected_output = ""
        self.init_class([4, 1, 1, -2, 2])
        with self.assertRaises(SystemExit) as cm:
            self.program.engine()
        self.assertEqual(cm.exception.code, 84)
        self.program.clearDatas()
    
    def test_invalid_args12(self): #negative point j
        self.expected_output = ""
        self.init_class([4, 1, 1, 2, -2])
        with self.assertRaises(SystemExit) as cm:
            self.program.engine()
        self.assertEqual(cm.exception.code, 84)
        self.program.clearDatas()
    
    def test_invalid_args13(self): #negative point i j
        self.expected_output = ""
        self.init_class([4, 1, 1, -2, -2])
        with self.assertRaises(SystemExit) as cm:
            self.program.engine()
        self.assertEqual(cm.exception.code, 84)
        self.program.clearDatas()

if "__main__" == __name__:
    unittest.main()