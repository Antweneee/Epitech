/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** IDisplay
*/

#ifndef IDISPLAY_HPP_
    #define IDISPLAY_HPP_
    #include "enum.hpp"
    #include "IInfo.hpp"

class IDisplay {
    public:
        virtual ~IDisplay() = default;
        virtual INDIE::KEYS get_key() = 0;
        virtual void draw() = 0;
        virtual void init() = 0;
        virtual IInfo::GameScenes window_handler() = 0;
        virtual void clear() = 0;
        virtual void refresh() = 0;
    protected:
    private:
};

#endif /* !IDISPLAY_HPP_ */
