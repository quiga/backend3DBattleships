/*
 * State.hpp
 *
 *  Created on: 2013.01.24.
 *      Author: Baarnus
 */

#ifndef APP_STATE_HPP_
#define APP_STATE_HPP_

#include <memory>

namespace app
{

class State
{
public:
	/// Smart pointer of state class.
	typedef std::shared_ptr<State> Ptr;
	/// Run on createing of the state.
	State();
	/// Run on deletion of the state.
	virtual ~State();
protected:
	/// The main class can manipulate.
	friend class Main_t;

	/// Run when the state become active.
	virtual void onActivate();
	/// Run when the state become deactive.
	virtual void onDeactivate();

	/// Running while the state is active.
	virtual void onRun();

	/// Push a new state to the top of the active (start).
	void pushState(State::Ptr newState);
	/// Replace the active state with a new state (start).
	void replaceState(State::Ptr newState);
	/// Pop the active state (stop).
	void popState();
	/// Pop all the state
	void popAllState();
};

} /* namespace app */
#endif /* APP_STATE_HPP_ */
