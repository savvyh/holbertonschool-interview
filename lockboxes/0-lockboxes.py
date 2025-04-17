#!/usr/bin/python3
"""
Function that determines if all boxes can be opened.
"""


def canUnlockAll(boxes):
    """
    Determine if all boxes can be opened with keys.
    """
    opened = set()
    stack = [0]
    opened.add(0)

    while stack:
        current_box = stack.pop()
        for key in boxes[current_box]:
            if key < len(boxes) and key not in opened:
                opened.add(key)
                stack.append(key)

    return len(opened) == len(boxes)
