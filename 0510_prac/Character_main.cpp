//�ǽ� 3. ���� ĳ���� �����ϱ�
//1. Character��� Ŭ���� ����
//2. �ʵ�(����) : name(�̸�), level(����), item_num(������ ��)
//3. ������ : ����ڿ��� �ַܼ� ĳ���� �̸��� �Է� �ް�, ĳ���� �����ϱ�(�̸��� �Է� ���� ������, ����, ������ ���� 0���� �ʱ�ȭ)
//4. ����ڿ��� ĳ���͸� ��� �������� �Է��ϰ� �ϱ�. (0�� �Է��� ������ �Է��� ��ȣ�� �ش��ϴ� �۾��� ����ϱ�)
//5. �� ����� ��� Character�� �޼ҵ�� ������� �־�� ��
//
//1�� �Է��ϸ� �̸� ����
//2�� �Է��ϸ� level up(level�� 1�� ����)
//3�� �Է��ϸ� item �ݱ�(item ���� 1�� ����)
//4�� �Է��ϸ� item ���(item ���� 1�� ����)
//5�� �Է��ϸ� �̸�, level, item�� �ֿܼ� ����ϱ�
//0�� �Է��ϸ� ���� ����

#include "Character.h"

int main() {
    Character character;

    // ĳ���� �̸� �Է� �ޱ�
    string charName;
    cout << "Enter character name: ";
    cin >> charName;
    character.changeName(charName);

    // �޴� ���� ���
    character.chooseMenu();

    return 0;
}