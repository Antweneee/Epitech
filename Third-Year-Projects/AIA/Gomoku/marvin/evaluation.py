MAX_PLACEMENT   =   (5)
HORIZONTAL      =   (1)
VERTICAL        =   (2)
ADJ_MATRIX      =   [0, 2, 4, 8, 16, 32]

def adjScore(sr) -> int:
    try:
        return ADJ_MATRIX[sr]
    except:
        return -1

def blockScore(piece, curr, sr, score) -> tuple:
    if piece != curr:
        if curr == 0:
            curr = piece
            sr = 1
        else:
            score += curr * adjScore(sr)
            curr = piece
            sr = 1
    else:
        if piece != 0:
            sr += 1
    return curr, sr, score

def gScore(board, check) -> int:
    score = 0
    for line in range(len(board)):
        curr = 0
        sr = 0
        for column in range(len(board)):
            curr, sr, score = blockScore(board[line][column] if check == HORIZONTAL else board[column][line], curr, sr, score)
        if curr != 0:
            score += curr * adjScore(sr)
    return score * -1

def diagonalScore(board) -> int:
    size = len(board)
    score = 0
    scores = {'dl': {}, 'dt': {}, 'dr': {}, 'db': {}}
    for line in range(MAX_PLACEMENT - 1, size):
        for key in scores:
            scores[key] = {'curr': 0, 'sr': 0, 'score': 0}
        for column in range(line + 1):
            scores['dl']['curr'], scores['dl']['sr'], scores['dl']['score'] =   \
                blockScore(board[line - column][column], scores['dl']['curr'], scores['dl']['sr'], scores['dl']['score'])
            scores['dt']['curr'], scores['dt']['sr'], scores['dt']['score'] =   \
                blockScore(board[size - 1 - column][line - column], scores['dt']['curr'], scores['dt']['sr'], scores['dt']['score'])
            scores['dr']['curr'], scores['dr']['sr'], scores['dr']['score'] =   \
                blockScore(board[column][size - 1 - line + column], scores['dr']['curr'], scores['dr']['sr'], scores['dr']['score'])
            scores['db']['curr'], scores['db']['sr'], scores['db']['score'] =   \
                blockScore(board[size - 1 - line + column][size - 1 - column], scores['db']['curr'], scores['db']['sr'], scores['db']['score'])
            score += scores['dl']['score'] + scores['dt']['score'] + scores['dr']['score'] + scores['db']['score']
    return score * -1

def evaluationScore(board) -> int:
    horizontal_score = gScore(board, HORIZONTAL)
    vertical_score = gScore(board, VERTICAL)
    diagonal_score = diagonalScore(board)
    return (horizontal_score) + (vertical_score) + (diagonal_score)
