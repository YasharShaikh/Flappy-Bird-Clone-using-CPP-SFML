#include "GameOverState.h"
#include <sstream>
#include <iostream>
#include "DEFINATIONS.h"
#include "GameState.h"
namespace flappybird
{

	flappybird::GameOverState::GameOverState(GameDataRef data) : _data(data)
	{
	}

	void flappybird::GameOverState::Init()
	{
		this->_data->assets.LoadTexture("Game Over Container", GAMEOVER_STATE_CONTAINER_FILEPATH);
		this->_data->assets.LoadTexture("Game Over Title", GAMEOVER_TITLE_FILEPATH);
		
		_backgrounds.setTexture(this->_data->assets.GetTexture("Main Menu State Background"));
		_container.setTexture(this->_data->assets.GetTexture("Game Over Container"));
		_title.setTexture(this->_data->assets.GetTexture("Game Over Title"));
		_retryButton.setTexture(this->_data->assets.GetTexture("Play Button"));

		_title.setPosition((SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2), (_title.getGlobalBounds().height / 2));
		_container.setPosition((SCREEN_WIDTH / 2) - (_container.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_container.getGlobalBounds().height / 2));
		_retryButton.setPosition(sf::Vector2f((_data->window.getSize().x / 2) - (_retryButton.getGlobalBounds().width / 2), _container.getPosition().y + _container.getGlobalBounds().height + (_retryButton.getGlobalBounds().height * 0.2)));
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
			if (this->_data->input.IsSpriteClicked(this->_retryButton, sf::Mouse::Left, this->_data->window))
			{
				this->_data->machine.AddState(stateRef(new GameState(_data)), true);
			}
		}
	}

	void flappybird::GameOverState::Update(float dt)
	{
	}

	void flappybird::GameOverState::Draw(float dt)
	{
		this->_data->window.clear();
		this->_data->window.draw(this->_backgrounds);
		this->_data->window.draw(this->_container);
		this->_data->window.draw(this->_title);
		this->_data->window.draw(this->_retryButton);
		this->_data->window.display();
	}
}
