#pragma once

#include <iostream>

using namespace std;

class Character {
private:
    string name;
    int level;
    int item_num;

public:
    // ������
    Character() : name(""), level(0), item_num(0) {}

    // �̸� ���� �޼ҵ�
    void changeName(const string& newName) ;

    // ���� ���� �޼ҵ�
    void levelUp();

    // ������ �ݱ� �޼ҵ�
    void pickItem();

    // ������ ��� �޼ҵ�
    void useItem();

    // ���� ��� �޼ҵ�
    void printCharacterInfo();

    // �޴� ��� �� ���� �޼ҵ�
    void chooseMenu();
};
