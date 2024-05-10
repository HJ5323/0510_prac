#include "Character.h"

// 아이템 사용 메소드
void Character::useItem() {
    if (item_num > 0)
        item_num--;
    cout << " item - 1" << endl;
    cout << "---------------------------------------------" << "\n" << endl;
}