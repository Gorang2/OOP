#include <iostream>
using namespace std;

int	**create_integer_matrix(int n);
void	destroy_integer_matrix(int **M, int n);

int	**create_integer_matrix(int n)
{
	int	**arr;

	arr = new int *[n];
	for (int i=0; i<n; i++)
		arr[i] = new int[n];

	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			arr[i][j] = i + j;
	return (arr);
}

void	destroy_integer_matrix(int **M, int n)
{
	for (int i=0; i<n; i++)
		delete M[i];
	delete[] M;
}

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
