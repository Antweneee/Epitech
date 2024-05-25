from marvin.winning import winning

def valid(board, line, column) -> bool:
    try:
        return board[line][column]
    except:
        return False

def isSqvalid(board, line, column) -> bool:
    return valid(board, line + 1, column) or valid(board, line - 1, column) or valid(board, line, column + 1)    \
        or valid(board, line, column - 1) or valid(board, line + 1, column + 1) or valid(board, line - 1, column + 1)    \
        or valid(board, line + 1, column - 1) or valid(board, line - 1, column - 1)

def squaresToCheck(board) -> list:
    nboard, wboard = [], []
    for line in range(len(board)):
        for column in range(len(board)):
            if not board[line][column] and isSqvalid(board, line, column):
                nboard.append([line, column])
                board[line][column] = 1
                if winning(len(board), board) != None:
                    wboard.append([line, column])
                board[line][column] = 2
                if winning(len(board), board) != None:
                    wboard.append([line, column])
                board[line][column] = 0
    return wboard if len(wboard) else nboard
