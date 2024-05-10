//�ǽ� 1-1. 
//1. Rectangle Ŭ���� �����
//2. �ʵ�(����) : width, height
//3. ������ : width �� height ������ 2���� ���ڸ� �Ű������� �ޱ�
//4. �޼ҵ� : width �� height�� �̿��Ͽ� �簢���� ���̸� ��ȯ�ϴ� area �޼ҵ� �����
//5. ��ü ���� �ÿ� width�� height�� ����ڿ��� �Է� �޾� �����ڷ� �Ѱ��ֱ�
//�ǽ� 1-1
//1. �ǽ� 1���� ���� Ŭ������ �ٸ� Ŭ���� ������ �����ϱ�(���� ������ �̿�)
//2. 1.���� ������ ������ area()�Լ� ȣ���ؼ� ���� ���ϱ�
//3. �ǽ� 1���� ���� Ŭ������ �⺻�����ڷ� ������ �ٸ� Ŭ���� ������ �����ϱ� (=�Ҵ� �̿�)
//4. 3.���� ������ ������ area()�Լ� ȣ���ؼ� ���� ���ϱ�

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Rectangle {
private:
	// �ʵ�
	float width{ 0 };
	float height{ 0 };

public:
	// ������
	Rectangle(float w, float h) : width(w), height(h) {}

	// ���� ������
	Rectangle(const Rectangle& other) : width(other.width), height(other.height) {}

	// ���̸� ����ϴ� �޼ҵ�
	float area() { return width * height; }
};

int main()
{
	// 1~2��
	float w, h;
	
	// ��ü ����
	string input;
	cout << "����, ���� ���̸� �Է��ϼ���. : ";
	getline(cin, input);
	stringstream ss(input);
	ss >> w >> h;

	Rectangle origin(w, h);
	cout << "origin ���̴� : " << origin.area() << endl;

	// ���� �����ڸ� �̿��� �ٸ� ��ü�� ����
	Rectangle copy1(origin); // => Rectangle copy = origin;

	cout << "copy 1 ���̴� : " << copy1.area() << endl;

	// 3~4��
	// �⺻ �����ڷ� ��ü ���� �� �Ҵ�
	Rectangle copy2(30, 40);

	// �Ҵ� �̿��Ͽ� �� ����
	copy2 = copy1;

	cout << "copy 2 ���̴� : " << copy2.area() << endl;

	return 0;
}

//// 1~2��
//// ��ü ����
//Rectangle origin(4, 5);

//// ���� �����ڸ� �̿��� �ٸ� ��ü�� ����
//Rectangle copy1(origin); // => Rectangle copy = origin;

//cout << "copy 1 ���̴� : " << copy1.area() << endl;

//// 3~4��
//// �⺻ �����ڷ� ��ü ���� �� �Ҵ�
//Rectangle copy2(30, 40);

//// �Ҵ� �̿��Ͽ� �� ����
//copy2 = copy1;

//cout << "copy 2 ���̴� : " << copy2.area() << endl;

//return 0;


