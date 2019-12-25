# test_unittest02.py
import unittest

class MyTestCase(unittest.TestCase):
    def setUp(self):
        print('setUp() called')

    def test_sample1(self):
        self.assertEqual( (2*3), 6)
        print('test_sample1()')

    def test_sample2(self):
        self.assertEqual( (4*3), 12)
        print('test_sample2()')

    def tearDown(self):
        print('tearDown() called')

if __name__ == '__main__':
    unittest.main()
