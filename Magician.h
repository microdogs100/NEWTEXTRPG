#ifndef MAGICIAN_H
#define MAGICIAN_H

#include "Character.h"

class Magician : public Character
{
public:
	Magician();
	void LevelUp() override;
};


#endif // MAGICIAN_H
