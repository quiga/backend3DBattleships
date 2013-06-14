/*
 * Main.cpp
 *
 *  Created on: 2013.01.24.
 *      Author: Baarnus
 */

#include "Main.hpp"

namespace app
{

using namespace std;

/**
 * Push a new state into the state machine.
 * Only work if the new state is non-nil.
 * @param newState the new state to the state machine.
 */
void Main_t::pushState(const State::Ptr newState)
{
	if (!newState) return;
	m_states.push(newState);
}

/**
 * Replace the top state of the state machine.
 * Only work if the new state is non-nil.
 * @param newState the new state to the state machine replacing the top state.
 */
void Main_t::replaceState(const State::Ptr newState)
{
	if (!newState) return;
	if (!m_states.empty()) m_states.pop();
	pushState(newState);
}

/**
 * Pop the top state from the state machine
 */
void Main_t::popState()
{
	if (!m_states.empty()) m_states.pop();
}

/**
 * Pop all the state from the stack
 */
void Main_t::popAllState()
{
	while (!m_states.empty())
		m_states.pop();
}

/**
 * Running the state machine of the main class with a start state.
 * Run the state then call update the state.
 * @param startState starting state of the application.
 */
int Main_t::run(State::Ptr startState)
{
	pushState(startState);
	startState.reset();

	updateState();
	while (!m_states.empty())
	{
		m_states.top()->onRun();
		updateState();
	}
	return 0;
}

/**
 * Singleton getter function.
 * @return Main::Ptr the main instance of the main function.
 */
Main_t::Ptr Main_t::getInstance()
{
	static Ptr instance(new Main_t());
	return instance;
}

Main_t::Ptr Main = Main_t::getInstance();

/**
 * Default constructor.
 */
Main_t::Main_t()
{
}

/**
 * Update the active state and run the 'onActivate' and 'onDeactivate' functions
 * on the states.
 */
void Main_t::updateState()
{
	static State::Ptr s_prev_state;
	State::Ptr actState;

	// Set the actual state
	if (!m_states.empty()) actState = m_states.top();

	// Run the corresponding functions
	if (s_prev_state != actState)
	{
		if (s_prev_state) s_prev_state->onDeactivate();
		if (actState) actState->onActivate();
	}

	// Set the previous state!
	s_prev_state = actState;
}

} /* namespace app */
