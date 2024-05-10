#pragma once

#include <iostream>

using namespace std;

class Character {
private:
    string name;
    int level;
    int item_num;

public:
    // 생성자
    Character() : name(""), level(0), item_num(0) {}

    // 이름 변경 메소드
    void changeName(const string& newName) ;

    // 레벨 증가 메소드
    void levelUp();

    // 아이템 줍기 메소드
    void pickItem();

    // 아이템 사용 메소드
    void useItem();

    // 상태 출력 메소드
    void printCharacterInfo();

    // 메뉴 출력 및 선택 메소드
    void chooseMenu();
};
