//�ǽ� 2. getter & setter ����غ���
//1. �ǽ� 1���� ���� Rectangle Ŭ������ getter�� setter �Լ��� �����Ѵ�.
//2. �ʵ�(����) : width, height
//3. �޼ҵ� : width�� height�� �̿��Ͽ� �簢���� ���̸� ��ȯ�ϴ� area �޼ҵ� �����
//4. Rectangle rect(1, 2); // �ش� �ڵ� �̿��Ͽ� Ŭ���� ���� �� ���� ���
//5. Setter �Լ��� �̿��Ͽ� ����ڿ��� �Է� ���� width�� height�� Rectangle Ŭ���� �ʵ忡 �����Ѵ�.
//6. ���̿� ���� ���� ���� ���

#include <iostream>
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

	// getter & setter �Լ�
	float getWidth() const { return this->width; }
	void setWidth(float w) { this->width = w; }

	float getHeight() const { return this->height; }
	void setHeight(float h) { this->height = h; }

	// ���̸� ����ϴ� �޼ҵ�
	float area() { return width * height; }
};

int main()
{
	// 4. Rectangle rect(1, 2); // �ش� �ڵ� �̿��Ͽ� Ŭ���� ���� �� ���� ���
	Rectangle rect(1, 2);

	// ���� ���
	cout << "���̴�: " << rect.area() << endl;

	// 1~2��
	float newW, newH;

	// ��ü ����
	string input;
	cout << "����, ���� ���̸� �Է��ϼ���. : ";
	getline(cin, input);
	stringstream ss(input);
	ss >> newW >> newH;	

	// setter �Լ��� �̿��Ͽ� width�� height ����
	rect.setWidth(newW);
	rect.setHeight(newH);

	// �Է¹��� ���� ���̿� ���� ���� ���� ���
	std::cout << "�Է� ����: " << rect.area() << std::endl;
	std::cout << "Width: " << rect.getWidth() << std::endl;
	std::cout << "Height: " << rect.getHeight() << std::endl;

	return 0;
}