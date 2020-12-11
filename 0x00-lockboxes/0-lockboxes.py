#!/usr/bin/python3
"""Open the boxes."""


def canUnlockAll(boxes):
    """Check if all the boxes can be opened"""
    if (len(boxes) == 0):
        return False
    if (type(boxes) is not list):
        return False
    checkB = [0] * len(boxes)
    checkB[0] = 1
    checkin = [0]

    while checkin:
        keys = checkin.pop()
        for key in boxes[keys]:
            if key < len(boxes):
                if not checkB[key]:
                    checkB[key] = 1
                    checkin.append(key)
    return all(checkB)
