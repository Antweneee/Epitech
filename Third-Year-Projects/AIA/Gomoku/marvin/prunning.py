import math

def pruneBoard(size, board, padding=5) -> tuple:
    left, right, top, bottom = math.inf, 0, math.inf, 0
    for line in range(size):
        for column in range(size):
            if board[line][column]:
                left = min(left, column)
                right = max(right, column)
                top = min(top, line)
                bottom = max(bottom, line)
    if padding:
        left = max(0, left - padding)
        right = min(size, right + padding)
        top = max(0, top - padding)
        bottom = min(size, bottom + padding)

    if (right - left) - (bottom - top):
        width = right - left
        height = bottom - top
        ssize = max(width, height)
        if width != ssize:
            x = ssize - width
            left = max(0, left - math.floor(x / 2))
            right = min(size - 1, right + math.floor(x / 2))
            x = ssize - (right - left)
            if x:
                if left:
                    left -= x
                else:
                    right += x
        elif height != ssize:
            x = ssize - height
            top = max(0, top - math.floor(x / 2))
            bottom = min(size - 1, bottom + math.floor(x / 2))
            x = ssize - (bottom - top)
            if x:
                if top:
                    top -= x
                else:
                    bottom += x
        if (bottom - top) != (right - left):
            print('unequal size !')
    cpboard = [[board[line][column] for column in range(left, right)] for line in range(top, bottom)]
    return cpboard, (left, top)
