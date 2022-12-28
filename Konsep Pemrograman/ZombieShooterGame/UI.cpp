#include "UI.h"

UI::UI(sf::RenderWindow& window, sf::Font font)
{
	hpUI.setSize (sf::Vector2f(150, 150)); hpUI.setOrigin(hpUI.getSize().x/2, hpUI.getSize().y/2);
	ammoUI.setSize(sf::Vector2f(20, 100)); ammoUI.setOrigin(ammoUI.getSize().x/2, ammoUI.getSize().y/2);
	gunUI.setSize(sf::Vector2f(300, 150)); gunUI.setOrigin(gunUI.getSize().x/2, gunUI.getSize().y/2);
	pauseUI.setSize(sf::Vector2f(50, 50)); pauseUI.setOrigin(pauseUI.getSize().x/2, pauseUI.getSize().y/2);
	quitUI.setSize (sf::Vector2f(50, 50)); quitUI.setOrigin(quitUI.getSize().x/2, quitUI.getSize().y/2);
	
	hpText.setFont(font);
	
	crosshair.setRadius(10); crosshair.setOrigin(sf::Vector2f(5, 5));
	
	hpUI.setPosition(80, 640);
	ammoUI.setPosition(170, 640);
	gunUI.setPosition(920, 640);
	pauseUI.setPosition(90, 30);
	quitUI.setPosition(30, 30);
	
	hpText.setPosition(540, 360);
	
	crosshair.setPosition(window.getSize().x/2, window.getSize().y/2);
	
	hpUI.setFillColor(sf::Color::Red);
	ammoUI.setFillColor(sf::Color::Yellow);
	gunUI.setFillColor(sf::Color::Yellow);
	pauseUI.setFillColor(sf::Color::Magenta);
	quitUI.setFillColor(sf::Color::Red);
}

void UI::Update(sf::RenderWindow& window){
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	crosshair.setPosition(sf::Vector2f(mousePos));
	
	pauseBtnColl = pauseUI.getGlobalBounds();
	quitBtnColl = quitUI.getGlobalBounds();

	if(pauseBtnColl.contains(sf::Vector2f(mousePos)) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) //Pause
	if(quitBtnColl.contains(sf::Vector2f(mousePos)) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) window.close();
	
	hpText.setCharacterSize(24);
    //hpText.setString(patch::to_string(100));
}

void UI::Draw(sf::RenderWindow& window){
	window.draw(hpUI);
	window.draw(hpText);
	window.draw(ammoUI);
	window.draw(gunUI);
	window.draw(enemyUI);
	window.draw(pauseUI);
	window.draw(quitUI);
	window.draw(crosshair);
}

