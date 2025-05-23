#!/usr/bin/python3
"""
Module that contains the function minOperations
"""


def minOperations(n):
    """
    Get the minimum number of operations to achieve exactly n 'H' characters.
    """

    sum = 0
    if n < 2:
        return 0
    else:
        for i in range(2, n + 1):
            if n % i == 0:
                sum += i
                n = n // i
            else:
                i += 1
    return sum
