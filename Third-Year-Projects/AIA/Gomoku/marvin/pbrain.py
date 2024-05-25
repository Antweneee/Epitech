import sys
import argparse
import time
import math
from marvin.evaluation import evaluationScore
from marvin.winning import winning
from marvin.squares import squaresToCheck
from marvin.prunning import pruneBoard


RETURN_SUCCESS  =   (0)
SCORES          =   {'IA': 10, 'Human': -10, 'Tie': 0}
SIZE            =   (20)
PLAYER_PIECE    =   (1)
AI_PIECE        =   (2)
BLANK_PIECE     =   (0)
BOARD           =   [[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]


class AI:
    def __init__(self, size=-math.inf, board=[]) -> None:
        self._size = size
        self._board = board
        self._scores = {'IA': 10, 'Human': -10, 'Tie': 0}
        self._timer = 0

    def isInitialized(self) -> bool:
        if self._size != -math.inf:
            return True
        return False

    def initBoard(self, size, board) -> None:
        self._size = size
        self._board = board

    def __AI(self, size, board, offset) -> tuple:
        highestScore = -math.inf
        move = None
        squares = squaresToCheck(board)
        for sq in squares:
            line, column = sq
            if board[line][column] == BLANK_PIECE:
                self.__Drop(board, line, column, AI_PIECE)
                score = self.__Minimax(size, board, 3, -math.inf, math.inf, False)
                self.__Drop(board, line, column, BLANK_PIECE)
                if score > highestScore:
                    highestScore = score
                    move = (line, column)
        x, y = (move[1] + offset[0]), (move[0] + offset[1])
        self.__Drop(self._board, y, x, AI_PIECE)
        return x, y
    
    def __Timeout(self):
        timeout = time.time() - self._timer
        return True if timeout >= 4.5 else False

    def __Minimax(self, size, board, depth, alpha, beta, isMaximizing) -> list:
        result = winning(size, board)
        if result != None:
            return SCORES.get(result)
        if depth == 0 or self.__Timeout() == True:
            eval = evaluationScore(board)
            return eval * -1
        bestscore = -math.inf if isMaximizing else math.inf
        squares = squaresToCheck(board)
        for sq in squares:
            line, column = sq
            piece = AI_PIECE if isMaximizing else PLAYER_PIECE
            self.__Drop(board, line, column, piece)
            score = self.__Minimax(size, board, depth - 1, alpha, beta, False if isMaximizing else True)
            bestscore = max(bestscore, score) if isMaximizing else min(bestscore, score)
            if isMaximizing:
                alpha = max(bestscore, alpha)
            else:
                beta = min(bestscore, beta)
            self.__Drop(board, line, column, BLANK_PIECE)
            if alpha >= beta:
                break
        return bestscore

    def PrintBoard(self) -> None:
        t = [('  ' if i < 10 else ' ') + str(i) for i in range(self._size)]
        print(' ', end="")
        print(''.join(t))
        for i in range(self._size):
            print((' ' if i < 10 else '') + str(i), end="")
            for j in range(self._size):
                if self._board[i][j] == AI_PIECE:
                    print('[o]', end="")
                elif self._board[i][j] == PLAYER_PIECE:
                    print('[x]', end="")
                else:
                    print('[.]', end="")
            print()

    def __Drop(self, board, line, column, piece) -> None:
        board[line][column] = piece
        # self.__PrintBoard()

    def __IsAI(self) -> bool:
        for i in range(self._size):
            for j in range(self._size):
                if self._board[i][j] != BLANK_PIECE:
                    return False
        return True

    def getBoard(self) -> list:
        return self._board

    def StartAI(self, aiStart, board) -> tuple:
        self._timer = time.time()
        self._board = board
        if aiStart == True:
            self.__Drop(self._board, self._size // 2, self._size // 2, AI_PIECE)
            return self._size // 2, self._size  // 2
            # print(f'{self._size // 2},{self._size // 2}')
            # return self.__Drop(self._board, self._size // 2, self._size // 2, AI_PIECE)
        board, offset = pruneBoard(self._size, self._board)
        x, y = self.__AI(len(board), board, offset)
        # self.__PrintBoard()
        self._timer = 0
        return x, y

# def main() -> int:
    # ai = AI(SIZE, BOARD)
    # result = winning(ai._size, ai._board)
    # while result == None:
        # ai.StartAI()
        # x, y = map(int, input("Give position at [X],[Y]: ").split(','))
        # if x > SIZE - 1 or y > SIZE - 1:
            # print("Bad [X] or / and [Y]")
            # return -1
        # if BOARD[x][y] == 0:
            # BOARD[x][y] = 1
        # result = winning(ai._size, ai._board)
    # print(result)
    # return RETURN_SUCCESS
# 
# if '__main__' == __name__:
    # parser = argparse.ArgumentParser()
    # parser.parse_args()
    # main()