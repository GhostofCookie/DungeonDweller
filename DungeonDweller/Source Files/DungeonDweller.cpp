/** @date 24/10/2017
 *
 * @author Team Kodika
 *
 * This is the main file for the game.
 */

#include "Game.h"

using namespace std;

int main()
{
	auto game = std::make_unique<Game>();
	game->Initialize();
	game->Run();
	game->Cleanup();

	return 0;
}
