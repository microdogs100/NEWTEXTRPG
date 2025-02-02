#ifndef CHARACTER_H
#define CHARACTER_H

class Character
{
public:
    int hp;
    int atk;
    int level;
    int exp;

    Character(int hp, int atk); //생성자 선언 -> 이렇게 쓰시오
    virtual void LevelUp() = 0; // 순수 가상 함수
};

#endif // CHARACTER_H
