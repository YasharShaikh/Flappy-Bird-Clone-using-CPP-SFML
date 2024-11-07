#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.h"

namespace flappybird
{
	class SplashState : public State
	{
	public:
		SplashState(gameDataRef data);

		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);



	private:
		gameDataRef _data;
		sf::Clock _clock;
		sf::Texture _backgroundText;
		sf::Sprite _backgroundSprite;
	};

}

