#include "Character.h"

// ĳ���� ���� �޼ҵ�
void Character::createCharacter(const string& charName) {
    name = charName;

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
                cout << "Name: " << selectName << endl;
                cout << "Level: " << level << endl;
                cout << "Item: " << item_num << endl;
                cout << "Health: " << health << endl;

                int choice;

                while (true) {
                    cout << "---------------------------------------------" << endl;
                    cout << "[ MENU ] -- ����� : "<< name <<"\n";
                    cout << "1. ���� ��       2. ������ �ݱ�    3. ������ ���" << endl;
                    cout << "4. ĳ���� ����   5. �̸� ����      6. ���� " << endl;
                    cout << "0. ����" << endl;
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
                        cout << "[user name]" << endl;
                        fstream file("characters.txt");

                        if (file.is_open()){
                            string line_name;

                            while (getline(file, line_name)) {
                                stringstream ss_name(line_name);
                                string name_in_file;

                                // �� �ٿ��� �̸� �κа� ������ �κ��� ����
                                ss_name >> name_in_file;
                                cout << name_in_file << endl;
                            }
                        string targetName;
                        cout << "������ ĳ������ �̸��� �Է��� �ּ���: ";
                        cin >> targetName;
                        attack(targetName);
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

    if (file.is_open()){
        string line_name;
        bool found = false;
        streampos foundPos;

        // ���Ͽ��� �� �پ� �о� �̸��� ��ġ���� Ȯ���ϰ�, ��ȭ��ȣ ����
        while (getline(file, line_name)){
            stringstream ss_name(line_name);
            string name_in_file, restOfInfo;

            // �� �ٿ��� �̸� �κа� ������ �κ��� ����
            ss_name >> name_in_file;
            getline(ss_name, restOfInfo);

            // �̸��� ã�� ����
            if (name_in_file == name){
                string newName;
                cout << "���ο� �̸��� �Է��� �ּ���: ";
                cin >> newName;
                // ����� �̸��� ������ �κ��� ���ļ� ���ο� �� ����
                ss_name.seekg(0, ios::beg); // ���� ��ġ�� �� ������ �̵�
                file.seekp(foundPos); // ������ �߰��� ��ġ�� �̵�
                file << newName << restOfInfo << endl;

                cout << "ĳ���� �̸� ���� �Ϸ�.\n" << endl;
                name = newName;

                found = true;
                break;
            }
            foundPos = file.tellg(); // ���� ���� �б� ��ġ ���
        }

        if (!found){
            // �̸��� ��ġ�� �ʴ´ٸ� ���� �޼��� ���
            cout << "�̸��� �����ϴ�.\n" << endl;
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
    cout << " level up! ���� ���� : " << level << endl;
    saveToFile();
}

// ������ �ݱ� �޼ҵ�
void Character::pickItem() {
    item_num++;
    cout << " ������ 1���� ȹ��! ���� ������ :  " << item_num << endl;
    saveToFile();
}

// ������ ��� �޼ҵ�
void Character::useItem() {
    if (item_num > 0) {
        item_num--;
        cout << " ������ 1���� ���! ���� ������ :  " << item_num << endl;
        saveToFile();
    }

    else if (item_num <= 0) {
        cout << "Error! �������� �����ϴ�." << endl;
    }
}

// �����ϱ� �޼ҵ�
void Character::attack(const string& targetName) {
    
    // ���Ͽ��� �ش� �̸��� ĳ���͸� ã��
    fstream file("characters.txt");
    if (file.is_open()) {
        string line;
        bool found = false;
        streampos foundPos;

        while (getline(file, line)) {
            stringstream ss(line);
            string name_in_file, restOfInfo;
            ss >> name_in_file;
            getline(ss, restOfInfo);

            if (name_in_file == targetName) {
                cout << "\n" << name << " ��(��)  " << targetName << "��(��) �����Ͽ����ϴ�!" << endl;

                found = true;
                file.close();
                
                takeDamage(targetName);
                break;
            }
        }
        file.close();

        if (!found)   // �ش� �̸��� ĳ���͸� ã�� ���� ���
        {
            cout << "������ ĳ���͸� ã�� �� �����ϴ�." << endl;
        }
    }
}

// ü�� ���� �޼ҵ�
void Character::takeDamage(const string& targetName) {
    name = targetName;

    // ���Ͽ��� �ش� �̸��� ĳ���͸� ã��
    fstream file("characters.txt");
    if (file.is_open()) {
        string line;
        bool found = false;
        streampos foundPos;

        while (getline(file, line)) {
            stringstream ss(line);
            string name_in_file, restOfInfo;
            ss >> name_in_file;

            if (name_in_file == targetName) {

                // ������ ������ �о ĳ���� ��ü�� ����
                getline(ss, restOfInfo);
                stringstream rest_ss(restOfInfo);
                rest_ss >> level >> item_num >> health;

                health -= 10;

                cout << name << "�� ���� ü�� : " << health << "\n" << endl;
                saveToFile();

                found = true;
                file.close();
                
                break;
            }
        }
        file.close();

        if (!found) { // �ش� �̸��� ĳ���͸� ã�� ���� ���
            cout << "������ ĳ���͸� ã�� �� �����ϴ�." << endl;
        }
    }

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

        while (getline(file, line)){
            stringstream ss(line);
            string name_in_file, restOfInfo;

            ss >> name_in_file;
            getline(ss, restOfInfo);

            if (name_in_file == name){
                // ĳ���� ������ ��ġ�� ã�� ���� ������Ʈ
                file.seekg(0, ios::beg);
                file.seekp(foundPos); // �߰��� ��ġ�� �̵�                
                file << name << " " << level << " " << item_num << " " << health << endl;

                cout << name << "�� ĳ���� ���� ����!" << endl;
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

    vector<Character> characters;
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
        cout << "[ MENU ]\n";
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
            string selectName;
            cout << "������ ĳ���� �̸��� �Է��� �ּ���. : ";
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
