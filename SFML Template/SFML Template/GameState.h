#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.h"
#include "Pipe.h"
#include "Land.h"

namespace flappybird
{
	class GameState : public State
	{

	public:
		GameState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);


	private:
		GameDataRef _data;
		sf::Clock _clock;
		sf::Sprite _background;

		Pipe* pipe;
		Land* land;
	};

}

//
//class GameState
//{
//};

