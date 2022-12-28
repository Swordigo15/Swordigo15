#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <vector>

#include "UI.h"
#include "Enemy.h"

#include "Patch.h"

/*#include <sstream>

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}*/

int Random(int, int);

int main()
{
	time_t t;
    srand((unsigned) time(&t));
	
    sf::RenderWindow window(sf::VideoMode(1080, 720), "SFML works!");
    
    //Texture
    //sf::Texture
    
    //Font
    sf::Font font;
    font.loadFromFile("Font/horrendo.ttf");
    
    //Sound
    sf::SoundBuffer m1911Shot; m1911Shot.loadFromFile("SFX/m1911-shootSFX.wav");
    sf::SoundBuffer m1911Reload; m1911Reload.loadFromFile("SFX/m1911-reloadSFX.wav");
    
    sf::SoundBuffer zombieSFXB; zombieSFXB.loadFromFile("SFX/ZombieSFX.wav");
    
	std::vector<sf::Sound> m1911ShotSFXs;
	sf::Sound m1911ReloadSFX;
	sf::Sound zombieSFX;
    
    //Text
    sf::Text timeCountText;
    timeCountText.setFont(font);
    
    //UI
    UI ui(window, font);
    
    //Object
	sf::RectangleShape quitBtn(sf::Vector2f(50, 50)); 
	quitBtn.setOrigin(quitBtn.getSize().x/2, quitBtn.getSize().y/2);
	quitBtn.setPosition(30, 30);
	quitBtn.setFillColor(sf::Color::Red);
	
	sf::RectangleShape background(sf::Vector2f(window.getSize().x, window.getSize().y * .8f)); 
	background.setOrigin(background.getSize().x/2, background.getSize().y/2);
	background.setPosition(window.getSize().x / 2, window.getSize().y * .4f);
	background.setFillColor(sf::Color::Blue);
	
	sf::RectangleShape ground(sf::Vector2f(window.getSize().x, window.getSize().y / 4)); 
	ground.setOrigin(ground.getSize().x/2, ground.getSize().y/2);
	ground.setPosition(window.getSize().x / 2, window.getSize().y * .85f);
	ground.setFillColor(sf::Color::Green);
	
	sf::RectangleShape zombie(sf::Vector2f(40, 100));
	zombie.setOrigin(zombie.getSize().x/2, zombie.getSize().y/2);
	zombie.setPosition((float)Random(30, 1030), 530);
	
	std::vector<Enemy> enemies;
	
	sf::RectangleShape zombieb(sf::Vector2f(400, 1000));
	zombieb.setOrigin(zombieb.getSize().x/2, zombieb.getSize().y/2);
	zombieb.setPosition(210, 530);	
		
	float deltaTime = 0.0f;
	float timeCount = 0.0f;
	sf::Clock timeCountClock;
	sf::Clock clock;
	
	int x;
	float shootCD, reloadCD;
	
	int zombieCount = 5, zIndex = 0, in = 0;
	float spawnCD;
	
	float xPos;	
	
    while (window.isOpen())
    {
    	timeCount = timeCountClock.getElapsedTime().asSeconds();
    	deltaTime = clock.restart().asSeconds();
    	
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
		}
		
		shootCD	 -= deltaTime;
		reloadCD -= deltaTime;
		spawnCD  -= deltaTime;
		
		if(spawnCD <= 0 && zIndex <= zombieCount){
			xPos = (float)Random(30, 1030);
			enemies.push_back(Enemy(10));
			enemies[zIndex].SetPos(sf::Vector2f(xPos, 530));
			zIndex++;
			zombieSFX.setBuffer(zombieSFXB);
			zombieSFX.play();
			spawnCD = 5;
		}
		
		for(int i = 0; i < zIndex; i++) enemies[i].Move(.0002f);
		
		//SFX
		if(shootCD <= 0 && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		    m1911ShotSFXs.push_back(sf::Sound());
		    m1911ShotSFXs[x].setBuffer(m1911Shot);
			m1911ShotSFXs[x].play();
			x++;
			shootCD = .8;
		}
		else if(reloadCD <= 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
		    m1911ReloadSFX.setBuffer(m1911Reload);
			m1911ReloadSFX.play();
			reloadCD = 1;
			//m1911ShotSFXs.clear();
		}
    	
    	//UI
    	ui.Update(window);
				
		//Zombie Move
		if(zombie.getSize().x < 400 && zombie.getSize().y < 1000)
			
        //Shoot Cool Down Text
        timeCountText.setCharacterSize(24);
        timeCountText.setPosition(950, 20);
        timeCountText.setString(patch::to_string(shootCD));
        
        
        //Clear
	    window.clear();
	
		//Draw
		window.draw(background);
		window.draw(ground);
		
		window.draw(timeCountText);
		
		for(int i = 0; i > zIndex; i--){
			in = zIndex - i;
			enemies[in].Draw(window);	
		}
		//window.draw(zombie);
		//window.draw(zombieb);
		
		ui.Draw(window);
		
		//Display
		window.display();
	}

    return 0;
}

int Random(int x, int y){
	return x + (rand() % y);	
}

