#include <iostream>
#include <string.h>
#include <String>

using namespace std;


struct Point {
	int x;
	int y;
};

class Rectangle {
private:
	Point calRightBottom() {
		Point rightBottom;
		rightBottom.x = rightTop.x;
		rightBottom.y = leftBottom.x;
		return rightBottom;
	}

	Point calLeftTop() {
		Point leftTop;
		leftTop.x = leftBottom.y;
		leftTop.y = rightTop.y;
		return leftTop;
	}

public:
	Point leftTop;
	Point rightTop;
	Point leftBottom;
	Point rightBottom;

	Rectangle(Point rightTop, Point leftBottom) {
		this->rightTop = rightTop;
		this->leftBottom = leftBottom;
		this->leftTop = calLeftTop();
		this->rightBottom = calRightBottom();
	}

	void printRectangleCoordinates() {
		cout << "leftTop = { " << this->leftTop.x << " " << this->leftTop.y << " }" << endl;
		cout << "leftBottom = { " << this->leftBottom.x << " " << this->leftBottom.y << " }" << endl;
		cout << "rightTop = { " << this->rightTop.x << " " << this->rightTop.y << " }" << endl;
		cout << "rightBottom = { " << this->rightBottom.x << " " << this->rightBottom.y << " }" << endl;

	}
};

Point getPointCoordinates();
bool isInRectangle(Point point, Rectangle rectangle);

int main() {
	
	cout << "Enter right top point coordinates of your rectangle" << endl;
	Point rightTop = getPointCoordinates();
	cout << "Enter left bottom point coordinates of your rectangle" << endl;
	Point leftBottom = getPointCoordinates();

	Rectangle rectangle =  Rectangle(rightTop, leftBottom);
	cout << "Your rectangle coordinates is : " << endl; 
	rectangle.printRectangleCoordinates();


	cout << "Create your point, which will be checked on located in rectandle or not." << endl;
	Point userPoint = getPointCoordinates();

	if (isInRectangle(userPoint, rectangle)) cout << "Your point in rectangle" << endl;
	else cout << "Your point is not in rectangle" << endl;

	system("pause");
	return 0;
}

Point getPointCoordinates()
{
	Point point;
	cout << "Enter 'x' of your point" << endl;
	cin >> point.x;
	cout << "Enter 'y' of your point" << endl;
	cin >> point.y;
	return point;
}

bool isInRectangle(Point point, Rectangle rectangle)
{
	if (point.x > rectangle.leftBottom.y && point.x < rectangle.rightTop.x
		&& point.y > rectangle.leftBottom.x && point.y < rectangle.rightTop.y
		) return true;

		return false;
}

