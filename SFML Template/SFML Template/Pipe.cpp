#include "Pipe.h"
#include <iostream>

namespace flappybird
{
	Pipe::Pipe(GameDataRef data) : _data(data)
	{
		_landHeight = _data->assets.GetTexture("Land").getSize().y;
		_pipeSpawnYOffset = 0;
	}
	void Pipe::SpawnBottomPipe()
	{
		sf::Sprite sprite(this->_data->assets.GetTexture("Pipe Up"));
		sprite.setPosition(this->_data->window.getSize().x, this->_data->window.getSize().y - sprite.getLocalBounds().height - _pipeSpawnYOffset);
		pipeSprites.push_back(sprite);
	}

	void Pipe::SpawnTopPipe()
	{
		sf::Sprite sprite(this->_data->assets.GetTexture("Pipe Down"));
		sprite.setPosition(this->_data->window.getSize().x, -_pipeSpawnYOffset);
		pipeSprites.push_back(sprite);
	}

	void Pipe::SpawnScoringPipe()
	{
		sf::Sprite sprite(this->_data->assets.GetTexture("Scoring Pipe"));
		sprite.setPosition(this->_data->window.getSize().x, 0);
		scoringPipeSprites.push_back(sprite);
	}


	void Pipe::SpawnInvisiblePipe()
	{
		sf::Sprite sprite(this->_data->assets.GetTexture("Pipe Down"));
		sprite.setPosition(this->_data->window.getSize().x, -_pipeSpawnYOffset);
		sprite.setColor(sf::Color(0, 0, 0, 0));
		pipeSprites.push_back(sprite);
	}

	void Pipe::MovePipe(float dt)
	{
		for (unsigned short int i = 0; i < pipeSprites.size(); i++)
		{
			if (pipeSprites.at(i).getPosition().x < 0 - pipeSprites.at(i).getLocalBounds().width)
			{
				pipeSprites.erase( pipeSprites.begin( ) + i );
			}
			else
			{
				sf::Vector2f position = pipeSprites.at(i).getPosition();
				float movement = PIPE_MOVEMENT_SPEED * dt;

				pipeSprites.at(i).move(-movement, 0);
			}
		}
		for (unsigned short int i = 0; i < scoringPipeSprites.size(); i++)
		{
			if (scoringPipeSprites.at(i).getPosition().x < 0 - scoringPipeSprites.at(i).getLocalBounds().width)
			{
				scoringPipeSprites.erase(scoringPipeSprites.begin( ) + i );
			}
			else
			{
				sf::Vector2f position = scoringPipeSprites.at(i).getPosition();
				float movement = PIPE_MOVEMENT_SPEED * dt;

				scoringPipeSprites.at(i).move(-movement, 0);
			}
		}
	}
	void Pipe::DrawPipes()
	{
		for (unsigned short int i = 0; i < pipeSprites.size(); i++)
		{
			_data->window.draw(pipeSprites.at(i));
		}
	}
	void Pipe::RandomizePipeOffset()
	{
		_pipeSpawnYOffset = rand() % (_landHeight + 1);
	}
	const std::vector<sf::Sprite>& Pipe::getSprite() const
	{
		return pipeSprites;
	}
	std::vector<sf::Sprite>& Pipe::getScoringSprite() 
	{
		return scoringPipeSprites;
	}
}