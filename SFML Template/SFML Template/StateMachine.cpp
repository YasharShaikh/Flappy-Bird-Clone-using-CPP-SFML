#include "StateMachine.h"



namespace flappybird
{

	void flappybird::StateMachine::AddState(stateRef newState, bool isReplacing)
	{
		if (newState == nullptr) {

		}
		this->_isAdding = true;
		this->_isReplacing = isReplacing;
		this->_newState = std::move(newState);
	}

	void StateMachine::RemoveState()
	{
		this->_isRemoving = true;

	}

	void flappybird::StateMachine::ProcessStateChange()
	{
		if (this->_isRemoving && !this->_states.empty())
		{
			this->_states.pop();
			if (!this->_states.empty())
			{
				this->_states.top()->Resume();
			}
			this->_isRemoving = false;
		}

		if (this->_isAdding)
		{
			if (!this->_states.empty())
			{
				if (this->_isReplacing)
				{
					this->_states.pop();
				}
				else
				{
					this->_states.top()->Pause();
				}
			}

			this->_states.push(std::move(this->_newState));
			this->_states.top()->Init();
			this->_isAdding = false;
		}
	}

	stateRef& StateMachine::GetActiveState()
	{

		if (!_states.empty()) {
			return this->_states.top();
		}
	}
}


//stateRef& flappybird::StateMachine::GetActiveState()
//{
//	// TODO: insert return statement here
//}
