#include"Warrior.h"
#include <iostream> 

Warrior::Warrior() : Character(100, 20) {}
//{ } �̰Ŵ� ������ ���� ���� ��� std::cout << "���簡 �����Ǿ����ϴ�!; �̷��� �� �� ����
//���� �� �ȿ��� ���� ����ִٸ� �߰����� �ʱ�ȭ �۾��� �ʿ���

void Warrior::LevelUp()
{
    if (exp >= 100)
    {
        level++;
        exp = 0;
        hp += 20;
        atk += 5;
        std::cout << "���簡 �������߽��ϴ�! ���� ����: " << level << "\n";
    }
}