#include <iostream>

using namespace std;

int	change_val(int *p)
{
	*p = 3;
	return 0;
}

int	main()
{
	int arr[3][2] = {1, 2, 3,4,5,6};
	int(&ref)[3][2] = arr;


	ref[0][0] = 999;
	ref[0][1] = 998;
	ref[1][0] = 997;

	int i =0;
	int j =0;
	for (i = 0; i < 3; i++)
	{
		j = 0;
		//cout << "i : " << i << endl;
		for (j =0; j < 2; j++)
		{
			//cout << "j : " << j << endl;
			cout << arr[i][j] << " ";
		}
	}
	cout << endl;
	return 0;
}

