#include "Character.h"

// ���� ��� �޼ҵ�
void Character::printCharacterInfo() {
    cout << "< " << name << " info >" << endl;
    cout << "Name: " << name << endl;
    cout << "Level: " << level << endl;
    cout << "Item: " << item_num << endl;
    cout << "---------------------------------------------" << "\n" << endl;
}