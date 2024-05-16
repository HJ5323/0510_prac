#include "Character.h"

// ĳ���� ���� �޼ҵ�
void Character::createCharacter(const string& charName) {
    name = charName;

    // �ʱ�ȭ
    level = 0;
    item_num = 0;
    health = 100;

    fstream file("characters.txt", ios::in | ios::out);

    if (file.is_open())
    {
        string line_name;
        bool found = false;
        streampos foundPos;

        while (getline(file, line_name)) {

            stringstream ss_name(line_name);
            string name_in_file;

            // �� �ٿ��� �̸� ����
            ss_name >> name_in_file;

            // �̸��� ��ġ�� ��� ���� �޼��� ��� �� �Լ� ����
            if (charName == name_in_file) {
                cout << "�̹� �ִ� ĳ�����Դϴ�.\n" << endl;
                found = true;
                break;
            }

            foundPos = file.tellg(); // ���� ���� �б� ��ġ ���
        }

        if (!found) {
            file.clear(); // EOF ���� �ʱ�ȭ
            file.seekp(0, ios::end); // ���� ������ �̵�
            file << name << ' ' << level << ' ' << item_num << ' ' << health << endl;
            cout << "ĳ���͸� �����߽��ϴ�.\n" << endl;
        }
    }

    else {
        cout << "������ �� �� �����ϴ�.\n" << endl;
    }
    file.close();
}

// ������ ĳ���� �̸� ���
void Character::printCharacterName() {
    cout << "[ User Name ]" << endl;
    fstream file("characters.txt");

    if (file.is_open()) {
        string line_name;

        while (getline(file, line_name)) {
            stringstream ss_name(line_name);
            string name_in_file;

            // �� �ٿ��� �̸� �κа� ������ �κ��� ����
            ss_name >> name_in_file;
            cout << " " << name_in_file << endl;
        }
    }
}

// ĳ���� ���� �޼ҵ�
void Character::selectCharacter(const string& selectName) {
    name = selectName;

    fstream file("characters.txt");

    if (file.is_open()) {
        string line;

        // ���Ͽ��� �� �پ� �о� �̸��� ��ġ�ϴ� ĳ���� ������ ã��
        while (getline(file, line)) {
            stringstream ss(line);
            string name_in_file, restOfInfo;

            // �� �ٿ��� �̸� �κа� ������ �κ��� ����
            ss >> name_in_file;
            getline(ss, restOfInfo);

            // �̸��� ��ġ�ϴ� ���
            if (name_in_file == selectName) {
                // ������ �κ��� stringstream���� ��ȯ�Ͽ� ������ ����
                stringstream rest_ss(restOfInfo);
                rest_ss >> level >> item_num >> health;

                // ĳ���� ���� ���
                cout << "[ select ]" << endl;
                cout << "Name: " << selectName << endl;
                cout << "Level: " << level << endl;
                cout << "Item: " << item_num << endl;
                cout << "Health: " << health << endl;

                int choice;

                while (true) {
                    cout << "---------------------------------------------" << endl;
                    cout << "[ MENU ] -- ����� : " << name << endl;
                    cout << "1. ���� ��       2. ������ �ݱ�    3. ������ ���" << endl;
                    cout << "4. ĳ���� ����   5. �̸� ����      6. ���� " << endl;
                    cout << "0. Start MENU" << endl;
                    cout << "Choose a Menu: ";
                    cin >> choice;
                    cout << "\n";

                    switch (choice) {

                    case 1:
                        levelUp();
                        break;

                    case 2:
                        pickItem();
                        break;

                    case 3:
                        useItem();
                        break;

                    case 4:
                        printCharacterInfo();
                        break;

                    case 5: {
                        string changeN;
                        changeN = name;
                        changeName(changeN);
                        break;
                    }

                    case 6: {
                        printCharacterName();

                        fstream file("characters.txt");

                        if (file.is_open()) {
                            string line_name;

                            string targetName;
                            cout << "\n������ ĳ������ �̸��� �Է��� �ּ���: ";
                            cin >> targetName;

                            // ���Ͽ��� �ش� �̸��� ĳ���͸� ã��
                            fstream file("characters.txt");
                            if (file.is_open()) {
                                string line;
                                bool found = false;

                                while (getline(file, line)) {
                                    stringstream ss(line);
                                    string name_in_file, restOfInfo;
                                    ss >> name_in_file;

                                    if (name_in_file == targetName) {
                                        // �ش� �̸��� ĳ���͸� ã������ ĳ���� ��ü ����
                                        Character target;
                                        target.name = targetName;
                                        // ������ ������ �о ĳ���� ��ü�� ����
                                        getline(ss, restOfInfo);
                                        stringstream rest_ss(restOfInfo);
                                        rest_ss >> target.level >> target.item_num >> target.health;
                                        // ĳ���͸� ����
                                        attack(target);
                                        found = true;
                                        file.close();
                                        break;
                                    }
                                }
                                file.close();

                                if (!found)   // �ش� �̸��� ĳ���͸� ã�� ���� ���
                                {
                                    cout << "������ ĳ���͸� ã�� �� �����ϴ�." << endl;
                                }
                            }
                            break;
                        }
                    }

                    case 0:
                        return;

                    default:
                        cout << "�ٽ� �Է��� �ּ���.\n\n";
                    }
                }
                return;
            }
        }
        // �ݺ��� ������ �ش� �̸��� ĳ���Ͱ� ���� ���̹Ƿ� ���� �޽��� ���
        cout << "�ش� �̸��� ĳ���Ͱ� �����ϴ�." << endl;
    }

    else {
        cout << "������ �� �� �����ϴ�." << endl;
    }
    file.close();
}

