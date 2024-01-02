#!/usr/bin/python3

# Define the function canUnlockAll that takes a list of boxes as input
def canUnlockAll(boxes):
    """
    Determine if all boxes can be unlocked.

    Args:
    - boxes: A list of lists where each inner list represents
    a box and contains keys.

    Returns:
    - True if all boxes can be unlocked, else False.
    """
    # Check if the input list is empty or None
    if not boxes or len(boxes) == 0:
        return False

    # Initialize a list to keep track of unlocked boxes,
    # starting with the first box(0)
    unlocked_boxes = [0]

    # Iterate through the list of unlocked boxes
    for box in unlocked_boxes:
        # Iterate through the keys in the current box
        for key in boxes[box]:
            # Check if the key is not already in the list of unlocked boxes
            # and if the key is within the valid range of box indices
            if key not in unlocked_boxes and key < len(boxes):
                # Add the key to the list of unlocked boxes
                unlocked_boxes.append(key)

    # Check if the number of unlocked boxes is equal to the total boxes
    return len(unlocked_boxes) == len(boxes)
