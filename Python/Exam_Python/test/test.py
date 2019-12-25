import unittest
import myCalc

class MyCalcTest(unittest.TestCase):
    
    def test_add(self):
        c = myCalc.add(20, 10)
        self.assertEqual(c, 30)

    def test_sub(self):
        c = myCalc.sub(20, 10)
        self.assertEqual(c, 10)

if __name__ == "__main__":
    unittest.main()