#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
 
void get_command(string &str);
void get_size(int& size);
int** gen_matrix(int size);
void swap(int* a, int* b);// 주어짐
void sort_array(int* ary, int size);
void sort_matrix_row(int **arr, int size);
void print_matrix(int **matrix, int size);
void save_matrix(int **arr, int size);
void free_matrix(int **arr, int size);

void	get_command(string &str)
{
	cout << "Available Commands :\n(1) Make Matrix\n(2) Print Matrix\n(3) Sort Matrix\n(4) Save matrix in 'matrix.txt'\n(0) Exit" << endl;
	cin >> str;
}

void	get_size(int& size)
{
	cout << "Enter the size in (size x size): ";
	cin >> size;
}

int	**gen_matrix(int size)
{
	srand(time(NULL));

	int	**arr = new int*[size];
	for (int i=0; i<size; i++)
		arr[i] = new int[size];

	for (int i=0; i<size; i++)
		for (int j=0; j<size; j++)
			arr[i][j] = rand() % 101;
	cout << "Completed initializing matrix." << endl; //문제에는 없었음
	return (arr);
}

void	sort_matrix_row(int **arr, int size)
{
	for (int i=0; i<size; i++)
		sort_array(arr[i], size);
	cout << "Completed sorting matrix rows." << endl;
}

void	print_matrix(int **matrix, int size)
{
	for (int row=0; row<size; row++)
	{
		for (int col=0; col<size; col++)
			cout << setw(4) << matrix[row][col];
		cout << endl;
	}
}

void	save_matrix(int **arr, int size)
{
	ofstream fout("matrix.txt");

	fout << setw(4) << size << endl;
	for (int i=0; i<size; i++)
	{
		for (int j=0; j<size; j++)
			fout << setw(4) << arr[i][j];
		fout << endl;
	}
	cout << "Saved." << endl;
}

void	free_matrix(int **arr, int size)
{
	for (int i=0; i<size; i++)
		delete arr[i];
	delete[] arr;
}

int main() {
       string command;
       int** matrix = NULL;
       int size = 0;
       while (1) {
	       cout << "========================================" << endl;
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
    {
    	for (int j=0; j<size; j++)
    	{
	    	if (j != size - 1)
		{
			if (ary[j] > ary[j + 1])
				swap(&(ary[j]), &(ary[j + 1]));
		}
		if (j != 0)
		  	if (ary[j] < ary[j - 1])
				swap(&(ary[j]), &(ary[j - 1]));
    	}
    }
}
