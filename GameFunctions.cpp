#include <iostream>
#include <ctime>
#include <cstdlib>
#include "GameFunctions.h"

using namespace std;

int input;
int select;

Warrior w;
Magician m;
Slime s;
Goblin g;

void BattleCharacter(Character& character, Monster& monster)
{
    while (monster.hp > 0 && character.hp > 0)
    {
        std::cout << "���� �� ĳ���� ü���� " << character.hp << ", ���ݷ��� " << character.atk << "�Դϴ�\n";
        std::cout << '\n';
        std::cout << "�׸��� ������ ���� ü�°� ���ݷ��Դϴ�\n";
        std::cout << "HP : " << monster.hp << " , ATK : " << monster.atk << '\n';
        std::cout << "1. �����Ѵ�\n";
        std::cout << "2. ���´�\n";
        std::cin >> input;
        std::cout << '\n';

        switch (input) //���� ����� �� �� ���������� ��
        {
        case 1:
            monster.hp -= character.atk;   
            break;
        case 2:
            character.hp -= monster.atk;
            break;
        default:
            std::cout << "�߸��� �Է��Դϴ�\n";
            std::cout << "�ٽ� �Է����ּ���\n";
            continue;
        }
    }

    if (monster.hp <= 0)
    {
        std::cout << "������ �������ϴ�\n";
        character.exp += 40;
        std::cout << "����ġ�� " << character.exp << " ȹ���߽��ϴ�\n";
        character.LevelUp();
        std::cout << "1. ��� ����ϱ�\n";
        std::cout << "2. ������ ���ư���\n";
        std::cin >> input;
        std::cout << '\n';

        switch (input)
        {
        case 1:
            BattleField();
            break;
        case 2:
            Town();
            break;
        default:
            std::cout << "�߸��� �Է��Դϴ�\n";
            std::cout << "�ٽ� �Է����ּ���\n";
            Battle();
        }
    }

    if (character.hp <= 0)
    {
        std::cout << "���ΰ��� �׾����ϴ� \n";
        std::cout << "������ ���ư��ϴ� \n";
        Town();
    }
}

void Battle()
{
    if (select == 1)
    {
        BattleCharacter(w, s);
    }
    else if (select == 2)
    {
        BattleCharacter(w, s);
    }
}

void BattleField()
{
    std::cout << "������Դϴ�\n";
    std::cout << '\n';

    srand(time(0));
    int monsterType = rand() % 2;
    if (monsterType == 0)
    {
        std::cout << "�������� �������ϴ�\n";
    }
    else
    {
        std::cout << "����� �������ϴ�\n";
    }

    std::cout << "�ο�ðڽ��ϱ�?\n";
    std::cout << "1. �ο��\n";
    std::cout << "2. ������ ���ư���\n";
    std::cin >> input;
    std::cout << '\n';

    switch (input)
    {
    case 1:
        std::cout << "������ �����մϴ�\n";
        if (monsterType == 0)
        {
            BattleCharacter(select == 1 ? static_cast<Character&>(w) : static_cast<Character&>(m), s);
        }
        else
        {
            BattleCharacter(select == 1 ? static_cast<Character&>(w) : static_cast<Character&>(m), g);
        }
        std::cout << '\n';
        break;
        std::cout << '\n';

    case 2:
        std::cout << "������ �������ϴ�\n";
        Town();
        std::cout << '\n';
    default:
        std::cout << "�߸��� �Է��Դϴ�\n";
        std::cout << "�ٽ� �Է����ּ���\n";
        BattleField();
        std::cout << '\n';
    }
}

void Town()
{
    std::cout << "�����Դϴ�\n";
    std::cout << "1. ����Ѵ�\n";
    std::cout << "2. ĳ���� ����â���� ���ư���\n";
    std::cout << "3. ���� ����\n";
    std::cin >> input;
    std::cout << '\n';

    switch (input)
    {
    case 1:
        std::cout << "����ͷ� �̵��մϴ�\n";
        std::cout << '\n';
        BattleField();
        std::cout << '\n';
    case 2:
        std::cout << "ĳ���� ����â���� ���ư��ϴ�\n";
        JobSelect();
        std::cout << '\n';

    case 3:
        std::cout << "������ �����մϴ�\n";
        exit(0);

    default:
        std::cout << "�߸��� �Է��Դϴ�\n";
        std::cout << "�ٽ� �Է����ּ���\n";
        Town();
        std::cout << '\n';
    }
}

void JobSelect()
{
    std::cout << "������ �����մϴ�\n";
    std::cout << "1. ����\n";
    std::cout << "2. ����\n";
    std::cout << "3. ���� ���� â���� ���ư���\n";
    std::cin >> select;
    std::cout << '\n';

    switch (select)
    {
    case 1:
        std::cout << "���縦 �����ϼ̽��ϴ�\n";
        Town();
        std::cout << '\n';

    case 2:
        std::cout << "���縦 �����ϼ̽��ϴ�\n";
        Town();
        std::cout << '\n';

    case 3:
        std::cout << "���� ���� ȭ������ ���ư��ϴ�\n";
        GameStart();
        std::cout << '\n';

    default:
        std::cout << "�߸��� �Է��Դϴ�\n";
        std::cout << "�ٽ� �Է����ּ��� \n";
        JobSelect();
        std::cout << '\n';
    }
}

void GameStart()
{
    std::cout << "Text RPG ���迡 ���� ���� ȯ���մϴ�\n";
    std::cout << "1. ���� ����\n";
    std::cout << "2. ���� ����\n";
    std::cin >> input;
    std::cout << '\n';

    switch (input)
    {
    case 1:
        JobSelect();
        std::cout << '\n';
    case 2:
        std::cout << "������ �����մϴ�\n";
        break;
    default:
        std::cout << "�߸��� �Է��Դϴ�\n";
        std::cout << "�ٽ� �Է����ּ���\n";
        GameStart();
        std::cout << '\n';
    }
}