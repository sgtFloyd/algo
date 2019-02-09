#ifndef COIN_TOSS_GAME_HPP
#define COIN_TOSS_GAME_HPP
/*
 *  Your opponent starts with 6 points. You start with 0
 *  You win when your score >= your opponent's score
 *  Flip a coin until you win:
 *    When you win a flip, your opponent gains 1 point and you gain 2
 *    When you lose a flip, your points reset to 0
 */

#include <iostream>
#include <ctime>
#include <gmpxx.h> // see: https://tspiteri.gitlab.io/gmp-mpfr-sys/gmp/
using BigInt = mpz_class;

class CoinTossGame {
protected:
  BigInt my_score = 0;
  BigInt op_score = 6;
  BigInt flips = 0;

public:
  void run() {
    srand(time(NULL)); // Seed random number generator with current time

    while(my_score < op_score) {
      flips++;
      if( rand() % 2 ){
        op_score++;
        my_score++++;
      } else
        my_score = 0;
    }
  }

#endif
