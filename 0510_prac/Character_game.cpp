//실습 3. 게임 캐릭터 생성하기
//1. Character라는 클래스 생성
//2. 필드(변수) : name(이름), level(레벨), item_num(아이템 수)
//3. 생성자 : 사용자에게 콘솔로 캐릭터 이름을 입력 받고, 캐릭터 생성하기(이름은 입력 받은 값으로, 레벨, 아이템 수는 0으로 초기화)
//4. 사용자에게 캐릭터를 어떻게 조작할지 입력하게 하기. (0을 입력할 때까지 입력한 번호에 해당하는 작업을 계속하기)
//5. 위 기능은 모두 Character의 메소드로 만들어져 있어야 함
//
//1을 입력하면 이름 변경
//2를 입력하면 level up(level이 1씩 증가)
//3을 입력하면 item 줍기(item 수가 1씩 증가)
//4를 입력하면 item 사용(item 수가 1씩 감소)
//5를 입력하면 이름, level, item을 콘솔에 출력하기
//0을 입력하면 게임 종료

#include "Character.h"

int main() {
    Character character;

    // 캐릭터 이름 입력 받기
    string charName;
    cout << "Enter character name: ";
    cin >> charName;
    character.changeName(charName);

    // 메뉴 선택 출력
    character.chooseMenu();

    return 0;
}