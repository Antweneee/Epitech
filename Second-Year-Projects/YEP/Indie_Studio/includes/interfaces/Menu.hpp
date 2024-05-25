/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** menu
*/

#ifndef MENU_HPP_
    #define MENU_HPP_
    #include "IDisplay.hpp"
    #include "Button.hpp"
    #include "IInfo.hpp"
    #include <vector>
    #include <memory>

class Menu : public IDisplay {
    public:
        virtual ~Menu() {};
        virtual INDIE::KEYS get_key() {return INDIE::KEYS::F1;};
        virtual void draw() {};
        virtual void init() {};
        virtual IInfo::GameScenes window_handler() {return IInfo::GameScenes::EXIT;};
        virtual void clear() {};
        virtual void refresh() {};
    protected:
        Image _cs;
        Texture2D _texturecs;
        Sound _btnsounds;
};

#endif /* !MENU_HPP_ */