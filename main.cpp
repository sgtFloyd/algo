#include <iostream>
#include "playground/coin_toss_game.hpp"

int main (int argc, char *argv[])
{
  CoinTossGame game;
  std::cout << game.run() << std::endl;
  return 0;
}
