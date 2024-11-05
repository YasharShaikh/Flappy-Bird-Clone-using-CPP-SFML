#pragma once

#include <memory>
#include <stralign.h>
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"


namespace flappybird
{
	struct GameData
	{
		StateMachine machine;
		sf::RenderWindow window;
		AssetManager asset;
		InputManager input;
	};

	typedef std::shared_ptr<GameData> gameDataRef;

	class Game
	{
	public:
		Game(int width, int height, std::string title);


	private:
		const float dt = 1.0 / 60.0f;
		sf::Clock _clock;
		gameDataRef _data = std::make_shared<GameData>();

		void Run();
	};
}

