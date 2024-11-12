#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>

namespace flappybird
{
	class Land
	{
	public:
		Land(GameDataRef data);
		void Moveland(float dt);
		void DrawLand();

		const std::vector<sf::Sprite>& getSprite() const;


	private:

		GameDataRef _data;
		std::vector<sf::Sprite> _landSprite;
	};
}

