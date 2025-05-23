#!/usr/bin/python3
"""
Module that contains the function minOperations 
"""


def minOperations(n):
    """
    Calculates the minimum number of operations needed to achieve exactly n 'H' characters in the file.
    """

    sum = 0
    if n < 2:
      return 0
    else:
       for i in range (2, n):
          if n % i == 0:
             sum += i
       return sum
