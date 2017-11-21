#include "GameState.h"
#include "ExploreState.h"
using namespace std;

int main()
{
  GameState *state = new ExploreState();
  state->Set();
  state->Get();

  return 0;
}
