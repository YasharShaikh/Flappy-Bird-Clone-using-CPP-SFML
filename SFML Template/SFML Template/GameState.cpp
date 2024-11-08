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
		this->_data->assets.LoadTexture("Pipe Down", PIPE_DOWN_FILEPATH);
		this->_data->assets.LoadTexture("Pipe Up", PIPE_UP_FILEPATH);
		this->_data->assets.LoadTexture("Land", LAND_FILEPATH);
		
		_background.setTexture(this->_data->assets.GetTexture("Game State Background"));
		pipe = new Pipe(_data);
		land = new Land(_data);
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
			pipe->MovePipe(dt);
			land->Moveland(dt);
		if (_clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY)
		{
			pipe->RandomizePipeOffset();
			pipe->SpawnTopPipe();
			pipe->SpawnBottomPipe();
			pipe->SpawnInvisiblePipe();
			_clock.restart();
		}

		//if(_clock.getElapsedTime())
	}
	void GameState::Draw(float dt)
	{
		this->_data->window.clear();
		this->_data->window.draw(this->_background);
		pipe->DrawPipes();
		land->DrawLand();
		this->_data->window.display();
	}
}
