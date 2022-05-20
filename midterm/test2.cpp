#include <iostream>

#include <string>

#include <fstream>

#include <iomanip>

using namespace std;

 

void get_command(string& command);

void get_size(int& size);

int** gen_matrix(int size);

void swap(int* a, int* b);// 주어짐

void sort_array(int* ary, int size);

void sort_matrix_row(int **matrix, int size);

void print_matrix(/*작성할 것*/);

void save_matrix(/*작성할 것*/);

void free_matrix(/*작성할 것*/);

void	get_command(string& command)
{
	cout << "1. Genereate matrix" << endl;
	cout << "2. Print matrix" << endl;
	cout << "3. Sort matrix" << endl;
	cout << "4. Save matrix" << endl;
	cout << "0. Exit" << endl;
	cout << ">>";
	cin >> command;
}

void	get_size(int& n)
{
	cout << "Enter the size in (size x size): ";
	cin >> n;
}

int	**gen_matrix(int size)
{
	//생성
	int **matrix = new int *[size];
	for (int i=0; i<size; i++)
		matrix[i] = new int[size];

	//초기화
	for (int i=0; i<size; i++)
		for (int j=0; j<size; j++)
			matrix[i][j] = rand() % 101;

	return matrix;
}


void	sort_matrix_row(int **matrix, int n)
{
	for (int i=0; i<n; i++)
		sort_array(matrix[i]);
}



int main() {

       string command;

       int** matrix = NULL;

       int size = 0;

       while (1) {

              get_command(command);
              if(command == "1"){

                      get_size(size);

                      matrix = gen_matrix(size);

              }

              else if (command == "2") {

                      print_matrix(matrix, size);

              }

              else if (command == "3") {

                      sort_matrix_row(matrix, size);

              }

              else if (command == "4") {

                      save_matrix(matrix, size);

              }

              else if (command == "0") {

                     free_matrix(matrix, size);

                      cout << "Exit the program.." << endl;

                      exit(104);

              }

              else {

                      cout << "Wrong command" << endl << endl;

             }

       }

 

       return 0;

}

 

void swap(int* a, int* b) {

    int temp = *a;

    *a = *b;

    *b = temp;

}

 

void sort_array(int* ary, int size){

	for (int i=0; i<size; i++)
		for (j=size - 1; j>i; j--)
			if (ary[j] < ary[j - 1])
				swap(&(ary[j]), &(ary[j - 1]));
    // 보너스 문제를 안 풀시에는 작성하지 않아도 됨

}

