#include <iostream>
using namespace std;

int Majority(int arr[], int n)
{
	int count = 1;
	int c = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] == c)
		{
			count++;
		}
		else
		{
			if (count > 0)
			{
				count--;
			}
			else
			{
				count = 1;
				c = arr[i];
			}
		}
	}
	count = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == c)
		{
			count++;
		}
	}
	return count > n / 2 ? c : -1;
}

int main()
{
	int arr[7] = { 1,2,3,5,4,4,4 };
	cout << Majority(arr, 7) << endl;
	getchar();

}