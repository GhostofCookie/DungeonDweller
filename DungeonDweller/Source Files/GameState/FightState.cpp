/** @date 25/11/2017
 * @author Tomas Rigaux
 *
 * This is the implementation for the Fight State.
 */

#include "FightState.h"

FightState::FightState(std::shared_ptr<Player> p, std::shared_ptr<Viewport> view)
{
	player = p;
	viewport = view;
}

void FightState::Set()
{
}

void FightState::Get()
{
	currState = States::COMBAT;
}
