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
    if data == []:
        return True

    continuation_number = 0

    for byte in data:
        binary_representation = format(byte, '08b')

        if continuation_number == 0:
            count_byte = 0
            for bit in binary_representation[:5]:
                if bit == '1':
                    count_byte += 1
                else:
                    break

            if count_byte == 0:
                continue

            if count_byte == 1 or count_byte > 4:
                return False

            continuation_number = count_byte - 1

        else:
            if not binary_representation.startswith('10'):
                return False
            continuation_number -= 1

    return continuation_number == 0
