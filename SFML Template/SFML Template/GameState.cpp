#include "GameState.h"
#include <sstream>
#include <iostream>
#include "DEFINATIONS.h"


namespace flappybird
{
	GameState::GameState(GameDataRef data) : _data(data)
	{
	}
	void GameState::Init()
	{
		this->_data->assets.LoadTexture("Game State Background", GAME_BACKGROUND_FILEPATH);
		_background.setTexture(this->_data->assets.GetTexture("Game State Background"));

	}
	void GameState::HandleInput()
	{
		sf::Event event;
		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				_data->window.close();
			}
			/*if (this->_data->input.IsSpriteClicked(this->_playButton, sf::Mouse::Left, this->_data->window))
			{
				std::cout << "jump bird" << std::endl;
			}*/
		}
	}
	void GameState::Update(float dt)
	{
	}
	void GameState::Draw(float dt)
	{
		this->_data->window.clear();
		this->_data->window.draw(this->_background);
		this->_data->window.display();
	}
}
