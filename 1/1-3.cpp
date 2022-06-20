#include <iostream>

using namespace std;

int	main()
{
	int user_input;
	cout << "저의 정보를 표시해 줍니다" << endl;
	cout << "1. name " << endl;
	cout << "2. age  " << endl;
	cout << "3. sex  " << endl;
	cin >> user_input;

	switch (user_input)
	{
		case 1:
			cout << "PSY ! " << endl;
			break;
		case 2:
			cout << "100 age" << endl;
			break;
		case 3:
			cout << "male" << endl;
			break;
		default:
			cout << "noting curious~" << endl;
			break;
	}
	return 0;
}
