#include "Character.h"


Character::Character(int hp, int atk) : hp(hp), atk(atk), level(1), exp(0) {}

//Character::Character(int hp, int atk) 클래스의 생성자임을 나타냄
// : hp(hp), atk(atk), level(1), exp(0) 생성자의 멤버 초기화 리스트
// 생성자가 호출될 때 멤버 변수를 초기화