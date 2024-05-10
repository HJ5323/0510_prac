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
#include <string>
#include <sstream>

using namespace std;

class Rectangle {
private:
	// 필드
	float width{ 0 };
	float height{ 0 };

public:
	// 생성자
	Rectangle(float w, float h) : width(w), height(h) {}

	// 복사 생성자
	Rectangle(const Rectangle& other) : width(other.width), height(other.height) {}

	// 넓이를 계산하는 메소드
	float area() { return width * height; }
};

int main()
{
	// 1~2번
	float w, h;
	
	// 객체 생성
	string input;
	cout << "가로, 세로 길이를 입력하세요. : ";
	getline(cin, input);
	stringstream ss(input);
	ss >> w >> h;

	Rectangle origin(w, h);
	cout << "origin 넓이는 : " << origin.area() << endl;

	// 복사 생성자를 이용해 다른 객체에 복사
	Rectangle copy1(origin); // => Rectangle copy = origin;

	cout << "copy 1 넓이는 : " << copy1.area() << endl;

	// 3~4번
	// 기본 생성자로 객체 생성 후 할당
	Rectangle copy2(30, 40);

	// 할당 이용하여 값 복사
	copy2 = copy1;

	cout << "copy 2 넓이는 : " << copy2.area() << endl;

	return 0;
}

//// 1~2번
//// 객체 생성
//Rectangle origin(4, 5);

//// 복사 생성자를 이용해 다른 객체에 복사
//Rectangle copy1(origin); // => Rectangle copy = origin;

//cout << "copy 1 넓이는 : " << copy1.area() << endl;

//// 3~4번
//// 기본 생성자로 객체 생성 후 할당
//Rectangle copy2(30, 40);

//// 할당 이용하여 값 복사
//copy2 = copy1;

//cout << "copy 2 넓이는 : " << copy2.area() << endl;

//return 0;


