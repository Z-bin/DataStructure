#include <iostream>
#include <algorithm>
using namespace std;

//Ex_2.8 逆置
void reverse(int *arr, int m, int n)
{
	for (int i = 0; i < m / 2; i++)
	{
		int temp = arr[i];
		arr[i] = arr[m - i - 1];
		arr[m - i - 1] = temp;
	}
	for (int i = m; i < m + n / 2; i++)
	{
		int temp = arr[i];
		arr[i] = arr[2 * m + n - i - 1];
		arr[2 * m + n - i - 1] = temp;
	}
	for (int i = 0; i < (m + n) / 2; i++)
	{
		int temp = arr[i];
		arr[i] = arr[m + n - i - 1];
		arr[m + n - i - 1] = temp;
	}
}

int main()
{
	int arr[6] = { 4,5,6,1,2,3 };
	reverse(arr, 3, 3);
	for (int i = 0; i < 6; i++)
	{
		cout << arr[i] << " ";
	}
	system("pause");
}
