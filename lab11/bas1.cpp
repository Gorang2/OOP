#include <iostream>
using namespace std;
class Point {
	private:
		int x;
		int y;
		static int numCreatedObjects;
	public:
		Point() : x(0), y(0) {
		
			numCreatedObjects++;
		}
// int _x 와 int _y를 입력으로 받는 생성자
/*구현*/
		Point(int _x, int _y)
		{
			numCreatedObjects++;
			x = _x;
			y = _y;
		}
		~Point() {
			cout << "Destructed..." << endl;
		}
		void setXY(int _x, int _y) {
			//this-> 사용한 초기화
			/*구현*/
			this->x = _x;
			this->y = _y;
		}
		int getX() const { return x; }
		int getY() const { return y; }
		// *this + pt2 ->
		Point operator+(Point& pt2) {
			/*구현*/
			Point res = Point();
			res.setXY(this->x + pt2.x, this->y + pt2.y);
			return res;
		}
//operator overloading(연산자 오버로딩)
		Point& operator=(Point& pt) {
		/*구현*/
			this -> x = pt.x;
			this -> y = pt.y;
			return *this;
		}
		static int getNumCreatedObject() { return numCreatedObjects; }
		friend void print(const Point& pt);
		friend ostream& operator<<(ostream& cout, Point& pt);
		friend class SpyPoint;
};
	//static 맴버 변수 초기화 (numCreatedObjects)
	/*구현*/
int Point::numCreatedObjects = 0;
	//객체 call by reference시: const로 함수 입력시 const method만 함수에서 사용가능
	// const: 객체 내부의 member data가 상수(변하지 않는다)
void print(const Point& pt) {
		cout << pt.x << ", " << pt.y << endl;
}
	//Point operator+(Point& pt1, Point& pt2){
	// Point result(pt1.getX() + pt2.get(X), pt1.getY() + pt2.getY());
	// return result;
	//}
ostream& operator<<(ostream& cout, Point& pt) {
/*구현*/
	return (cout << pt.x << ", " << pt.y);
}
class SpyPoint {
	public:
//다음과 같이 출력 되도록 hack_all_info함수 구현
//Hacked by SpyPoint
//x: 40
//y: 60
//numCreatedObj.: 10
/*구현*/
		void	hack_all_info(Point& pt)
		{
			cout << "Hacked by SpyPoint" << endl;
			cout << "x: " << pt.x << endl;
			cout << "y: " << pt.y << endl;
			cout << "numCreatedObj : " << pt.numCreatedObjects << endl;
		}
};

int main() {
	Point pt1(1, 2);
	cout << "pt1 : ";
	print(pt1);
	cout << endl;
	// 포인터
	Point* pPt1 = &pt1;
	// pPt1의 값을 통해 getX, getY를 호출하여 출력
	cout << "pt1 : ";
	/*구현*/
	cout << (*pPt1).getX() << ", " << (*pPt1).getY() << endl; 
	// pPt1를 통해 호출 getX, getY를 호출하여 출력
	cout << "pt1 : ";
	/*구현*/
	cout << pPt1->getX() << ", " << pPt1->getY() << endl;
	cout << endl;
	//동적으로 Point* pPt2할당하여 10,20넣은 뒤 ->사용하여 출력(pt1 출력 참고)
	Point *pPt2 = new Point(10, 20);
	/*구현*/
	cout << "pt2 : ";
	cout << pPt2->getX() << ", " << pPt2->getY() << endl;
	/*구현*/
	cout << endl;
	
	//pPt1, pPt2의 메모리 해제
	/*구현*/
	delete pPt2;
	cout << "pt1 NumCreatedObject : ";
	cout << /*구현*/ pt1.getNumCreatedObject() << endl;
	// 연산자 오버로딩
	//pt4 = pt2, pt3값 더하기
	Point pt2 = Point(10, 20);
	Point pt3 = Point(30, 40);
	Point pt4 = pt2 + pt3;
	/*구현*/
	cout << "pt2 : ";
	cout << pt2 << endl;
	cout << "pt3 : ";
	cout << pt3 << endl;
	cout << "pt4 : ";
	cout << pt4 << endl;
	cout << "pt1 NumCreatedObject : ";
	cout << /*구현*/pt1.getNumCreatedObject() << endl << endl;;
	// object array
	Point* ptAry = new Point[5]/*구현*/;
	ptAry[0] = pt1;
	ptAry[1] = pt2;
	ptAry[2] = pt3;
	ptAry[3] = pt4;
	cout << "pt2 NumCreatedObject : ";
	cout << /*구현*/(ptAry[1]).getNumCreatedObject() << endl;
	cout << endl;
	// ptAry 메모리 해제
	/*구현*/
	delete[] ptAry;
	cout << endl;
	// friend class
	SpyPoint spy;
	cout << "pt1 info" << endl;
	spy.hack_all_info(pt1);
	cout << endl;
	/*구현*/
	cout << "pt4 info" << endl;
	spy.hack_all_info(pt4);
	cout << endl;
	/*구현*/
	return 0;
}
