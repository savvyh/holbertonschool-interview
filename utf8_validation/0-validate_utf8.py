#!/usr/bin/python3
"""
UTF-8 Validation
"""


def validUTF8(data):
    """
    Check if a given data set represents a valid UTF-8 encoding.

    Args:
        data: List of integers representing bytes

    Returns:
        True if data is a valid UTF-8 encoding, else False
    """
    index = 0

    while index < len(data):
        current_byte = data[index]

        if current_byte < 0 or current_byte > 255:
            return False

        binary_string = format(current_byte, '08b')

        expected_bytes = 0
        for bit in binary_string:
            if bit == '1':
                expected_bytes += 1
            else:
                break

        if expected_bytes == 0:
            index += 1
            continue

        if expected_bytes == 1 or expected_bytes > 4:
            return False

        if index + expected_bytes > len(data):
            return False

        for continuation_index in range(index + 1, index + expected_bytes):
            continuation_byte = data[continuation_index]
            if continuation_byte < 0 or continuation_byte > 255:
                return False
            continuation_binary = format(continuation_byte, '08b')
            if not continuation_binary.startswith('10'):
                return False

        index += expected_bytes

    return True
