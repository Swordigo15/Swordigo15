#ifndef UI_H
#define UI_H

#include <SFML/Graphics.hpp>

//#include "Patch.h"

class UI
{
	private:
		sf::RectangleShape hpUI;
		sf::RectangleShape ammoUI;
		sf::RectangleShape gunUI;
		sf::RectangleShape enemyUI;
		sf::RectangleShape pauseUI;
		sf::RectangleShape quitUI;
		sf::CircleShape crosshair;
		
		sf::Text hpText;
		
		sf::FloatRect pauseBtnColl;
		sf::FloatRect quitBtnColl;
		
	public:
		UI(sf::RenderWindow&, sf::Font);
		void Update(sf::RenderWindow&);
		void Draw(sf::RenderWindow&);
};

#endif

