#include "Character.h"

// ������ ��� �޼ҵ�
void Character::useItem() {
    if (item_num > 0)
        item_num--;
    cout << " item - 1" << endl;
    cout << "---------------------------------------------" << "\n" << endl;
}