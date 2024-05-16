#include "Character.h"

// 캐릭터 생성 메소드
void Character::createCharacter(const string& charName) {
    name = charName;

    // 초기화
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

            // 한 줄에서 이름 추출
            ss_name >> name_in_file;

            // 이름이 겹치는 경우 오류 메세지 출력 후 함수 종료
            if (charName == name_in_file) {
                cout << "이미 있는 캐릭터입니다.\n" << endl;
                found = true;
                break;
            }

            foundPos = file.tellg(); // 현재 파일 읽기 위치 기억
        }

        if (!found) {
            file.clear(); // EOF 상태 초기화
            file.seekp(0, ios::end); // 파일 끝으로 이동
            file << name << ' ' << level << ' ' << item_num << ' ' << health << endl;
            cout << "캐릭터를 생성했습니다.\n" << endl;
        }
    }

    else {
        cout << "파일을 열 수 없습니다.\n" << endl;
    }
    file.close();
}

// 생성된 캐릭터 이름 출력
void Character::printCharacterName() {
    cout << "[ User Name ]" << endl;
    fstream file("characters.txt");

    if (file.is_open()) {
        string line_name;

        while (getline(file, line_name)) {
            stringstream ss_name(line_name);
            string name_in_file;

            // 한 줄에서 이름 부분과 나머지 부분을 추출
            ss_name >> name_in_file;
            cout << " " << name_in_file << endl;
        }
    }
}

// 캐릭터 선택 메소드
void Character::selectCharacter(const string& selectName) {
    name = selectName;

    fstream file("characters.txt");

    if (file.is_open()) {
        string line;

        // 파일에서 한 줄씩 읽어 이름이 일치하는 캐릭터 데이터 찾기
        while (getline(file, line)) {
            stringstream ss(line);
            string name_in_file, restOfInfo;

            // 한 줄에서 이름 부분과 나머지 부분을 추출
            ss >> name_in_file;
            getline(ss, restOfInfo);

            // 이름이 일치하는 경우
            if (name_in_file == selectName) {
                // 나머지 부분을 stringstream으로 변환하여 데이터 추출
                stringstream rest_ss(restOfInfo);
                rest_ss >> level >> item_num >> health;

                // 캐릭터 정보 출력
                cout << "[ select ]" << endl;
                cout << "Name: " << selectName << endl;
                cout << "Level: " << level << endl;
                cout << "Item: " << item_num << endl;
                cout << "Health: " << health << endl;

                int choice;

                while (true) {
                    cout << "---------------------------------------------" << endl;
                    cout << "[ MENU ] -- 사용자 : " << name << endl;
                    cout << "1. 레벨 업       2. 아이템 줍기    3. 아이템 사용" << endl;
                    cout << "4. 캐릭터 정보   5. 이름 변경      6. 공격 " << endl;
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
                            cout << "\n공격할 캐릭터의 이름을 입력해 주세요: ";
                            cin >> targetName;

                            // 파일에서 해당 이름의 캐릭터를 찾기
                            fstream file("characters.txt");
                            if (file.is_open()) {
                                string line;
                                bool found = false;

                                while (getline(file, line)) {
                                    stringstream ss(line);
                                    string name_in_file, restOfInfo;
                                    ss >> name_in_file;

                                    if (name_in_file == targetName) {
                                        // 해당 이름의 캐릭터를 찾았으면 캐릭터 객체 생성
                                        Character target;
                                        target.name = targetName;
                                        // 나머지 정보를 읽어서 캐릭터 객체에 저장
                                        getline(ss, restOfInfo);
                                        stringstream rest_ss(restOfInfo);
                                        rest_ss >> target.level >> target.item_num >> target.health;
                                        // 캐릭터를 공격
                                        attack(target);
                                        found = true;
                                        file.close();
                                        break;
                                    }
                                }
                                file.close();

                                if (!found)   // 해당 이름의 캐릭터를 찾지 못한 경우
                                {
                                    cout << "공격할 캐릭터를 찾을 수 없습니다." << endl;
                                }
                            }
                            break;
                        }
                    }

                    case 0:
                        return;

                    default:
                        cout << "다시 입력해 주세요.\n\n";
                    }
                }
                return;
            }
        }
        // 반복이 끝나면 해당 이름의 캐릭터가 없는 것이므로 오류 메시지 출력
        cout << "해당 이름의 캐릭터가 없습니다." << endl;
    }

    else {
        cout << "파일을 열 수 없습니다." << endl;
    }
    file.close();
}

