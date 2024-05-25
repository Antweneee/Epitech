import math

MAX_PLACEMENT   =   (5)
PLAYER_PIECE    =   (1)
AI_PIECE        =   (2)
BLANK_PIECE     =   (0)

def winning(size, board) -> str:
    if size == -math.inf or size == math.inf:
        return None
    for line in range(0, size):
        for col in range(MAX_PLACEMENT, size):
            if board[line][col - MAX_PLACEMENT] == PLAYER_PIECE and board[line][col - MAX_PLACEMENT + 1] == PLAYER_PIECE and board[line][col - MAX_PLACEMENT + 2] == PLAYER_PIECE \
            and board[line][col - MAX_PLACEMENT + 3] == PLAYER_PIECE and board[line][col - MAX_PLACEMENT + 4] == PLAYER_PIECE:
                return 'Human'
            if board[line][col - MAX_PLACEMENT] == AI_PIECE and board[line][col - MAX_PLACEMENT + 1] == AI_PIECE and board[line][col - MAX_PLACEMENT + 2] == AI_PIECE \
            and board[line][col - MAX_PLACEMENT + 3] == AI_PIECE and board[line][col - MAX_PLACEMENT + 4] == AI_PIECE:
                return 'IA'

    for line in range(MAX_PLACEMENT, size):
        for col in range(0, size):
            if board[line - MAX_PLACEMENT][col] == PLAYER_PIECE and board[line - MAX_PLACEMENT + 1][col] == PLAYER_PIECE and board[line - MAX_PLACEMENT + 2][col] == PLAYER_PIECE \
            and board[line - MAX_PLACEMENT + 3][col] == PLAYER_PIECE and board[line - MAX_PLACEMENT + 4][col] == PLAYER_PIECE:
                return 'Human'
            if board[line - MAX_PLACEMENT][col] == AI_PIECE and board[line - MAX_PLACEMENT + 1][col] == AI_PIECE and board[line - MAX_PLACEMENT + 2][col] == AI_PIECE \
            and board[line - MAX_PLACEMENT + 3][col] == AI_PIECE and board[line - MAX_PLACEMENT + 4][col] == AI_PIECE:
                return 'IA'

    for line in range(0, size - MAX_PLACEMENT + 1):
        for col in range(0, size - MAX_PLACEMENT + 1):
            if board[line][col] == PLAYER_PIECE and board[line + 1][col + 1] == PLAYER_PIECE and board[line + 2][col + 2] == PLAYER_PIECE \
            and board[line + 3][col + 3] == PLAYER_PIECE and board[line + 4][col + 4] == PLAYER_PIECE:
                return 'Human'
            if board[line][col] == AI_PIECE and board[line + 1][col + 1] == AI_PIECE and board[line + 2][col + 2] == AI_PIECE \
            and board[line + 3][col + 3] == AI_PIECE and board[line + 4][col + 4] == AI_PIECE:
                return 'IA'

    for line in range(0, size - MAX_PLACEMENT + 1):
        for col in range(MAX_PLACEMENT, size):
            if board[line][col] == PLAYER_PIECE and board[line + 1][col - 1] == PLAYER_PIECE and board[line + 2][col - 2] == PLAYER_PIECE \
            and board[line + 3][col - 3] == PLAYER_PIECE and board[line + 4][col - 4] == PLAYER_PIECE:
                return 'Human'
            if board[line][col] == AI_PIECE and board[line + 1][col - 1] == AI_PIECE and board[line + 2][col - 2] == AI_PIECE \
            and board[line + 3][col - 3] == AI_PIECE and board[line + 4][col - 4] == AI_PIECE:
                return 'IA'

    for line in range(0, size):
        for col in range(0, size):
            if board[line][col] == BLANK_PIECE:
                return None
    return 'Tie'
