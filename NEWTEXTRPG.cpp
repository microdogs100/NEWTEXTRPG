// NEWTEXTRPG.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <ctime> //time 함수 정의
#include <cstdlib> //srand, rand 함수 사용을 위한 헤더파일
using namespace std;
int input;
int select;

void GameStart();
void JobSelect();
void Town();
void BattleField();
void Battle();
void BattleCharacter(int& charHp, int charAtk, int& monsterHp, int monsterAtk, int& charExp);
//16번째 줄 같은 경우에는 함수 선언임! 함수 정의가 아님
void LevelUp(struct w); //뭔가 이상한데...
void LevelUp(struct m);


struct Warrior
{
    int hp = 100;
    int atk = 20;
	int level = 1;
	int exp = 0;
};

struct Magician
{
    int hp = 60;
    int atk = 60;
    int level = 1;
	int exp = 0;
};

struct Slime
{
    int hp = 80;
    int atk = 15;
};

struct Goblin
{
	int hp = 100;
	int atk = 20;
};

Warrior w;
Magician m;
Slime s;
Goblin g;

void LevelUp(Warrior& w)
{
	if (w.exp >= 100)
	{
		w.level++;
		w.exp = 0; //남는 경험치를 넘겨주는 기능도 있으면 좋을듯
        w.hp += 20;
		w.atk += 5;
        std::cout << "전사가 레벨업했습니다! 현재 레벨: " << w.level << "\n";
	}
}
void LevelUp(Magician& m)
{
	if (m.exp >= 100)
	{
		m.level++;
		m.exp = 0;
		m.hp += 10;
		m.atk += 10;
        std::cout << "법사가 레벨업했습니다! 현재 레벨: " << m.level << "\n";
	}
}

void BattleCharacter(int& charHp, int charAtk, int& monsterHp, int monsterAtk, int& charExp)
//hp에만 참조를 사용한 이유는 캐릭터, 몬스터 체력을 직접 수정하기 위함, 공격력은 수정할 필요가 없기 때문에 참조를 사용하지 않음
//아래 Battle()함수에 있는 것을 참조하기 위해 &를 사용함
{
    while (monsterHp > 0 && charHp > 0)
    {

        std::cout << "현재 내 캐릭의 체력은 " << charHp << ", 공격력은 " << charAtk << "입니다\n";
        std::cout << '\n';
        std::cout << "그리고 몬스터의 현재 체력과 공격력입니다\n";
        std::cout << "HP : " << monsterHp << " , ATK : " << monsterAtk << '\n';
        std::cout << "1. 공격한다\n";
        std::cout << "2. 막는다\n";
        std::cin >> input;
        std::cout << '\n';

        switch (input)
        {
        case 1:
            monsterHp -= charAtk;
            break;
        case 2:
            charHp -= monsterAtk;
            break;
        default:
            std::cout << "잘못된 입력입니다\n";
            std::cout << "다시 입력해주세요\n";
            continue; //Battle()
        }
    }

    if (monsterHp <= 0)
    {
        std::cout << "전투가 끝났습니다\n";
        charExp += 40;
		std::cout << "경험치를 " << charExp << " 획득했습니다\n";
        if (w.exp >= 100)
        {
			LevelUp(w);
		}
		else if (m.exp >= 100)
		{
			LevelUp(m);
		}
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
    
    if (charHp <= 0)
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
		BattleCharacter(w.hp, w.atk, s.hp, s.atk, w.exp);
		LevelUp(w); //여기서 설정한 값들이 원본이니 여기엔 포인터나 참조를 사용하지 않음
		
	}
    else if (select == 2)
    {
        BattleCharacter(m.hp, m.atk, s.hp, s.atk, m.exp);
		LevelUp(m);
    }
}

void BattleField()
{
    std::cout << "사냥터입니다\n";
    std::cout << '\n';
    //몬스터를 여럿 설정해서 랜덤으로 만나게 하고싶음
    
	srand(time(0)); //난수 생성기의 시드를 현재 시간으로 설정, time은 현재 시간을 초 단위로 반환
	//seed란 난수 생성기의 초기값을 의미함, 이 값이 같으면 같은 난수가 생성됨
	int monsterType = rand() % 2; //몬스터 종류 랜덤으로 만나게 하기
    if (monsterType == 0)
    {
        std::cout << "슬라임을 만났습니다\n";
	    s.hp = 80;

    }

    else
    {
		std::cout << "고블린을 만났습니다\n";
		g.hp = 50;
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
            BattleCharacter(select == 1 ? w.hp : m.hp, select == 1 ? w.atk : m.atk, s.hp, s.atk, select ==1 ? w.exp : m.exp);
        }
        else 
        {
            BattleCharacter(select == 1 ? w.hp : m.hp, select == 1 ? w.atk : m.atk, g.hp, g.atk, select == 1 ? w.exp : m.exp);
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
    //여기서 게임 종료를 어떻게 구현해야 할 지 모르겠음
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
        BattleField();
        std::cout << '\n';
    case 2:
        std::cout << "캐릭터 선택창으로 돌아갑니다\n";
        JobSelect();
        std::cout << '\n';

	case 3:
		std::cout << "게임을 종료합니다\n";
		exit(0); //프로그램을 종료하는 함수 -> cstdlib에 있음 0은 정상종료를 의미
    
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
