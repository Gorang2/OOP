#include <iostream>
using namespace std;
int main(){
    int i, j, k;
    int ****a = new int*** [2];
    a[0] = new int** [2];
    a[1] = new int** [2];
    for(i=0; i<2; i++){
        for(j=0; j<2; j++)
	{
            	a[i][j] = new int*[5];
		for (k=0; k<5; k++)
		{
			a[i][j][k] = new int;
			*(a[i][j][k]) = i + j + k;
            		cout << *(a[i][j][k]) << " ";
		}
		cout << endl;
	}	
        cout << endl;
    }
    for (i=0; i<2; i++)
    {
	    for (j=0; j<2; j++)
	    {
		    for (k=0; k<5; k++)
			    delete a[i][j][k];
		    delete[] a[i][j];
	    }
	    delete[] a[i];
    }
    delete[] a;

    return 0;
}
