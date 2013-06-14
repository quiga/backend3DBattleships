/*
 * Main.hpp
 *
 *  Created on: 2013.01.24.
 *      Author: Baarnus
 */

#ifndef APP_MAIN_HPP_
#define APP_MAIN_HPP_

#include <memory>
#include <stack>

#include "State.hpp"

namespace app
{

class Main
{
public:
	/// Push a new state.
	void pushState(const State::Ptr newState);
	/// Replace the stop state.
	void replaceState(const State::Ptr newState);
	/// Pop the top state.
	void popState();
	/// Pop all state
	void stop();

	/// Start and run the state machine.
	int run(State::Ptr startState);

	/// Smart pointer type for the app::Main class.
	typedef std::shared_ptr<Main> Ptr;
	/// Singleton object of app::Main class.
	static Main& getSingleton();
private:
	/// The stack of the states.
	std::stack<State::Ptr> m_states;
	/// Exit
	bool mRunning;

	/// Default constructor.
	Main();
	/// Update the state.
	void updateState();
};

extern Main& MainSingleton;

} /* namespace app */
#endif /* APP_MAIN_HPP_ */
