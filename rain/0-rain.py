#!/usr/bin/python3
"""
0-rain.py
"""


def rain(walls):
    """
    Calculate how many square units of water will be retained after it rains.
    """
    if not walls:
        return 0

    walls_length = len(walls)
    total_rainwater = 0

    for i in range(walls_length):
        max_left = max(walls[:i+1]) if i > 0 else walls[i]

        max_right = max(walls[i:]) if i < walls_length-1 else walls[i]

        water_at_position = min(max_left, max_right) - walls[i]

        if water_at_position > 0:
            total_rainwater += water_at_position

    return total_rainwater