// �̸� ���� �޼ҵ�
void Character::changeName(const string& changeN) {
    name = changeN;

    fstream file("characters.txt");

    if (file.is_open()) {
        string line_name;
        bool found = false;
        streampos foundPos;

        // ���Ͽ��� �� �پ� �о� �̸��� ��ġ���� Ȯ���ϰ�, �̸� ����
        while (getline(file, line_name)) {
            stringstream ss_name(line_name);
            string name_in_file, restOfInfo;

            // �� �ٿ��� �̸� �κа� ������ �κ��� ����
            ss_name >> name_in_file;
            getline(ss_name, restOfInfo);

            // �̸��� ã�� ����
            if (name_in_file == name) {
                string newName;
                cout << "���ο� �̸��� �Է��� �ּ���: ";
                cin >> newName;
                // ����� �̸��� ������ �κ��� ���ļ� ���ο� �� ����
                ss_name.seekg(0, ios::beg); // ���� ��ġ�� �� ������ �̵�
                file.seekp(foundPos); // ������ �߰��� ��ġ�� �̵�
                file << newName << restOfInfo << endl;

                cout << "ĳ���� �̸� ���� �Ϸ�." << endl;
                name = newName;

                found = true;
                break;
            }
            foundPos = file.tellg(); // ���� ���� �б� ��ġ ���
        }

    }

    else {
        cout << "������ �� �� �����ϴ�.\n" << endl;
    }
    file.close();
}

// ���� ���� �޼ҵ�
void Character::levelUp() {
    level++;
    cout << "  level up! ���� " << name <<"�� ���� : " << level << endl;
    saveToFile();
}

// ������ �ݱ� �޼ҵ�
void Character::pickItem() {
    item_num++;
    cout << "  ������ 1���� ȹ��! " << name << "�� ���� ������ :  " << item_num << endl;
    saveToFile();
}

// ������ ��� �޼ҵ�
void Character::useItem() {
    if (item_num > 0) {
        item_num--;
        cout << "  ������ 1���� ���! " << name << "�� ���� ������ :  " << item_num << endl;
        saveToFile();
    }

    else if (item_num <= 0) {
        cout << "Error! �������� �����ϴ�." << endl;
    }
}

