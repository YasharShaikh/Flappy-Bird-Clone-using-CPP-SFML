#include "Flash.h"
namespace flappybird
{
	Flash::Flash(GameDataRef data) : _data(data)
	{
		_Shape = sf::RectangleShape(sf::Vector2f(_data->window.getSize().x, _data->window.getSize().y));
		_Shape.setFillColor(sf::Color(255, 255, 255, 0));

		flashOn = true;
	}
	void Flash::Show(float dt)
	{
		if (flashOn)
		{
			int alpha = (int)_Shape.getFillColor().a + (FLASH_SPEED * dt);

			if (alpha >= 255.0f)
			{
				alpha = 255.0f;
				flashOn = false;
			}

			_Shape.setFillColor(sf::Color(255, 255, 255, alpha));
		}
		else
		{
			int alpha = (int)_Shape.getFillColor().a - (FLASH_SPEED * dt);

			if (alpha <= 0.0f)
			{
				alpha = 0.0f;
			}

			_Shape.setFillColor(sf::Color(255, 255, 255, alpha));
		}
	}
	void Flash::Draw()
	{
		_data->window.draw(_Shape);
	}
}