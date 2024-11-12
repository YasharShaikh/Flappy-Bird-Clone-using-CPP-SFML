#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.h"
namespace flappybird
{
	class Collision
	{
	public:
		Collision();
		bool CheckSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2/*, sf::Sprite sprite3, sf::Sprite sprite4*/);
		bool CheckSpriteCollision(sf::Sprite sprite1, float scale1, sf::Sprite sprite2, float scale2/*, sf::Sprite sprite3, sf::Sprite sprite4*/);

	private:
	};
}


