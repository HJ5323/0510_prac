//�ǽ� 1. Ŭ���� ����غ���
//1. Rectangle Ŭ���� �����
//2. �ʵ�(����) : width, height
//3. ������ : width �� height ������ 2���� ���ڸ� �Ű������� �ޱ�
//4. �޼ҵ� : width �� height�� �̿��Ͽ� �簢���� ���̸� ��ȯ�ϴ� area �޼ҵ� �����
//5. ��ü ���� �ÿ� width�� height�� ����ڿ��� �Է� �޾� �����ڷ� �Ѱ��ֱ�

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Rectangle {
private :
	float width{ 0 };
	float height{ 0 };

public:
	Rectangle(float w, float h) : width(w), height(h) {}

	float area(){ return width * height; }

};

int main()
{
	//float w, h;
	//cout << "���� ���̸� �Է��ϼ���. : ";
	//cin >> w;
	//cout << "���� ���̸� �Է��ϼ���. : ";
	//cin >> h;

	//Rectangle rec(w, h);

	//cout << "���̴� : " << rec.area() << endl;

	//return 0;

	float w, h;

	string input;
	cout << "����, ���� ���̸� �Է��ϼ���. : ";
	getline(cin, input);
	stringstream ss(input);
	ss >> w >> h;

	Rectangle rec(w, h);
	cout << "���̴� : " << rec.area() << endl;
	
	return 0;
}
Rectangle origin(10, 20); // ���� ��ü ����

Rectangle copy(origin); // => Rectangle copy = origin; // ���� �����ڸ� �̿��� �ٸ� ��ü�� ����

cout << "copy ���̴� : " << copy.area() << endl;

// 3~4��
Rectangle copy2(30, 40); // �⺻ �����ڸ� �̿��Ͽ� ���ο� ��ü ����

copy2 = origin; // �Ҵ� �̿��Ͽ� �� ����

cout << "copy 2 ���̴� : " << copy2.area() << endl;

return 0;