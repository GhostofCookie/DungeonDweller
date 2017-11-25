#include "Character.h"
#include "Player.h"
#include "../Screen/Screen.h"


int main()
{
   Player player(10, 10,"hi", "hello", 10, 10);
   Screen screen;

   player.Img().Draw(screen);
   // player.Draw(screen);

   cout << screen;
   return 0;
}
