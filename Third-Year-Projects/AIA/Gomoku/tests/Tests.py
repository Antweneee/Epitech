#!/usr/bin/env python3

import unittest
from main import Game

class TestCalculator(unittest.TestCase):
    @classmethod
    def setUpClass(self): ### run once before all test cases ###
        pass

    @classmethod
    def tearDownClass(self): ### run once after all test cases ###
        pass

    def initGame(self, boardSize) -> Game:
        gameObject = Game()
        gameObject.setPlayerInput("START "+str(boardSize))
        gameObject.parsePlayerInput()
        gameObject.command.execute(gameObject)
        aiResponse = gameObject.getAiResponse()
        self.assertEqual(aiResponse, "OK")
        gameObject.endOfTurn()
        return gameObject

    def testBasicStart(self):
        self.gameObject = Game()
        self.gameObject.setPlayerInput("START 20")
        self.gameObject.parsePlayerInput()
        self.gameObject.command.execute(self.gameObject)
        aiResponse = self.gameObject.getAiResponse()
        self.assertEqual(aiResponse, "OK")

    def testDoubleStart(self):
        self.gameObject = self.initGame(20)
        self.gameObject.setPlayerInput("START 20")
        self.gameObject.parsePlayerInput()
        self.gameObject.command.execute(self.gameObject)
        self.gameObject.aiResponseFunction()
        aiResponse = self.gameObject.getAiResponse()
        self.assertEqual(aiResponse, "ERROR message")

    def testInvalidSizeStart(self):
        self.gameObject = Game()
        self.gameObject.setPlayerInput("START 3")
        self.gameObject.parsePlayerInput()
        self.gameObject.command.execute(self.gameObject)
        aiResponse = self.gameObject.getAiResponse()
        self.assertEqual(aiResponse, "ERROR message")
    
    def testNegativeSizeStart(self):
        self.gameObject = Game()
        self.gameObject.setPlayerInput("START -3")
        self.gameObject.parsePlayerInput()
        self.gameObject.command.execute(self.gameObject)
        aiResponse = self.gameObject.getAiResponse()
        self.assertEqual(aiResponse, "ERROR message")
    
    def testNonsenceSizeStart(self):
        self.gameObject = Game()
        self.gameObject.setPlayerInput("START size")
        self.gameObject.parsePlayerInput()
        self.gameObject.command.execute(self.gameObject)
        aiResponse = self.gameObject.getAiResponse()
        self.assertEqual(aiResponse, "ERROR message")
    
    def testMultipleArgumentsStart(self):
        self.gameObject = Game()
        self.gameObject.setPlayerInput("START size aaaa")
        self.gameObject.parsePlayerInput()
        self.gameObject.command.execute(self.gameObject)
        aiResponse = self.gameObject.getAiResponse()
        self.assertEqual(aiResponse, "ERROR message")

    def testValidSizeAndWrongArgumentsStart(self):
        self.gameObject = Game()
        self.gameObject.setPlayerInput("START size aaaa")
        self.gameObject.parsePlayerInput()
        self.gameObject.command.execute(self.gameObject)
        aiResponse = self.gameObject.getAiResponse()
        self.assertEqual(aiResponse, "ERROR message")

    def testInvalidCommand(self):
        self.gameObject = Game()
        self.gameObject.setPlayerInput("BAED")
        self.gameObject.parsePlayerInput()
        self.gameObject.command.execute(self.gameObject)
        aiResponse = self.gameObject.getAiResponse()
        self.assertEqual(aiResponse, "UNKNOWN command not found")
    
    def testUnitializedBoardBeginCommand(self):
        self.gameObject = Game()
        self.gameObject.setPlayerInput("BEGIN")
        self.gameObject.parsePlayerInput()
        self.gameObject.command.execute(self.gameObject)
        aiResponse = self.gameObject.getAiResponse()
        self.assertEqual(aiResponse, "ERROR message")

    def testBeginInvalidCommand(self):
        self.gameObject = self.initGame(20)
        self.gameObject.setPlayerInput("BEGIN adefezfz")
        self.gameObject.parsePlayerInput()
        self.gameObject.command.execute(self.gameObject)
        self.gameObject.aiResponseFunction()
        aiResponse = self.gameObject.getAiResponse()
        self.assertEqual(aiResponse, "ERROR message")

    def testBeginValidCommand(self):
        self.gameObject = self.initGame(20)
        self.gameObject.setPlayerInput("BEGIN")
        self.gameObject.parsePlayerInput()
        self.gameObject.command.execute(self.gameObject)
        self.gameObject.aiResponseFunction()
        aiResponse = self.gameObject.getAiResponse()
        self.assertEqual(aiResponse, "10,10")

    def testEndCommand(self):
        self.gameObject = self.initGame(20)
        self.gameObject.setPlayerInput("END")
        self.gameObject.parsePlayerInput()
        self.gameObject.command.execute(self.gameObject)
        self.gameObject.aiResponseFunction()
        aiResponse = self.gameObject.getAiResponse()
        self.assertEqual(aiResponse, "")
    
    def testUnitializedBoardTurnCommand(self):
        self.gameObject = Game()
        self.gameObject.setPlayerInput("TURN 0,0")
        self.gameObject.parsePlayerInput()
        self.gameObject.command.execute(self.gameObject)
        self.gameObject.aiResponseFunction()
        aiResponse = self.gameObject.getAiResponse()
        self.assertEqual(aiResponse, "ERROR message")
    
    def testValidTurnCommand(self):
        self.gameObject = self.initGame(20)
        self.gameObject.setPlayerInput("TURN 10,10")
        self.gameObject.parsePlayerInput()
        self.gameObject.command.execute(self.gameObject)
        self.gameObject.aiResponseFunction()
        aiResponse = self.gameObject.getAiResponse()
        self.assertEqual(aiResponse, "9,9")

    def testInvalidTurnCommand1(self):
        self.gameObject = self.initGame(20)
        self.gameObject.setPlayerInput("TURN a,10")
        self.gameObject.parsePlayerInput()
        self.gameObject.command.execute(self.gameObject)
        self.gameObject.aiResponseFunction()
        aiResponse = self.gameObject.getAiResponse()
        self.assertEqual(aiResponse, "ERROR message")

    def testInvalidTurnCommand2(self):
        self.gameObject = self.initGame(20)
        self.gameObject.setPlayerInput("TURN 10,a")
        self.gameObject.parsePlayerInput()
        self.gameObject.command.execute(self.gameObject)
        self.gameObject.aiResponseFunction()
        aiResponse = self.gameObject.getAiResponse()
        self.assertEqual(aiResponse, "ERROR message")
    
    def testInvalidTurnCommand3(self):
        self.gameObject = self.initGame(20)
        self.gameObject.setPlayerInput("TURN")
        self.gameObject.parsePlayerInput()
        self.gameObject.command.execute(self.gameObject)
        self.gameObject.aiResponseFunction()
        aiResponse = self.gameObject.getAiResponse()
        self.assertEqual(aiResponse, "ERROR message")
    
    def testInvalidTurnCommand4(self):
        self.gameObject = self.initGame(20)
        self.gameObject.setPlayerInput("TURN 10,")
        self.gameObject.parsePlayerInput()
        self.gameObject.command.execute(self.gameObject)
        self.gameObject.aiResponseFunction()
        aiResponse = self.gameObject.getAiResponse()
        self.assertEqual(aiResponse, "ERROR message")
    
    def testOutOfRangeTurnCommand1(self):
        self.gameObject = self.initGame(20)
        self.gameObject.setPlayerInput("TURN -1, -1")
        self.gameObject.parsePlayerInput()
        self.gameObject.command.execute(self.gameObject)
        self.gameObject.aiResponseFunction()
        aiResponse = self.gameObject.getAiResponse()
        self.assertEqual(aiResponse, "ERROR message")

    def testOutOfRangeTurnCommand2(self):
        self.gameObject = self.initGame(20)
        self.gameObject.setPlayerInput("TURN 21, 21")
        self.gameObject.parsePlayerInput()
        self.gameObject.command.execute(self.gameObject)
        self.gameObject.aiResponseFunction()
        aiResponse = self.gameObject.getAiResponse()
        self.assertEqual(aiResponse, "ERROR message")

    def testAboutCommand(self):
        self.gameObject = self.initGame(20)
        self.gameObject.setPlayerInput("ABOUT")
        self.gameObject.parsePlayerInput()
        self.gameObject.command.execute(self.gameObject)
        self.gameObject.aiResponseFunction()
        aiResponse = self.gameObject.getAiResponse()
        self.assertEqual(aiResponse, 'name="Zesor", version="1.0", author="Toto&Anto", country="FRA"')

    def testInvalidAboutCommand(self):
        self.gameObject = self.initGame(20)
        self.gameObject.setPlayerInput("ABOUT aaaaa")
        self.gameObject.parsePlayerInput()
        self.gameObject.command.execute(self.gameObject)
        self.gameObject.aiResponseFunction()
        aiResponse = self.gameObject.getAiResponse()
        self.assertEqual(aiResponse, 'ERROR message')
    
    def testUnitializedBoardTurnCommand(self):
        self.gameObject = Game()
        self.gameObject.setPlayerInput("BOARD")
        self.gameObject.parsePlayerInput()
        self.gameObject.command.execute(self.gameObject)
        self.gameObject.aiResponseFunction()
        aiResponse = self.gameObject.getAiResponse()
        self.assertEqual(aiResponse, "ERROR message")
    
    # def testValidBoardTurnCommand(self):
        # self.gameObject = self.initGame(20)
        # self.gameObject.setPlayerInput("BOARD")
        # self.gameObject.parsePlayerInput()
        # self.gameObject.command.execute(self.gameObject)
        # 
        # self.gameObject.command.boardInput = "DONE"
        # self.gameObject.command.boardParse()
        # self.gameObject.command.boardReset()
# 
        # self.gameObject.aiResponseFunction()
        # aiResponse = self.gameObject.getAiResponse()
        # self.assertEqual(aiResponse, "10,10")

if "__main__" == __name__:
    unittest.main()