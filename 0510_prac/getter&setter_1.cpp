//실습 2. getter & setter 사용해보기
//1. 실습 1에서 만든 Rectangle 클래스에 getter와 setter 함수를 선언한다.
//2. 필드(변수) : width, height
//3. 메소드 : width와 height를 이용하여 사각형의 넓이를 반환하는 area 메소드 만들기
//4. Rectangle rect(1, 2); // 해당 코드 이용하여 클래스 선언 후 넓이 출력
//5. Setter 함수를 이용하여 사용자에게 입력 받은 width와 height를 Rectangle 클래스 필드에 저장한다.
//6. 넓이와 가로 세로 길이 출력

#include <iostream>
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

	// getter & setter 함수
	float getWidth() const { return this->width; }
	void setWidth(float w) { this->width = w; }

	float getHeight() const { return this->height; }
	void setHeight(float h) { this->height = h; }

	// 넓이를 계산하는 메소드
	float area() { return width * height; }
};

int main()
{
	// 4. Rectangle rect(1, 2); // 해당 코드 이용하여 클래스 선언 후 넓이 출력
	Rectangle rect(1, 2);

	// 넓이 출력
	cout << "넓이는: " << rect.area() << endl;

	// 1~2번
	float newW, newH;

	// 객체 생성
	string input;
	cout << "가로, 세로 길이를 입력하세요. : ";
	getline(cin, input);
	stringstream ss(input);
	ss >> newW >> newH;	

	// setter 함수를 이용하여 width와 height 설정
	rect.setWidth(newW);
	rect.setHeight(newH);

	// 입력받은 값의 넓이와 가로 세로 길이 출력
	cout << "입력 넓이: " << rect.area() << endl;
	cout << "Width: " << rect.getWidth() << endl;
	cout << "Height: " << rect.getHeight() << endl;

	return 0;
}