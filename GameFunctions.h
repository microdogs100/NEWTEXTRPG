#ifndef GAMEFUNCTIONS_H
#define GAMEFUNCTIONS_H

#include "Warrior.h"
#include "Magician.h"
#include "Slime.h"
#include "Goblin.h"

void GameStart();
void JobSelect();
void Town();
void BattleField();
void Battle();
void BattleCharacter(Character& character, Monster& monster);

#endif // GAMEFUNCTIONS_H