// 이름 변경 메소드
void Character::changeName(const string& changeN) {
    name = changeN;

    fstream file("characters.txt");

    if (file.is_open()) {
        string line_name;
        bool found = false;
        streampos foundPos;

        // 파일에서 한 줄씩 읽어 이름이 겹치는지 확인하고, 이름 수정
        while (getline(file, line_name)) {
            stringstream ss_name(line_name);
            string name_in_file, restOfInfo;

            // 한 줄에서 이름 부분과 나머지 부분을 추출
            ss_name >> name_in_file;
            getline(ss_name, restOfInfo);

            // 이름을 찾고 변경
            if (name_in_file == name) {
                string newName;
                cout << "새로운 이름을 입력해 주세요: ";
                cin >> newName;
                // 변경된 이름과 나머지 부분을 합쳐서 새로운 줄 생성
                ss_name.seekg(0, ios::beg); // 현재 위치를 맨 앞으로 이동
                file.seekp(foundPos); // 이전에 발견한 위치로 이동
                file << newName << restOfInfo << endl;

                cout << "캐릭터 이름 변경 완료." << endl;
                name = newName;

                found = true;
                break;
            }
            foundPos = file.tellg(); // 현재 파일 읽기 위치 기억
        }

    }

    else {
        cout << "파일을 열 수 없습니다.\n" << endl;
    }
    file.close();
}

// 레벨 증가 메소드
void Character::levelUp() {
    level++;
    cout << "  level up! 현재 " << name <<"의 레벨 : " << level << endl;
    saveToFile();
}

// 아이템 줍기 메소드
void Character::pickItem() {
    item_num++;
    cout << "  아이템 1개를 획득! " << name << "의 남은 아이템 :  " << item_num << endl;
    saveToFile();
}

// 아이템 사용 메소드
void Character::useItem() {
    if (item_num > 0) {
        item_num--;
        cout << "  아이템 1개를 사용! " << name << "의 남은 아이템 :  " << item_num << endl;
        saveToFile();
    }

    else if (item_num <= 0) {
        cout << "Error! 아이템이 없습니다." << endl;
    }
}

// 공격하기 메소드
void Character::attack(Character& target) {
    cout << name << "이(가)  " << target.name << "을(를) 공격하였습니다!\n" << endl;
    target.takeDamage();
}

// 체력 감소 메소드
void Character::takeDamage() {
    health -= 10;
    cout << "  " << name << "의 남은 체력 : " << health << endl;
    saveToFile();

    if (health <= 0) {
        cout << "Error! 체력이 없습니다." << endl;
    }
}

// 파일 저장 메소드
void Character::saveToFile() {

    fstream file("characters.txt", ios::in | ios::out);

    // 파일에서 한 줄씩 읽어 이름이 겹치는지 확인하고, 캐릭터 정보 수정
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
                // 캐릭터 정보가 위치를 찾아 정보 업데이트
                file.seekg(0, ios::beg);
                file.seekp(foundPos); // 발견한 위치로 이동                
                file << name << " " << level << " " << item_num << " " << health << endl;

                cout << "  " << name << "의 캐릭터 정보 저장!" << endl;
                found = true;
                break;
            }
            foundPos = file.tellg(); // 현재 파일 읽기 위치 기억
        }
    }

    else {
        cout << "파일을 열 수 없습니다." << endl;
    }
    file.close();
}

// 상태 출력 메소드
void Character::printCharacterInfo() {

    ifstream file("characters.txt");

    if (file.is_open()) {

        string line;

        // 파일에서 한 줄씩 읽어 이름이 일치하는 캐릭터 데이터 찾기
        while (getline(file, line)) {
            stringstream ss(line);
            string name_in_file, restOfInfo;

            // 한 줄에서 이름 부분과 나머지 부분을 추출
            ss >> name_in_file;
            getline(ss, restOfInfo);

            // 이름이 일치하는 경우
            if (name_in_file == name) {
                // 나머지 부분을 stringstream으로 변환하여 데이터 추출
                stringstream rest_ss(restOfInfo);
                rest_ss >> level >> item_num >> health;

                // 캐릭터 정보 출력
                cout << "[ Info ]" << endl;
                cout << "Name: " << name << endl;
                cout << "Level: " << level << endl;
                cout << "Item: " << item_num << endl;
                cout << "Health: " << health << endl;
            }
        }
    }

    else {
        cout << "파일을 열 수 없습니다.\n" << endl;
    }
    file.close();
}

// 메뉴 출력 및 선택 메소드
void Character::chooseMenu() {
    int choice;

    while (true) {
        cout << "---------------------------------------------" << endl;
        cout << "[ Start MENU ]\n";
        cout << "1. 캐릭터 생성    2. 캐릭터 선택     0. 종료 " << endl;
        cout << "Choose a Menu: ";
        cin >> choice;
        cout << "\n";

        switch (choice) {
        case 1: {
            string charName;
            cout << "생성할 캐릭터 이름을 입력해 주세요: ";
            cin >> charName;
            createCharacter(charName);
            break;
        }

        case 2: {
            printCharacterName();
            string selectName;
            cout << "\n선택할 캐릭터 이름을 입력해 주세요. : ";
            cin >> selectName;
            selectCharacter(selectName);
            break;
        }

        case 0:
            return;

        default:
            cout << "다시 입력해 주세요.\n\n";
        }
    }
}