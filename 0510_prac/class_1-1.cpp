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

using namespace std;

class Rectangle {
private:
	float width{ 0 };
	float height{ 0 };

public:
	Rectangle(float w, float h) : width(w), height(h) {}

	// ���� ������
	Rectangle(const Rectangle& other) : width(other.width), height(other.height) {}

	float area() { return width * height; }
};

int main()
{
	// 1~2��
	Rectangle rect(4, 5);

	Rectangle rect_copy1(rect); // => Rectangle rect_copy1 = rect;

	cout << rect_copy1.area() <<endl;

	// 3~4��
	Rectangle rect2(2, 2);
	rect2 = rect_copy1;

	cout << rect2.area() << endl;
}
