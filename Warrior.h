#ifndef WARRIOR_H
#define WARRIOR_H

#include "Character.h"

class Warrior : public Character
{
public:
	Warrior(); //생성자
	void LevelUp() override; 

	//캐릭터.h에 보면 virtual void LevelUp() = 0; 이게 있음
	// 이걸 선언해서 캐릭터 클래스가 추상 클래스이고 얘가 스스로 생성 못하게 해둠

	//캐릭터 클래스를 상속 받아 LevelUP을 오버라이딩하여 해당 직업 캐릭의 레벨업 동작을 정의함

	//이렇게 하면 클래스 상속 받는 다양한 직업들이 고유한 레벨업 동작 정의 가능하고
	//한편으로 캐릭터 클래스는 공통된 인터페이스를 제공하여 일관된 방식으로 동작 호출 가능
};

#endif // WARRIOR_H
