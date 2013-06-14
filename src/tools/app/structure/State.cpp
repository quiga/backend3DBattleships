/*
 * State.cpp
 *
 *  Created on: 2013.01.24.
 *      Author: Baarnus
 */

#include "State.hpp"
#include "Main.hpp"

namespace app
{

/**
 * Default constructor of the state class.
 */
State::State()
{
}

/**
 * Destructor of the state class.
 */
State::~State()
{
}

/**
 * This function run when the state become active.
 */
void State::onActivate()
{
}

/**
 * This function run when the state become deactive.
 */
void State::onDeactivate()
{
}

/**
 * This function run while this state is active.
 */
void State::onRun()
{
}

/**
 * Push a new state to the top of the states stack.
 * This new state will become the active state.
 * @param newState the state to the top of the stack.
 */
void State::pushState(State::Ptr newState)
{
	MainSingleton.pushState(newState);
}

/**
 * Replace the top state on the stack, and become the active state.
 * @param newState the state for replace.
 */
void State::replaceState(State::Ptr newState)
{
	MainSingleton.replaceState(newState);
}

/**
 * Pop the top state from the stack. Usually the active state become deactive!
 */
void State::popState()
{
	MainSingleton.popState();
}

/**
 * Pop all the state from the stack
 */
void State::stop()
{
	MainSingleton.stop();
}

} /* namespace app */
