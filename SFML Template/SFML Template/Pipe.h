#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>
#include "DEFINATIONS.h"

namespace flappybird
{
	class Pipe
	{
	public: 
		Pipe(GameDataRef data);
		void SpawnBottomPipe();
		void SpawnTopPipe();
		void SpawnInvisiblePipe();
		void MovePipe(float dt);
		void DrawPipes();
		void RandomizePipeOffset();


	private:
		GameDataRef _data;
		std::vector<sf::Sprite> pipeSprites;
		int _landHeight;
		int _pipeSpawnYOffset;

	};

}

