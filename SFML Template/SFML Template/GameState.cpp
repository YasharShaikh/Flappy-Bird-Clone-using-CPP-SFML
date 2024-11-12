#include "GameState.h"
#include <sstream>
#include <iostream>
#include "DEFINATIONS.h"
#include "GameOverState.h"

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
		this->_data->assets.LoadTexture("Scoring Pipe", INVISIBLE_SCORING_PIPE_FILEPATH);
		this->_data->assets.LoadTexture("Land", LAND_FILEPATH);
		this->_data->assets.LoadTexture("Bird Frame 1", BIRD_FRAME_1);
		this->_data->assets.LoadTexture("Bird Frame 2", BIRD_FRAME_2);
		this->_data->assets.LoadTexture("Bird Frame 3", BIRD_FRAME_3);
		this->_data->assets.LoadTexture("Bird Frame 4", BIRD_FRAME_4);
		this->_data->assets.LoadFont("Arial Font", SCORE_POINTS_FONT);
		_background.setTexture(this->_data->assets.GetTexture("Game State Background"));

		pipe = new Pipe(_data);
		land = new Land(_data);
		bird = new Bird(_data);
		flash = new Flash(_data);
		hud = new HUD(_data);

		_score = 0;
		hud->UpdateScore(-_score);

		_gameState = GameStates::eReady;
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

			if (_data->input.IsSpriteClicked(_background, sf::Mouse::Left, this->_data->window))
			{
				if (GameStates::eGameOver != _gameState)
				{
					_gameState = GameStates::ePlaying;
					bird->Tap();
				}
			}
		}
	}
	void GameState::Update(float dt)
	{
		if (GameStates::eGameOver != _gameState)
		{
			land->Moveland(dt);
			bird->Animate(dt);
		}


		if (GameStates::ePlaying == _gameState)
		{
			pipe->MovePipe(dt);
			if (_clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY)
			{
				pipe->RandomizePipeOffset();
				pipe->SpawnTopPipe();
				pipe->SpawnBottomPipe();
				pipe->SpawnInvisiblePipe();
				pipe->SpawnScoringPipe();
				_clock.restart();
			}

			bird->Update(dt);
			std::vector<sf::Sprite> landSprite = land->getSprite();
			for (int i = 0; i < landSprite.size(); i++)
			{
				if (collision.CheckSpriteCollision(bird->getSprite(), 0.7f, landSprite.at(i), 0.1f))
				{
					_gameState = GameStates::eGameOver;
					_clock.restart();
				}
			}

			std::vector<sf::Sprite> pipeSprite = pipe->getSprite();
			for (int i = 0; i < pipeSprite.size(); i++)
			{
				if (collision.CheckSpriteCollision(bird->getSprite(), 0.625f, pipeSprite.at(i), 1.0f))
				{
					_gameState = GameStates::eGameOver;
					_clock.restart();
				}
			}


			if (GameStates::ePlaying == _gameState)
			{
				std::vector<sf::Sprite>& scoringSprites = pipe->getScoringSprite();
				for (int i = 0; i < scoringSprites.size(); i++)
				{
					if (collision.CheckSpriteCollision(bird->getSprite(), 0.625f, scoringSprites.at(i), 1.0f))
					{
						_score++;
						hud->UpdateScore(_score);
						scoringSprites.erase(scoringSprites.begin() + i);
					}
				}
			}
		}

		if (GameStates::eGameOver == _gameState)
		{
			flash->Show(dt);
			if (_clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER)
			{
				_data->machine.AddState(stateRef(new GameOverState(_data, _score)), true);
			}
		}

	}
	void GameState::Draw(float dt)
	{
		this->_data->window.clear();
		this->_data->window.draw(this->_background);
		pipe->DrawPipes();
		land->DrawLand();
		bird->DrawBird();
		flash->Draw();
		hud->Draw();
		this->_data->window.display();
	}
}
