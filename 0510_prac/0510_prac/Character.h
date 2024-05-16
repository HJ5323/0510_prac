#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Character {
private:
    string name;
    int level;
    int item_num;
    int health;

public:
    // 생성자
    Character() : name(""), level(0), item_num(0), health (100) {}

    // 캐릭터 생성 메소드
    void createCharacter(const string& charName);

    // 생성된 캐릭터 이름 출력
    void printCharacterName();

    // 캐릭터 선택 메소드
    void selectCharacter(const string& selectName);

    // 이름 변경 메소드
    void changeName(const string& changeN);

    // 레벨 증가 메소드
    void levelUp();

    // 아이템 줍기 메소드
    void pickItem();

    // 아이템 사용 메소드
    void useItem();

    // 공격하기 메소드
    void attack(Character& target);
    //void attack(const string& targetName);


    // 체력 감소 메소드
    void takeDamage();
    //void takeDamage(const string& targetName);

    // 상태 출력 메소드
    void printCharacterInfo();

    // 파일 저장 메소드
    void saveToFile();

    // 메뉴 출력 및 선택 메소드
    void chooseMenu();
};
