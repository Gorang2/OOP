#include <iostream>

using namespace std;

int	**create_integer_matrix(int n);
void	destroy_integer_matrix(int **matrix, int n);

int main()
{
    int i,j, **M;
    M = create_integer_matrix(3);
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    destroy_integer_matrix(M, 3);
    return 0;
}

int	**create_integer_matrix(int n)
{
	int	**matrix;

	matrix = new int*[n];
	for (int i=0; i<n; i++)
		matrix[i] = new int[n];
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			matrix[i][j] = i + j;
	return matrix;
}

void	destroy_integer_matrix(int **matrix, int n)
{
	for (int i=0; i<n; i++)
		delete matrix[i];
	delete[] matrix;
}
