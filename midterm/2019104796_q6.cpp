#include <iostream>

#include <string>

#include <fstream>

#include <iomanip>

using namespace std;


void get_command(string& str);

void get_size(int& size);

int** gen_matrix(int size);

void swap(int* a, int* b);// 주어짐

void sort_array(int* ary, int size);

void sort_matrix_row(int **matrix, int size);

void print_matrix(int **matrix, int size);

void save_matrix(int **matrix, int size);

void free_matrix(int **matrix, int size);

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

void	get_command(string& str)
{
	cout << "1. Generate matrix" << endl;
	cout << "2. Print matrix" << endl;
	cout << "3. Sort matrix" << endl;
	cout << "4. Save matrix" << endl;
	cout << "0. Exit program" << endl;
	cout << ">>";
	cin >> str;
}

void	get_size(int& size)
{
	cout << "Enter the size in (size x size): ";
	cin >> size;
	cout << endl;
}

void swap(int* a, int* b) {

    int temp = *a;

    *a = *b;

    *b = temp;

}

int	**gen_matrix(int size)
{
	int	**matrix;

	srand(time(NULL));

	matrix = new int*[size];
	for (int i=0; i<size; i++)
		matrix[i] = new int[size];
	for (int i=0; i<size; i++)
		for (int j=0; j<size; j++)
			matrix[i][j] = rand() % 101;
	return (matrix);
}

void	sort_matrix_row(int **matrix, int size)
{
	for (int i=0; i<size; i++)
		sort_array(matrix[i], size);
	cout << "Completed" << endl << endl;
}

void	print_matrix(int **matrix, int size)
{
	for (int row=0; row<size; row++)
	{
		for (int col=0; col<size; col++)
			cout << setw(4) << matrix[row][col];
		cout << endl;
	}
	cout << endl;
}

void	save_matrix(int **matrix, int size)
{
	ofstream fout("matrix.txt");
	fout << size << endl;
	for (int i=0; i<size; i++)
	{
		for (int j=0; j<size; j++)
			fout << setw(4) << matrix[i][j];
		fout << endl;
	}
	cout << "Saved" << endl << endl;
}

void	free_matrix(int **matrix, int size)
{
	for (int i=0; i<size; i++)
		delete matrix[i];
	delete[] matrix;
}

void sort_array(int* ary, int size){
	for (int i=0; i<size; i++)
		for (int j=size-1; j>i; j--)
			if (ary[j] < ary[j - 1])
				swap(&(ary[j]), &(ary[j - 1]));
}
