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
#define INVISIBLE_SCORING_PIPE_FILEPATH "Resources/res/InvisibleScoringPipe.png"
#define LAND_FILEPATH "Resources/res/land.png"
#define PIPE_MOVEMENT_SPEED 200.0f
#define PIPE_SPAWN_FREQUENCY 0.5f


#define GAMEOVER_STATE_CONTAINER_FILEPATH "Resources/res/Game-Over-Body.png"
#define GAMEOVER_TITLE_FILEPATH "Resources/res/Game-Over-Title.png"
#define TIME_BEFORE_GAME_OVER 1.5f	
#define BRONZE_MEDAL_FILEPATH "Resources/res/Bronze-Medal.png"
#define SILVER_MEDAL_FILEPATH "Resources/res/Silver-Medal.png"
#define GOLD_MEDAL_FILEPATH "Resources/res/Gold-Medal.png"
#define PLATNIUM_MEDAL_FILEPATH "Resources/res/Platinum-Medal.png"

#define BRONZE_MEDAL_SCORE 0
#define SILVER_MEDAL_SCORE 5
#define GOLD_MEDAL_SCORE 50
#define PLATNIUM_MEDAL_SCORE 100


#define BIRD_FRAME_1 "Resources/res/bird-01.png"
#define BIRD_FRAME_2 "Resources/res/bird-02.png"
#define BIRD_FRAME_3 "Resources/res/bird-03.png"
#define BIRD_FRAME_4 "Resources/res/bird-04.png"
#define BIRD_ANIMATION_DURATION 0.4f	
#define SCORE_POINTS_FONT "Resources/fonts/FlappyFont.ttf"

#define BIRD_STATE_STILL 1
#define BIRD_STATE_FALL 2
#define BIRD_STATE_FLY 3

#define GRAVITY 350.0f
#define FLY_SPEED 350.0f
#define FLY_DURATION 0.25f
#define ROTATE_SPEED 100.0f


#define HIT_SOUND_FILEPATH "Resources/audio/Hit.wav"
#define POINT_SOUND_FILEPATH "Resources/audio/Point.wav"
#define WING_SOUND_FILEPATH "Resources/audio/Wing.wav"

enum GameStates
{
	eReady,
	ePlaying,
	eGameOver
};

#define FLASH_SPEED 1500.0f