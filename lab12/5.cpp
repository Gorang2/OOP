#include <iostream>

using namespace std;

class Train {
	public:
		Train() {}
		Train(int people) { mPeople = people; }
		~Train() {}
		virtual int station(int takeOff, int takeOn) 
		{
			mPeople = mPeople + takeOn - takeOff;
			if (mPeople < 0 || mPeople > 300)
				return (false);
			return (true);
		}
	protected:
		int mPeople; // 사람 수
};

class Ktx : public Train {
	public:
		Ktx() : Train::Train(0) {}
		Ktx(int people) : Train::Train(people) {}
		~Ktx() {}
// 기차에 사람이 타고 내리는 함수
		int station(int takeOff, int takeOn) override 
		{ return (Train::station(takeOff, takeOn)); }
		int getPeople() { return (mPeople); }
};

int main()
{
	Ktx k;
	int takeOff, takeOn, maxPeople;

	maxPeople = 0;
	for (int i=0; i<5; i++)
	{
		cout << i + 1 << "번역: ";
		cin >> takeOff >> takeOn;
		if (k.station(takeOff, takeOn) == false)
		{
			k.getPeople() < 0 ? cout << "정원미달입니다"<< endl : cout << "정원초과입니다" << endl;
			exit(EXIT_FAILURE) ;
		}
		if (k.getPeople() > maxPeople)
			maxPeople = k.getPeople();
	}
	cout << "가장 많은 사람이 탑승 했을 때의 사람 수: " << maxPeople << endl;
	return 0;
}
