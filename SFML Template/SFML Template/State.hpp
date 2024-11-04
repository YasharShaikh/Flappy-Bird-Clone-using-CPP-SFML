#pragma once

namespace flappybird
{
	class State
	{
	public:
		virtual void Init() = 0; // used when initialization 
		virtual void HandleInput() = 0; // handling input events
		virtual void Update() = 0; ////used to update the gamelogic
		virtual void Draw(float dt) = 0; //used to display the gamelogic

		virtual void Pause() {}
		virtual void Resume() {}




	};

}