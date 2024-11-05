#include "SplashState.h"


#include <sstream>
#include "SplashState.h"
#include "DEFINATIONS.h"

#include <iostream>


namespace flappybird
{
	SplashState::SplashState(gameDataRef data) : _data(data)
	{
	}
	void SplashState::Init()
	{
		this->_data->asset.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROND_FILEPATH);
		_backgroundSprite.setTexture(this->_data->asset.GetTexture("Splash State Background"));
	}
	void SplashState::HandleInput()
	{
		sf::Event event;
		while (_data->window.pollEvent(event))
		{
			_data->window.close();
		}
	}
	void SplashState::Update(float dt)
	{
		if (_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
		{
			std::cout << "Go to main menu" << std::endl;
		}
	}
	void SplashState::Draw(float dt)
	{
		_data->window.clear();

		_data->window.draw(_backgroundSprite);
		_data->window.display();
	}
}
