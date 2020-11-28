#pragma once
#include "Monster.h"
#include<iostream>

using namespace std;

class Elf : public Monster
{
	int m_Health;
	int m_Ark;
	int m_Def;

public:
	Elf (int hp= 0,  int ark= 0, int def= 0 ) :m_Health(hp), m_Ark(ark), m_Def(def)
	{

	}

	~Elf()
	{

	}

	virtual Monster* clone()
	{
		return new Elf(m_Health, m_Ark, m_Def);
	}

	virtual void hi()
	{
		cout << "숲을 지키겠다." << endl;
	}

};
