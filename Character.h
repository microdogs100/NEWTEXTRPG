#ifndef CHARACTER_H
#define CHARACTER_H

class Character
{
public:
    int hp;
    int atk;
    int level;
    int exp;

    Character(int hp, int atk); //������ ���� -> �̷��� ���ÿ�
    virtual void LevelUp() = 0; // ���� ���� �Լ�
};

#endif // CHARACTER_H
