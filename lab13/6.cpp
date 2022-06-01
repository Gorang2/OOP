#include <iostream>

using namespace std;

#define type int
template <typename T>
class CList
{
	public:
		CList():m_Length(0){}
		~CList() {};
		bool IsEmpty()
		{
			if (m_Length == 0)
				return (1);
			return (0);
		}
		bool IsFull()
		{
			if (m_Length == 5)
				return (1);
			return (0);
		}
		void swap(T* a, T* b)
		{
			T tmp = *a;
			*a = *b;
			*b = tmp;
		}
		void sort()
		{
			for (int i=0; i<m_Length - 1; i++)
				for (int j=0; j<m_Length - i - 1; j++)
					if (m_Array[j] > m_Array[j+1])
						swap(&(m_Array[j]), &(m_Array[j+1]));
		}
		void Add(T data)
		{
			if (m_Length == 5)
			{
				cout << "\n\tList is full." << endl;
				return ;
			}
			for (int i=0; i<m_Length; i++)
				if (m_Array[i] == data)
				{
					cout << " 중복된 데이터가 존재합니다." << endl;
					return;
				}
			m_Array[m_Length] = data;
			m_Length++;
			sort();


		}
		void Delete(T data)
		{
			if (m_Length == 0)
			{
				cout << "\n\tList is empty." << endl;
				return ;
			}
			for (int i=0; i<m_Length; i++)
				if (m_Array[i] == data)
					for (int j=i; j<m_Length - 1; j++)
						m_Array[j] = m_Array[j+1];
			m_Length--;
		}

		void Print()
		{
			cout << endl <<  "\t※ Current List" << endl << '\t';
			for (int i=0; i<m_Length; i++)
				cout <<  m_Array[i] << " ";
			cout << endl;
		}
	private:
		T m_Array[5]; // 데이터를 저장할 공간
		int m_Length; // list에 있는 데이터 수
};
int command()
{
	int num;
	cout << "\n\t---- menu ----" << endl;
	cout << "\t1. 리스트 추가" << endl;
	cout << "\t2. 리스트 삭제" << endl;
	cout << "\t3. 리스트 출력" << endl;
	cout << "\t4. 프로그램 종료" << endl;
	cout << "\n\t입력 --> ";
	cin >> num;
	return num;
}

int main()
{
	CList<type> list; // type형으로 list 선언
	type input; // list에 입력 할 데이터
	int com; // 선택한 기능
	while (1)
	{
	       	com = command(); // 기능을 선택
		switch (com)
		{
			case 1: // 추가
				cout << "\n추가할 데이터 : ";
				cin >> input;
				list.Add(input);
				break;
			case 2: // 삭제
				cout << "\n삭제할 데이터 : ";
				cin >> input;
				list.Delete(input);
				break;
			case 3: // 출력
				list.Print();
				break;
			case 4: // 프로그램 종료
				cout << "\n\t프로그램을 종료합니다\n";
				return 0;
				break;
			default:
				break;
		}
	}
       	return 0;
}
