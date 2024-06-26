//실습 1. 클래스 사용해보기
//1. Rectangle 클래스 만들기
//2. 필드(변수) : width, height
//3. 생성자 : width 와 height 설정할 2개의 숫자를 매개변수로 받기
//4. 메소드 : width 와 height를 이용하여 사각형의 넓이를 반환하는 area 메소드 만들기
//5. 객체 생성 시에 width와 height을 사용자에게 입력 받아 생성자로 넘겨주기

#include <iostream>
#include <sstream>

using namespace std;

class Rectangle {
private :
	// 필드
	float width{ 0 };
	float height{ 0 };

public:
	// 생성자
	Rectangle(float w, float h) : width(w), height(h) {}

	// 넓이 계산 메소드
	float area(){ return width * height; }

};


int main()
{
	//float w, h;
	//cout << "가로 길이를 입력하세요. : ";
	//cin >> w;
	//cout << "세로 길이를 입력하세요. : ";
	//cin >> h;

	//Rectangle rec(w, h);

	//cout << "넓이는 : " << rec.area() << endl;

	//return 0;

	float w, h;

	string input;
	cout << "가로, 세로 길이를 입력하세요. : ";
	getline(cin, input);
	stringstream ss(input);
	ss >> w >> h;

	Rectangle rec(w, h);
	cout << "넓이는 : " << rec.area() << endl;
	
	return 0;
}
