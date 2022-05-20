#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <iomanip>
using namespace std;

int	**init_matrix(int row, int col)
{
	int **mat = new int*[row];
	for (int i=0; i<row; i++)
		mat[i] = new int[col];

	for (int i=0; i< row; i++)
		for (int j=0; j<col; j++)
		{
			mat[i][j] = rand() % 20 - 10;
		}
	return (mat);
}

void	print_matrix(int **matrix, int row, int col, string name)
{
	cout << endl<< name << "행렬 : " << endl;
	for (int i=0; i<row; i++)
	{
		for (int j=0; j<col; j++)
			cout << setw(6) << matrix[i][j];
		cout << endl;
	}
}

int	**mult_matrix(int **A, int **B, int Arow, int Acol, int Brow, int Bcol)
{
	if (Acol != Brow)
	{
		cout << endl << "두 행렬을 곱할 수 없습니다." << endl;
		exit(EXIT_FAILURE);
	}
	
	int ** res = new int*[Arow];
	for (int i=0; i<Arow; i++)
		res[i] = new int[Bcol];

	for (int i=0; i<Arow; i++)
		for (int j=0; j<Bcol; j++)
		{
			res[i][j] = 0;
			for (int k=0; k<Acol; k++)
				res[i][j] += A[i][k] * B[k][j];
		}
	return (res);
}



int main()
{
	int **A;
	int **B;
	int **res;
	int Arow, Acol, Brow, Bcol;
	srand(time(NULL));
	cout << "A의 행, 열의 크기를 입력해주세요 : ";
	cin >> Arow >> Acol;
	cout << "B의 행, 열의 크기를 입력해주세요 : ";
	cin >> Brow >> Bcol;

	if (Arow < 1 || Acol < 1 || Brow < 1 || Bcol < 1)
	{
		cout << endl << "행렬을 생성할 수 없습니다." << endl;
		return (EXIT_FAILURE);
	}
	A = init_matrix(Arow, Acol);
	B = init_matrix(Brow, Bcol);
	print_matrix(A, Arow, Acol, "A ");
	print_matrix(B, Brow, Bcol, "B ");
	res = mult_matrix(A, B, Arow, Acol, Brow, Bcol);
	print_matrix(res, Arow, Bcol, "AB 곱");
	return (0);
}
