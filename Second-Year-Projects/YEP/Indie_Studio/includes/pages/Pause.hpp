/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** Pause
*/

#ifndef PAUSE_HPP_
    #define PAUSE_HPP_
    #include "Menu.hpp"
    #include "Core.hpp"
    #include "Shapes.hpp"
    #include "IInfo.hpp"

class Pause {
    public:
        Pause();
        ~Pause();
        INDIE::KEYS get_key() {return INDIE::KEYS::F1;};
        void draw(IInfo::PaueScenes &is_Paused);
        void init();
        IInfo::GameScenes window_handler() {return IInfo::GameScenes::EXIT;};
        void clear();
        void refresh();
        void pushButton(Button& button) {this->_btnVector.emplace_back(button);};
        IInfo::PaueScenes isButtonPressed(std::vector<Button> &button);
    protected:
    private:
        std::vector<Button> _btnVector;
        Button _resumeButton;
        Button _saveButton;
        Button _exitButton;
        Core _core;
        Shapes _rect;
};

#endif /* !PAUSE_HPP_ */
