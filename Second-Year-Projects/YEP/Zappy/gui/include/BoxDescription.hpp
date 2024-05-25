/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** BoxDescription
*/

#ifndef BOXDESCRIPTION_HPP_
#define BOXDESCRIPTION_HPP_

#include "Button.hpp"

class BoxDescription {
    enum CELLTEXTS {
        TITLE,
        POSITION,
        TEAMS,
    };
    public:
        BoxDescription();
        ~BoxDescription();

        sf::Sprite getBoxSprite() const;
        void setPosBoxSprite(sf::Vector2f pos);

        sf::Sprite getDeraumereSprite() const;
        sf::Sprite getFoodSprite() const;
        sf::Sprite getLinemateSprite() const;
        sf::Sprite getMendianeSprite() const;
        sf::Sprite getPhirasSprite() const;
        sf::Sprite getSiburSprite() const;
        sf::Sprite getThystameSprite() const;

        void setPosMapSprite(std::vector<std::pair<int, int>> positions);
    protected:
    private:
        sf::Texture _boxTexture;
        sf::Sprite _boxSprite;

        sf::Texture _deraumereTexture;
        sf::Sprite _deraumereSprite;

        sf::Texture _foodTexture;
        sf::Sprite _foodSprite;

        sf::Texture _linemateTexture;
        sf::Sprite _linemateSprite;

        sf::Texture _mendianeTexture;
        sf::Sprite _mendianeSprite;

        sf::Texture _phirasTexture;
        sf::Sprite _phirasSprite;

        sf::Texture _siburTexture;
        sf::Sprite _siburSprite;

        sf::Texture _thystameTexture;
        sf::Sprite _thystameSprite;
        // std::map<std::string, std::shared_ptr<sf::Sprite>> _sprites;
        bool _playDescription;
};

#endif /* !BOXDESCRIPTION_HPP_ */
