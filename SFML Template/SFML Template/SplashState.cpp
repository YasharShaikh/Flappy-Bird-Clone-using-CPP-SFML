#include "SplashState.h"
#include <sstream>
#include "DEFINATIONS.h"
#include <iostream>

namespace flappybird
{
    SplashState::SplashState(gameDataRef data) : _data(data)
    {
        std::cout << "SplashState Constructor Called" << std::endl;
    }

    void SplashState::Init()
    {
        std::cout << "Loading texture from path: " << SPLASH_SCENE_BACKGROND_FILEPATH << std::endl;
        this->_data->asset.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROND_FILEPATH);
        _backgroundSprite.setTexture(this->_data->asset.GetTexture("Splash State Background"));
        std::cout << "SplashState Initialized" << std::endl;
    }

    void SplashState::HandleInput()
    {
        sf::Event event;
        while (_data->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                std::cout << "Window close event triggered." << std::endl;
                _data->window.close();
            }
        }
    }

    void SplashState::Update(float dt)
    {
        if (_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
        {
            std::cout << "Splash State expired, transitioning to Main Menu" << std::endl;
            //_data->machine.AddState(stateRef(new MainMenuState(_data)), true);
        }
    }

    void SplashState::Draw(float dt)
    {
        _data->window.clear();
        _data->window.draw(_backgroundSprite);
        _data->window.display();
    }
}
