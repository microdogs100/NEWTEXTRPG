#include"Warrior.h"
#include <iostream> 

Warrior::Warrior() : Character(100, 20) {}
//{ } 이거는 본문임 가령 예를 들어 std::cout << "전사가 생성되었습니다!; 이렇게 쓸 수 있음
//원래 이 안에도 뭔가 들어있다면 추가적인 초기화 작업이 필요함

void Warrior::LevelUp()
{
    if (exp >= 100)
    {
        level++;
        exp = 0;
        hp += 20;
        atk += 5;
        std::cout << "전사가 레벨업했습니다! 현재 레벨: " << level << "\n";
    }
}