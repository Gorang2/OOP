#pragma once

#include <string>
using namespace std;
// 함수 오버로딩: int sum(int x, int y),
// double sum(double x, double y)
// float sum(float x, float y, float z)
// 함수 오버라이딩 (상속의 특수한 경우 사용)
//void Text::append(string _extra)
//void Fancy::append(string _extra)
class Text {
	private:
		string text;
	public:
		Text(string _t);
		virtual string get();
/*구현*/ //get()함수 virtual 로 구현
		virtual void append(string _extra);
};

