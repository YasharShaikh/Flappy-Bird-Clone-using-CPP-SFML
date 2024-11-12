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
		this->_data->assets.LoadTexture("Bird Frame 1", BIRD_FRAME_1);
		this->_data->assets.LoadTexture("Bird Frame 2", BIRD_FRAME_2);
		this->_data->assets.LoadTexture("Bird Frame 3", BIRD_FRAME_3);
		this->_data->assets.LoadTexture("Bird Frame 4", BIRD_FRAME_4);
		_background.setTexture(this->_data->assets.GetTexture("Game State Background"));
		pipe = new Pipe(_data);
		land = new Land(_data);
		bird = new Bird(_data);
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
		
			if(_data->input.IsSpriteClicked(_background, sf::Mouse::Left, this->_data->window))
			{
				bird ->Tap();
			}
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

		bird->Animate(dt);
		bird->Update(dt);
	}
	void GameState::Draw(float dt)
	{
		this->_data->window.clear();
		this->_data->window.draw(this->_background);
		pipe->DrawPipes();
		land->DrawLand();
		bird->DrawBird();
		this->_data->window.display();
	}
}
