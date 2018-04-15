#include <iostream>
#include <algorithm>
using namespace std;

void SearchExchangeInsert(int *arr, int num, int len)
{
	int low = 0, high = len-1, mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (arr[mid] == num)
		{
			break;
		}
		else if (arr[mid] < num)
		{
			low = mid + 1;
		}
		else 
		{
			high = mid - 1;
		}		
	}
	if (arr[mid] == num&& mid != len - 1)
	{
		int temp = arr[mid];
		arr[mid] = arr[mid + 1];
		arr[mid + 1] = temp;
	}
	if (low > high)
	{
		int i;
		for(i = len - 1; i > high; i--)
			arr[i + 1] = arr[i];
		arr[i + 1] = num;		
	}
}

int main()
{
	int arr[10] = { 1,2,3,4,5 };
	SearchExchangeInsert(arr, 10, 5);
	for (int i = 0; i < 6; i++)
	{
		cout << arr[i] << " ";
	}
	system("pause");
}