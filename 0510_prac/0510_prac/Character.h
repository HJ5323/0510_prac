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
    // ������
    Character() : name(""), level(0), item_num(0), health (100) {}

    // ĳ���� ���� �޼ҵ�
    void createCharacter(const string& charName);

    // ������ ĳ���� �̸� ���
    void printCharacterName();

    // ĳ���� ���� �޼ҵ�
    void selectCharacter(const string& selectName);

    // �̸� ���� �޼ҵ�
    void changeName(const string& changeN);

    // ���� ���� �޼ҵ�
    void levelUp();

    // ������ �ݱ� �޼ҵ�
    void pickItem();

    // ������ ��� �޼ҵ�
    void useItem();

    // �����ϱ� �޼ҵ�
    void attack(Character& target);
    //void attack(const string& targetName);


    // ü�� ���� �޼ҵ�
    void takeDamage();
    //void takeDamage(const string& targetName);

    // ���� ��� �޼ҵ�
    void printCharacterInfo();

    // ���� ���� �޼ҵ�
    void saveToFile();

    // �޴� ��� �� ���� �޼ҵ�
    void chooseMenu();
};
