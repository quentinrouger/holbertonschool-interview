#!/usr/bin/python3
"""
method that determines if a given data set represents a valid UTF-8 encoding
"""


def validUTF8(data):
    """
    method that determines if a given data set represent a valid UTF-8 encoding
    """
    num_bytes = 0

    for num in data:
        mask = 1 << 7
        if num_bytes == 0:
            while mask & num:
                num_bytes += 1
                mask >>= 1

            if num_bytes == 0:
                continue

            if num_bytes == 1 or num_bytes > 4:
                return False
        else:
            if not (num & (1 << 7) and not (num & (1 << 6))):
                return False

        num_bytes -= 1

    return num_bytes == 0
