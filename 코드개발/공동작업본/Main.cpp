#include "Monster.h"
#include "Spawner.h"
#include "Bear.h"
#include "DarkElf.h"
#include "HighElf.h"
#include "Player.h"
#include "save.h"

#include <iostream>

using namespace std;


int main(int argc, char const* argv[])

{
	Monster* bearPrototype = new Bear(200, 20, 30);
	Spawner* bearSpawner = new Spawner(bearPrototype);
	Monster* bear = bearSpawner->spawnMonster();

	bear->hi();
	bear->MobAttack(); 
	bear->MobSkill();//Bear형 몬스터 객체를 프로토타입으로 만들어 생성하고 hi(), MobAttack(), MobSkill() 함수 작동

	Monster* darkelfPrototype = new DarkElf(150, 25, 10);
	Spawner* darkelfSpawner = new Spawner(darkelfPrototype);
	Monster* darkelf = darkelfSpawner->spawnMonster();

	darkelf->hi();
	darkelf->MobAttack();
	darkelf->MobSkill(); //DarkElf형 몬스터 객체를 프로토타입으로 만들어 생성하고 hi(), MobAttack(), MobSkill() 함수 작동

	Monster* highelfPrototype = new HighElf(150, 30, 10);
	Spawner* highelfSpawner = new Spawner(highelfPrototype);
	Monster* highelf = highelfSpawner->spawnMonster();

	highelf->hi();
	highelf->MobAttack();
	highelf->MobSkill(); //HighElf형 몬스터 객체를 프로토타입으로 만들어 생성하고 hi(), MobAttack(), MobSkill() 함수 작동

	saveFile* saveFileSingleton = saveFile::callSaveFile();

	Player player(100, 60, 60);
	saveFileSingleton->writingFile(player);
	saveFileSingleton->readingFile(player);
	cout << "체력: " << player.getHealth() << ", 공격력: " << player.getArk() << ", 방어력: " << player.getDef() << endl;

	while (1)
	{
		int hp, ark, def;
		cout << "hp input: ";
		cin >> hp;
		cout << "ark input: ";
		cin >> ark;
		cout << "def input: ";
		cin >> def;
		player.setHealth(hp);
		player.setArk(ark);
		player.setDef(def);
		saveFileSingleton->writingFile(player);
		saveFileSingleton->readingFile(player);
		cout << "체력: " << player.getHealth() << ", 공격력: " << player.getArk() << ", 방어력: " << player.getDef() << endl;
	}

}
