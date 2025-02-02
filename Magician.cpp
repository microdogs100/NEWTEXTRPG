#include <iostream>
#include "Magician.h"

Magician::Magician() : Character(80, 40) {}    

void Magician::LevelUp()
{
    if (exp >= 100)
    {
        level++;
        exp = 0;
        hp += 10;
        atk += 10;
        std::cout << "���簡 �������߽��ϴ�! ���� ����: " << level << "\n";
    }
}