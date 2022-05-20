#include <iostream>
#include <string>
#include <vector>

using namespace std;

int inputGrade(float grade) {
   cin >> grade;
   if ((grade - (int)grade) != 0.0 || grade < 0 || grade > 100) {
      cout << "invalid input!!!" << endl;
      exit(EXIT_FAILURE);
   }
   else
      return (int)grade;
}
int topGrade(const vector<int>& grade) {
	int max = 0;

	for (auto g : grade) {
		if (max < g)
		{
			max = g;
		}
	}
	return max;
}

int main() {
   vector<int> grades;
   float _grade = 0;
   for (int i = 0; i < 3; i++) {
      cout << "Input " << i << "-th grade(0~100):";
      int grade = inputGrade(_grade);
      /*====================구현 1=================*/
      /* 어차피 inputgrade에서 적절하지 않은 수는 걸러짐 */
      grades.push_back(grade);
      
   }
   /*==================구현 2============*/
   int grade = topGrade(grades);
   cout << "Top Grade: " << grade << endl;
      return 0;
}
