#include "GameOverState.h"
#include <sstream>
#include <iostream>
#include "DEFINATIONS.h"

namespace flappybird
{

	flappybird::GameOverState::GameOverState(GameDataRef data) : _data(data)
	{
	}

	void flappybird::GameOverState::Init()
	{

		this->_data->assets.LoadTexture("Game Over Background", GAMEOVER_STATE_CONTAINER_FILEPATH);
		this->_data->assets.LoadTexture("Game Over Title", GAMEOVER_TITLE_FILEPATH);
		
		_background.setTexture(this->_data->assets.GetTexture("Game Over Background"));
		_title.setTexture(this->_data->assets.GetTexture("Game Over Title"));

		_title.setPosition((SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2), (_title.getGlobalBounds().height / 2));
		_background.setPosition((SCREEN_WIDTH / 2) - (_background.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_background.getGlobalBounds().height / 2));
	}

	void flappybird::GameOverState::HandleInput()
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

	void flappybird::GameOverState::Update(float dt)
	{
	}

	void flappybird::GameOverState::Draw(float dt)
	{
		this->_data->window.clear();
		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_title);
		this->_data->window.display();
	}
}
