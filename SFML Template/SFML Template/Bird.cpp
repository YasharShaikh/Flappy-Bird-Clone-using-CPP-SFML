#include "Bird.h"


namespace flappybird
{
	Bird::Bird(GameDataRef data) : _data(data)
	{
		_animationIterator = 0;
		_animationFrames.push_back(_data->assets.GetTexture("Bird Frame 1"));
		_animationFrames.push_back(_data->assets.GetTexture("Bird Frame 2"));
		_animationFrames.push_back(_data->assets.GetTexture("Bird Frame 3"));
		_animationFrames.push_back(_data->assets.GetTexture("Bird Frame 4"));
		_birdSprite.setTexture(_animationFrames.at(_animationIterator));

		_birdSprite.setPosition((_data->window.getSize().x / 4) - (_birdSprite.getGlobalBounds().width / 2), (_data->window.getSize().y / 2) - (_birdSprite.getGlobalBounds().height / 2));

		birdState = BIRD_STATE_STILL;

	}
	void Bird::DrawBird()
	{
		_data->window.draw(_birdSprite);

	}
	void Bird::Animate(float dt)
	{
		if (_clock.getElapsedTime().asSeconds() > BIRD_ANIMATION_DURATION / _animationFrames.size())
		{
			if (_animationIterator < _animationFrames.size() - 1)
			{
				_animationIterator++;
			}
			else
			{
				_animationIterator = 0;
			}
			_birdSprite.setTexture(_animationFrames.at(_animationIterator));
			_clock.restart();
		}
	}
	void Bird::Update(float dt)
	{
		if (BIRD_STATE_FALL == birdState)
		{
			_birdSprite.move(0, GRAVITY * dt);
		}
		else if (BIRD_STATE_FLY == birdState)
		{
			_birdSprite.move(0, -FLY_SPEED * dt);
		}

		if (_movementClock.getElapsedTime().asSeconds() > FLY_DURATION)
		{
			_movementClock.restart();
			birdState = BIRD_STATE_FALL;
		}
	}
	void Bird::Tap()
	{
		_movementClock.restart();
		birdState = BIRD_STATE_FLY;
	}
}