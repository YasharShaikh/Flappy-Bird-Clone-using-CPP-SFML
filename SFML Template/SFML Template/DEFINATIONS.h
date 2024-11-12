#pragma once

#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1024

#define SPLASH_STATE_SHOW_TIME 3.0

#define SPLASH_STATE_BACKGROUND_FILEPATH "Resources/res/Splash Background.png"

#define GAME_BACKGROUND_FILEPATH "Resources/res/sky.png"
#define GAME_TITLE_FILEPATH "Resources/res/title.png"
#define PLAY_BUTTON_FILEPATH "Resources/res/PlayButton.png"

#define PIPE_UP_FILEPATH "Resources/res/PipeUp.png"
#define PIPE_DOWN_FILEPATH "Resources/res/PipeDown.png"
#define LAND_FILEPATH "Resources/res/land.png"
#define PIPE_MOVEMENT_SPEED 200.0f


#define GAMEOVER_STATE_BACKGROUND_FILEPATH "Resources/res/Game-Over-Body.png"
#define GAMEOVER_TITLE_FILEPATH "Resources/res/Game-Over-Title.png"
#define PIPE_SPAWN_FREQUENCY 0.5f


#define BIRD_FRAME_1 "Resources/res/bird-01.png"
#define BIRD_FRAME_2 "Resources/res/bird-02.png"
#define BIRD_FRAME_3 "Resources/res/bird-03.png"
#define BIRD_FRAME_4 "Resources/res/bird-04.png"
#define BIRD_ANIMATION_DURATION 0.4f	


#define BIRD_STATE_STILL 1
#define BIRD_STATE_FALL 2
#define BIRD_STATE_FLY 3

#define GRAVITY 350.0f
#define FLY_SPEED 350.0f
#define FLY_DURATION 0.25f
#define ROTATE_SPEED 100.0f

enum GameStates
{
	eReady,
	ePlaying,
	eGameOver
};