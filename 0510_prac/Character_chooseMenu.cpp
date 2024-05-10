#include "Character.h"

// 메뉴 출력 및 선택 메소드
void Character::chooseMenu() {
    int choice;

    while (true) {
        cout << "\n[ MENU ]\n";
        cout << "1. Change Name   2. Level Up         3. Pick Item " << endl;
        cout << "4. Use Item      5. Character Info   0. Exit" << endl;
        cout << "Choose a Menu: ";
        cin >> choice;
        cout << "\n";

        switch (choice) {
        case 1: {
            string newName;
            cout << "Enter new name: ";
            cin >> newName;
            changeName(newName);
            cout << " change complete!" << endl;
            cout << "---------------------------------------------" << "\n" << endl;
            break;
        }

        case 2:
            levelUp();
            break;

        case 3:
            pickItem();
            break;

        case 4:
            useItem();
            break;

        case 5:
            printCharacterInfo();
            break;

        case 0:
            return;

        default:
            cout << "Please try again.\n\n";
        }
    }
}