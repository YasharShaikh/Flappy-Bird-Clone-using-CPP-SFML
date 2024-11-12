#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.h"

namespace flappybird
{
	class GameOverState : public State
	{

	public:
		GameOverState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);


	private:
		GameDataRef _data;
		sf::Clock _clock;
		sf::Sprite _backgrounds;
		sf::Sprite _container;
		sf::Sprite _title;
		sf::Sprite _retryButton;

	};

}

