#ifndef WARRIOR_H
#define WARRIOR_H

#include "Character.h"

class Warrior : public Character
{
public:
	Warrior(); //������
	void LevelUp() override; 

	//ĳ����.h�� ���� virtual void LevelUp() = 0; �̰� ����
	// �̰� �����ؼ� ĳ���� Ŭ������ �߻� Ŭ�����̰� �갡 ������ ���� ���ϰ� �ص�

	//ĳ���� Ŭ������ ��� �޾� LevelUP�� �������̵��Ͽ� �ش� ���� ĳ���� ������ ������ ������

	//�̷��� �ϸ� Ŭ���� ��� �޴� �پ��� �������� ������ ������ ���� ���� �����ϰ�
	//�������� ĳ���� Ŭ������ ����� �������̽��� �����Ͽ� �ϰ��� ������� ���� ȣ�� ����
};

#endif // WARRIOR_H
