#include "Land.h"
#include "DEFINATIONS.h"


namespace flappybird
{
	flappybird::Land::Land(GameDataRef data) : _data(data)
	{
		sf::Sprite sprite(_data->assets.GetTexture("Land"));
		sf::Sprite sprite2(_data->assets.GetTexture("Land"));

		sprite.setPosition(0, _data->window.getSize().y - sprite.getGlobalBounds().height);
		sprite2.setPosition(sprite.getGlobalBounds().width, _data->window.getSize().y - sprite.getGlobalBounds().height);
		_landSprite.push_back(sprite);
		_landSprite.push_back(sprite2);
	}

	void Land::Moveland(float dt)
	{
		for (unsigned short int i = 0; i < _landSprite.size(); i++)
		{

				sf::Vector2f position = _landSprite.at(i).getPosition();
				float movement = PIPE_MOVEMENT_SPEED * dt;

				_landSprite.at(i).move(-movement, 0.0f);

				if (_landSprite.at(i).getPosition().x < 0 - _landSprite.at(i).getLocalBounds().width)
				{
					sf::Vector2f position(_data->window.getSize().x, _landSprite.at(i).getPosition().y);

					_landSprite.at(i).setPosition(position);
				}
		}
	}

	void Land::DrawLand()
	{
		for (unsigned short int i = 0; i < _landSprite.size(); i++)
		{
			_data->window.draw(_landSprite.at(i));
		}
	}

}

