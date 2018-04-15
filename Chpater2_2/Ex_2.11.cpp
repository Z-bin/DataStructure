#include <iostream>
using namespace std;

int find(int *A, int *B,int n)
{
	int la, ha, ma, lb, hb, mb;
	la = lb = 0;
	ha = hb = n - 1;
	while (la != ha || lb != hb)
	{
		ma = (la + ha) / 2;
		mb = (lb + hb) / 2;
		if (A[ma] == B[mb])
			return A[ma];
		if (A[ma] < B[mb])
		{
			if ((la + ha) % 2 == 0)
			{
				la = ma;
				hb = mb;
			}
			else
			{
				la = ma + 1;
				hb = mb;
			}
		}
		else
		{
			if ((lb + hb) % 2 == 0)
			{
				ha= ma;
				lb = mb;
			}
			else
			{
				ha= ma;
				lb = mb+1;
			}
		}

	}
	return A[la] < B[lb] ? A[la] : B[lb];
}


int main()
{
	int A[5] = { 1,2,3,4,10};
	int B[5] = { 1,2,5,6,8 };

	cout<<find(A, B, 5)<<" ";
	system("pause");
}