// �����ϱ� �޼ҵ�
void Character::attack(Character& target) {
    cout << name << "��(��)  " << target.name << "��(��) �����Ͽ����ϴ�!\n" << endl;
    target.takeDamage();
}

// ü�� ���� �޼ҵ�
void Character::takeDamage() {
    health -= 10;
    cout << "  " << name << "�� ���� ü�� : " << health << endl;
    saveToFile();

    if (health <= 0) {
        cout << "Error! ü���� �����ϴ�." << endl;
    }
}

// ���� ���� �޼ҵ�
void Character::saveToFile() {

    fstream file("characters.txt", ios::in | ios::out);

    // ���Ͽ��� �� �پ� �о� �̸��� ��ġ���� Ȯ���ϰ�, ĳ���� ���� ����
    if (file.is_open()) {

        string line;
        bool found = false;
        streampos foundPos;

        while (getline(file, line)) {
            stringstream ss(line);
            string name_in_file, restOfInfo;

            ss >> name_in_file;
            getline(ss, restOfInfo);

            if (name_in_file == name) {
                // ĳ���� ������ ��ġ�� ã�� ���� ������Ʈ
                file.seekg(0, ios::beg);
                file.seekp(foundPos); // �߰��� ��ġ�� �̵�                
                file << name << " " << level << " " << item_num << " " << health << endl;

                cout << "  " << name << "�� ĳ���� ���� ����!" << endl;
                found = true;
                break;
            }
            foundPos = file.tellg(); // ���� ���� �б� ��ġ ���
        }
    }

    else {
        cout << "������ �� �� �����ϴ�." << endl;
    }
    file.close();
}

// ���� ��� �޼ҵ�
void Character::printCharacterInfo() {

    ifstream file("characters.txt");

    if (file.is_open()) {

        string line;

        // ���Ͽ��� �� �پ� �о� �̸��� ��ġ�ϴ� ĳ���� ������ ã��
        while (getline(file, line)) {
            stringstream ss(line);
            string name_in_file, restOfInfo;

            // �� �ٿ��� �̸� �κа� ������ �κ��� ����
            ss >> name_in_file;
            getline(ss, restOfInfo);

            // �̸��� ��ġ�ϴ� ���
            if (name_in_file == name) {
                // ������ �κ��� stringstream���� ��ȯ�Ͽ� ������ ����
                stringstream rest_ss(restOfInfo);
                rest_ss >> level >> item_num >> health;

                // ĳ���� ���� ���
                cout << "[ Info ]" << endl;
                cout << "Name: " << name << endl;
                cout << "Level: " << level << endl;
                cout << "Item: " << item_num << endl;
                cout << "Health: " << health << endl;
            }
        }
    }

    else {
        cout << "������ �� �� �����ϴ�.\n" << endl;
    }
    file.close();
}

// �޴� ��� �� ���� �޼ҵ�
void Character::chooseMenu() {
    int choice;

    while (true) {
        cout << "---------------------------------------------" << endl;
        cout << "[ Start MENU ]\n";
        cout << "1. ĳ���� ����    2. ĳ���� ����     0. ���� " << endl;
        cout << "Choose a Menu: ";
        cin >> choice;
        cout << "\n";

        switch (choice) {
        case 1: {
            string charName;
            cout << "������ ĳ���� �̸��� �Է��� �ּ���: ";
            cin >> charName;
            createCharacter(charName);
            break;
        }

        case 2: {
            printCharacterName();
            string selectName;
            cout << "\n������ ĳ���� �̸��� �Է��� �ּ���. : ";
            cin >> selectName;
            selectCharacter(selectName);
            break;
        }

        case 0:
            return;

        default:
            cout << "�ٽ� �Է��� �ּ���.\n\n";
        }
    }
}