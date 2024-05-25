/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** Score
*/

#ifndef SCORE_HPP_
    #define SCORE_HPP_
    #include "IDisplay.hpp"
    #include "enum.hpp"
    #include "Core.hpp"
    #include "Text.hpp"
    #include "Shapes.hpp"
    #include "Textures.hpp"

class Score : public IDisplay {
    public:
        Score();
        ~Score();
        INDIE::KEYS get_key();
        void draw();
        void init();
        void unload();
        IInfo::GameScenes window_handler();
        void clear();
        void refresh();

        size_t getHighScore() const {return _highScore;}
        size_t getsecondScore() const {return _secondScore;}
        size_t getThirdScore() const {return _highScore;}

        std::string getFirstPlayer() const {return _firstPlayer;}
        std::string getSecondPlayer() const {return _secondPlayer;}
        std::string getThirdPlayer() const {return _thirdPlayer;}


    protected:
    private:
        size_t _secondScore;
        size_t _thirdScore;
        size_t _highScore;
        std::string _firstPlayer;
        std::string _secondPlayer;
        std::string _thirdPlayer;
        Core _core;
        Textures _textures;
        Text _text;
        Shapes _shapes;
        Texture2D _texturescore;
};

#endif /* !SCORE_HPP_ */
