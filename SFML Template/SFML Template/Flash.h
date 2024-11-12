#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>
#include "DEFINATIONS.h"
namespace flappybird
{
	class Flash
	{

	public:
		Flash(GameDataRef data);
		void Show(float dt);
		void Draw();
	private:
		GameDataRef _data;
		sf::RectangleShape _Shape;
		bool flashOn;

	};

}

