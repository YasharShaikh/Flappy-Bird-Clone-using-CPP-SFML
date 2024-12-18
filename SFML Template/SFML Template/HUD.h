#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "DEFINATIONS.h"
namespace flappybird
{
	class HUD
	{

	public:
		HUD(GameDataRef data);
		void Draw();
		void UpdateScore(int score);

	private:
		GameDataRef _data;
		sf::Text _scoreText;
	};

}

