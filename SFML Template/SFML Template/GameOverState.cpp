#include "GameOverState.h"
#include <sstream>
#include <iostream>
#include "DEFINATIONS.h"
#include "GameState.h"
#include <fstream>
namespace flappybird
{

	flappybird::GameOverState::GameOverState(GameDataRef data, int score) : _data(data), _score(score)
	{
	}

	void flappybird::GameOverState::Init()
	{

		std::fstream readFile;
		readFile.open("Resources/flappybird.txt");
		if (readFile.is_open())
		{
			while (!readFile.eof())
			{
				readFile >> _highScore;
			}
		}
		readFile.close();
		std::ofstream writeFile("Resources/flappybird.txt");
		if (writeFile)
		{
			if (_score > _highScore)
			{
				_highScore = _score;
			}
			writeFile << _highScore;
		}

		this->_data->assets.LoadTexture("Game Over Container", GAMEOVER_STATE_CONTAINER_FILEPATH);
		this->_data->assets.LoadTexture("Game Over Title", GAMEOVER_TITLE_FILEPATH);
		
		_backgrounds.setTexture(this->_data->assets.GetTexture("Main Menu State Background"));
		_container.setTexture(this->_data->assets.GetTexture("Game Over Container"));
		_title.setTexture(this->_data->assets.GetTexture("Game Over Title"));
		_retryButton.setTexture(this->_data->assets.GetTexture("Play Button"));

		_title.setPosition((SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2), (_title.getGlobalBounds().height / 2));
		_container.setPosition((SCREEN_WIDTH / 2) - (_container.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_container.getGlobalBounds().height / 2));
		_retryButton.setPosition(sf::Vector2f((_data->window.getSize().x / 2) - (_retryButton.getGlobalBounds().width / 2), _container.getPosition().y + _container.getGlobalBounds().height + (_retryButton.getGlobalBounds().height * 0.2)));


		_scoreText.setFont(_data->assets.GetFont("Arial Font"));
		_scoreText.setString(std::to_string(_score));
		_scoreText.setCharacterSize(56);
		_scoreText.setFillColor(sf::Color::White);
		_scoreText.setOrigin(sf::Vector2f(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2));
		_scoreText.setPosition(sf::Vector2f(_data->window.getSize().x / 10 * 7.25, _data->window.getSize().y / 2.15));

		_highScoreText.setFont(this->_data->assets.GetFont("Arial Font"));
		_highScoreText.setString(std::to_string(_highScore));
		_highScoreText.setCharacterSize(56);
		_highScoreText.setFillColor(sf::Color::White);
		_highScoreText.setOrigin(sf::Vector2f(_highScoreText.getGlobalBounds().width / 2, _highScoreText.getGlobalBounds().height / 2));
		_highScoreText.setPosition(sf::Vector2f(_data->window.getSize().x / 10 * 7.25, _data->window.getSize().y / 1.78));

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
		this->_data->window.draw(_scoreText);
		this->_data->window.draw(_highScoreText);
		this->_data->window.display();
	}
}
