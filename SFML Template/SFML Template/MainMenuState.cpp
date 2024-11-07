#include "MainMenuState.h"
#include <sstream>
#include <iostream>
#include "DEFINATIONS.h"
#include "GameState.h"
#include "GameOverState.h"
namespace flappybird
{
	flappybird::MainMenuState::MainMenuState(GameDataRef data) : _data(data)
	{
	}

	void flappybird::MainMenuState::Init()
	{
		this->_data->assets.LoadTexture("Main Menu State Background", GAME_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Title", GAME_TITLE_FILEPATH);
		this->_data->assets.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);


		_background.setTexture(this->_data->assets.GetTexture("Main Menu State Background"));
		_title.setTexture(this->_data->assets.GetTexture("Title"));
		_playButton.setTexture(this->_data->assets.GetTexture("Play Button"));


		_title.setPosition((SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2), (_title.getGlobalBounds().height / 2));
		_playButton.setPosition((SCREEN_WIDTH / 2) - (_playButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_playButton.getGlobalBounds().height / 2));
	}

	void flappybird::MainMenuState::HandleInput()
	{
		sf::Event event;
		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				_data->window.close();
			}
			if (this->_data->input.IsSpriteClicked(this->_playButton, sf::Mouse::Left, this->_data->window))
			{
				_data->machine.AddState(stateRef(new GameOverState(this->_data)), true);
				std::cout << "Going to Game Screen " << std::endl;
			}
		}
	}

	void flappybird::MainMenuState::Update(float dt)
	{
	}

	void flappybird::MainMenuState::Draw(float dt)
	{
		this->_data->window.clear();

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_title);
		this->_data->window.draw(this->_playButton);

		this->_data->window.display();
	}

}
