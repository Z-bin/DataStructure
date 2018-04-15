#include <iostream>
using namespace std;

void Reverse(int *arr, int from, int to)
{
	int i, temp;
	for (int i = 0; i < (to - from + 1) / 2; i++)
	{
		temp = arr[from + i];
		arr[from + i] = arr[to - i];
		arr[to - i] = temp;
	}
}

void Converse(int *arr, int n, int p)
{
	Reverse(arr, 0, p-1);
	Reverse(arr, p, n-1);
	Reverse(arr, 0, n-1);
}

int main()
{
	int arr[5] = { 1,2,3,4,5 };
	Converse(arr, 5, 5);
	for (int i = 0; i < 5; i++)
		cout << arr[i] << " ";
	
}