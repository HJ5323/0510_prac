#include "Character.h"

// 상태 출력 메소드
void Character::printCharacterInfo() {
    cout << "< " << name << " info >" << endl;
    cout << "Name: " << name << endl;
    cout << "Level: " << level << endl;
    cout << "Item: " << item_num << endl;
    cout << "---------------------------------------------" << "\n" << endl;
}