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

class Main_t
{
public:
	/// Push a new state.
	void pushState(const State::Ptr newState);
	/// Replace the stop state.
	void replaceState(const State::Ptr newState);
	/// Pop the top state.
	void popState();
	/// Pop all state
	void popAllState();

	/// Start and run the state machine.
	int run(State::Ptr startState);

	/// Smart pointer type for the app::Main class.
	typedef std::shared_ptr<Main_t> Ptr;
	/// Singleton object of app::Main class.
	static Ptr getInstance();
private:
	/// The stack of the states.
	std::stack<State::Ptr> m_states;

	/// Default constructor.
	Main_t();
	/// Update the state.
	void updateState();
};

extern Main_t::Ptr Main;

} /* namespace app */
#endif /* APP_MAIN_HPP_ */
