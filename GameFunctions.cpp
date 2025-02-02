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
        std::cout << "현재 내 캐릭의 체력은 " << character.hp << ", 공격력은 " << character.atk << "입니다\n";
        std::cout << '\n';
        std::cout << "그리고 몬스터의 현재 체력과 공격력입니다\n";
        std::cout << "HP : " << monster.hp << " , ATK : " << monster.atk << '\n';
        std::cout << "1. 공격한다\n";
        std::cout << "2. 막는다\n";
        std::cin >> input;
        std::cout << '\n';

        switch (input) //전투 방식은 좀 더 개선가능할 듯
        {
        case 1:
            monster.hp -= character.atk;   
            break;
        case 2:
            character.hp -= monster.atk;
            break;
        default:
            std::cout << "잘못된 입력입니다\n";
            std::cout << "다시 입력해주세요\n";
            continue;
        }
    }

    if (monster.hp <= 0)
    {
        std::cout << "전투가 끝났습니다\n";
        character.exp += 40;
        std::cout << "경험치를 " << character.exp << " 획득했습니다\n";
        character.LevelUp();
        std::cout << "1. 계속 사냥하기\n";
        std::cout << "2. 마을로 돌아가기\n";
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
            std::cout << "잘못된 입력입니다\n";
            std::cout << "다시 입력해주세요\n";
            Battle();
        }
    }

    if (character.hp <= 0)
    {
        std::cout << "주인공이 죽었습니다 \n";
        std::cout << "마을로 돌아갑니다 \n";
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
    std::cout << "사냥터입니다\n";
    std::cout << '\n';

    srand(time(0));
    int monsterType = rand() % 2;
    if (monsterType == 0)
    {
        std::cout << "슬라임을 만났습니다\n";
    }
    else
    {
        std::cout << "고블린을 만났습니다\n";
    }

    std::cout << "싸우시겠습니까?\n";
    std::cout << "1. 싸운다\n";
    std::cout << "2. 마을로 돌아간다\n";
    std::cin >> input;
    std::cout << '\n';

    switch (input)
    {
    case 1:
        std::cout << "전투에 돌입합니다\n";
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
        std::cout << "마을로 도망갑니다\n";
        Town();
        std::cout << '\n';
    default:
        std::cout << "잘못된 입력입니다\n";
        std::cout << "다시 입력해주세요\n";
        BattleField();
        std::cout << '\n';
    }
}

void Town()
{
    std::cout << "마을입니다\n";
    std::cout << "1. 사냥한다\n";
    std::cout << "2. 캐릭터 선택창으로 돌아간다\n";
    std::cout << "3. 게임 종료\n";
    std::cin >> input;
    std::cout << '\n';

    switch (input)
    {
    case 1:
        std::cout << "사냥터로 이동합니다\n";
        std::cout << '\n';
        BattleField();
        std::cout << '\n';
    case 2:
        std::cout << "캐릭터 선택창으로 돌아갑니다\n";
        JobSelect();
        std::cout << '\n';

    case 3:
        std::cout << "게임을 종료합니다\n";
        exit(0);

    default:
        std::cout << "잘못된 입력입니다\n";
        std::cout << "다시 입력해주세요\n";
        Town();
        std::cout << '\n';
    }
}

void JobSelect()
{
    std::cout << "직업을 선택합니다\n";
    std::cout << "1. 전사\n";
    std::cout << "2. 법사\n";
    std::cout << "3. 게임 시작 창으로 돌아가기\n";
    std::cin >> select;
    std::cout << '\n';

    switch (select)
    {
    case 1:
        std::cout << "전사를 선택하셨습니다\n";
        Town();
        std::cout << '\n';

    case 2:
        std::cout << "법사를 선택하셨습니다\n";
        Town();
        std::cout << '\n';

    case 3:
        std::cout << "게임 시작 화면으로 돌아갑니다\n";
        GameStart();
        std::cout << '\n';

    default:
        std::cout << "잘못된 입력입니다\n";
        std::cout << "다시 입력해주세요 \n";
        JobSelect();
        std::cout << '\n';
    }
}

void GameStart()
{
    std::cout << "Text RPG 세계에 오신 것을 환영합니다\n";
    std::cout << "1. 게임 시작\n";
    std::cout << "2. 게임 종료\n";
    std::cin >> input;
    std::cout << '\n';

    switch (input)
    {
    case 1:
        JobSelect();
        std::cout << '\n';
    case 2:
        std::cout << "게임을 종료합니다\n";
        break;
    default:
        std::cout << "잘못된 입력입니다\n";
        std::cout << "다시 입력해주세요\n";
        GameStart();
        std::cout << '\n';
    }
}