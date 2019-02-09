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
#include <gmpxx.h> // see: https://gmplib.org/manual/C_002b_002b-Class-Interface.html
typedef mpz_class BigInt;

class CoinTossGame {
protected:
  BigInt my_score = 0;
  BigInt op_score = 6;

public:
  BigInt run() {
    return op_score;
  }
};

#endif
