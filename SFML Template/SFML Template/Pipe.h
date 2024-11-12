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
		void SpawnScoringPipe();
		void SpawnInvisiblePipe();
		void MovePipe(float dt);
		void DrawPipes();	
		void RandomizePipeOffset();

		const std::vector<sf::Sprite>& getSprite() const;
		 std::vector<sf::Sprite>& getScoringSprite() ;


	private:
		GameDataRef _data;
		std::vector<sf::Sprite> pipeSprites;
		std::vector<sf::Sprite> scoringPipeSprites;
		int _landHeight;
		int _pipeSpawnYOffset;

	};

}

