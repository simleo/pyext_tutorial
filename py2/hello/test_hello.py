import unittest
import hello


class TestHello(unittest.TestCase):

    def runTest(self):
        what = "World"
        greeting = hello.greet(what)
        self.assertEqual(greeting, "Hello, %s" % what)


if __name__ == '__main__':
    unittest.main()
