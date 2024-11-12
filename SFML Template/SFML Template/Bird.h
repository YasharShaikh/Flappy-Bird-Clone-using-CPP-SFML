#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>
#include "DEFINATIONS.h"


namespace flappybird
{
	class Bird
	{
	public: 
		Bird(GameDataRef data);
		void DrawBird();
		void Animate(float dt);
		void Update(float dt);
		void Tap();
		const sf::Sprite& getSprite() const;

	private:
		GameDataRef _data;
		sf::Sprite _birdSprite;
		std::vector<sf::Texture> _animationFrames;
		unsigned int _animationIterator;
		sf::Clock _clock;
		sf::Clock _movementClock;
		float _rotation;
		int birdState;
	};

}

