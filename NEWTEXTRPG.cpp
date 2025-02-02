// NEWTEXTRPG.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
int input;
int select;

void GameStart();
void JobSelect();
void Town();
void BattleField();
void Battle();

struct Warrior
{
    int hp = 100;
    int atk = 20;
};

struct Magician
{
    int hp = 60;
    int atk = 60;
};

struct Slime
{
    int hp = 80;
    int atk = 15;
};

Warrior w;
Magician m;
Slime s;

void Battle()
{
    s.hp = 80; //얘도 그렇고 캐릭도 부활을 해야하네
    while (s.hp > 0 || m.hp <= 0 || w.hp <= 0)
    {   
        if (select == 1)
        {
            std::cout << "현재 내 캐릭의 체력은 " << w.hp << ", 공격력은 " << w.atk << "입니다\n";
            std::cout << '\n';
            std::cout << "그리고 슬라임의 현재 체력과 공격력입니다\n";
            std::cout << "HP : " << s.hp << " , ATK : " << s.atk << '\n';
            std::cout << "1. 공격한다\n";
            std::cout << "2. 막는다\n";
            std::cin >> input;
            std::cout << '\n';

            switch (input)
            {
            case 1:
                s.hp = s.hp - w.atk;
                break;
            case 2:
                w.hp = w.hp - s.atk;
                break;
            default:
                std::cout << "잘못된 입력입니다\n";
                std::cout << "다시 입력해주세요\n";
                Battle();
            }
        }

        else
        {
            std::cout << "현재 내 캐릭의 체력은 " << m.hp << ", 공격력은 " << m.atk << "입니다\n";
            std::cout << '\n';
            std::cout << "그리고 슬라임의 현재 체력과 공격력입니다\n";
            std::cout << "HP : " << s.hp << " , ATK : " << s.atk << '\n';
            std::cout << "1. 공격한다\n";
            std::cout << "2. 막는다\n";
            std::cin >> input;
            std::cout << '\n';

            switch (input)
            {
            case 1:
                s.hp = s.hp - w.atk;
                break;
            case 2:
                w.hp = w.hp - s.atk;
                break;
            default:
                std::cout << "잘못된 입력입니다\n";
                std::cout << "다시 입력해주세요\n";
                Battle();
            }
        }

    }

    if (s.hp <= 0)
    {
        std::cout << "전투가 끝났습니다\n";
        std::cout << "1. 계속 사냥하기\n";
        std::cout << "2. 마을로 돌아가기\n";
        std::cin >> input;
        std::cout << '\n';

        switch (input)
        {
        case 1:
            BattleField();
        case 2:
            Town();
        }
    }
    
    if (m.hp <= 0 || w.hp <= 0)
    {
        std::cout << "주인공이 죽었습니다 \n";
        std::cout << "마을로 돌아갑니다 \n";
        Town();
    }
    
}

void BattleField()
{
    std::cout << "사냥터입니다\n";
    std::cout << '\n';
    //몬스터를 여럿 설정해서 랜덤으로 만나게 하고싶음
    std::cout << "슬라임을 만났습니다\n";
    std::cout << "싸우시겠습니까?\n";
    std::cout << "1. 싸운다\n";
    std::cout << "2. 마을로 돌아간다\n";
    std::cin >> input;
    std::cout << '\n';

    switch (input)
    {
    case 1:
        std::cout << "전투에 돌입합니다\n";
        Battle();
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
    //여기서 게임 종료를 어떻게 구현해야 할 지 모르겠음
    std::cout << "마을입니다\n";
    std::cout << "1. 사냥한다\n";
    std::cout << "2. 캐릭터 선택창으로 돌아간다\n";
    std::cin >> input;
    std::cout << '\n';

    switch (input)
    {
    case 1:
        std::cout << "사냥터로 이동합니다\n";
        BattleField();
        std::cout << '\n';
    case 2:
        std::cout << "캐릭터 선택창으로 돌아갑니다\n";
        JobSelect();
        std::cout << '\n';
    
    default :
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




int main()
{   

   GameStart();
   
   
}

//마을, 사냥터
    //캐릭, 몬스터
    //전투(공격, 방어)
    //캐릭선택
    //게임파일 -> 초반 시작 유무
    //마을 -> 사냥한다, 캐릭 선택창으로 돌아간다가 뜨는 곳
    // 직업 선택창 -> 말그대로 직업 선택창
    //사냥터 -> 싸운다, 마을로 돌아간다 + 때린다 막는다, 계속 사냥하냐까지 보여주는 곳
    //몬스터 -> 사냥터에서 등장해서 상대와 싸우는 놈
    //캐릭 -> 초반에 생성해서 모든 곳을 돌아다니는 놈

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
