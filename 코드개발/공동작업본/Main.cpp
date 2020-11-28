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
/*<결과창>
곰 (체력:200 공격력:20 방어력:30)이 소환 되었습니다.
기본 공격
스킬 공격

숲을 지키겠다.
다크엘프(체력:150 공격력:25 방어력:10)가 소환 되었습니다.
기본 공격
다크엘프의 어둠화살!

숲을 지키겠다.
하이엘프 (체력:150 공격력:25 방어력:10)가 소환 되었습니다.
기본 공격
하이엘프의 신성한 빛!

saveFile is created
체력:100, 공격력:60, 방어력:60 (초기에 정해둔 플레이어 파라미터)
hp, ark, def 입력하여 입력받은 값이 체력: 공격력: 방어력: 순서로 나온다. */
