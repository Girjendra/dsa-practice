"""
Given two integers dividend and divisor, divide two integers without using multiplication,
division, and mod operator.
The integer division should truncate toward zero, which means losing its fractional part.
For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.
Return the quotient after dividing dividend by divisor.
Note: Assume we are dealing with an environment that could only store integers within the
32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly
greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231,
then return -231.
"""
class Solution:
    def divide(self, dd: int, dr: int) -> int:
        ispos = True if (dd >= 0) == (dr >= 0) else False
        dd = dd if dd >= 0 else -dd
        dr = dr if dr >= 0 else -dr

        q = 0
        for i in range(31, -1, -1):
            if dr << i <= dd:
                dd -= dr << i
                q |= 1 << i

        if q >= 2147483648 and ispos == True:
            return 2147483647
        elif q >= 2147483648 and ispos == False:
            return -2147483648
        return int(q) if ispos == True else -int(q)