//실습 1-1. 
//1. Rectangle 클래스 만들기
//2. 필드(변수) : width, height
//3. 생성자 : width 와 height 설정할 2개의 숫자를 매개변수로 받기
//4. 메소드 : width 와 height를 이용하여 사각형의 넓이를 반환하는 area 메소드 만들기
//5. 객체 생성 시에 width와 height을 사용자에게 입력 받아 생성자로 넘겨주기
//실습 1-1
//1. 실습 1에서 만든 클래스를 다른 클래스 변수에 복사하기(복사 생성자 이용)
//2. 1.에서 복사한 변수의 area()함수 호출해서 넓이 구하기
//3. 실습 1에서 만든 클래스를 기본생성자로 생성된 다른 클래스 변수에 복사하기 (=할당 이용)
//4. 3.에서 보가한 변수의 area()함수 호출해서 넓이 구하기

#include <iostream>

using namespace std;

class Rectangle {
private:
	float width{ 0 };
	float height{ 0 };

public:
	Rectangle(float w, float h) : width(w), height(h) {}

	// 복사 생성자
	Rectangle(const Rectangle& other) : width(other.width), height(other.height) {}

	float area() { return width * height; }
};

int main()
{
	// 1~2번
	Rectangle rect(4, 5);

	Rectangle rect_copy1(rect); // => Rectangle rect_copy1 = rect;

	cout << rect_copy1.area() <<endl;

	// 3~4번
	Rectangle rect2(2, 2);
	rect2 = rect_copy1;

	cout << rect2.area() << endl;
}
