#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

const int InitiSize = 100;
typedef struct
{
	char *data;
	int MaxSize;
	int Length;
}SeqList;

//插入元素
bool ListInsert(SeqList &L, int i, char e)
{
	if (i < 1 || i > L.Length + 1)
	{
		return false;
	}
	if (L.Length >= L.MaxSize)
	{
		return false;
	}
	for (int j = L.Length; j >= i; j--)
	{
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.Length++;
	return true;
}

//删除第i个位置元素
bool ListDelete(SeqList &L, int i, char &e)
{
	if (i < 1 || i > L.Length)
	{
		return false;
	}
	e = L.data[i - 1];
	for (int j = i; j < L.Length; j++)
	{
		L.data[j - 1] = L.data[j];
	}
	L.Length--;
	return true;
}

//查找元素所在位置
int LoacteElem(SeqList L, char e)
{
	int i;
	for (i = 0; i < L.Length; i++)
	{
		if (L.data[i] == e)
		{
			return i + 1;
		}
	}
	return 0;
}

//Ex_2.1 删除最小元素
bool Del_Min(SeqList &L, char &value)
{
	if (L.Length == 0)
	{
		return false;
	}
	int pos = 0;
	value = L.data[0];
	for (int i = 1; i < L.Length; i++)
	{
		if (L.data[i] < value)
		{
			value = L.data[i];
			pos = i;
		}
	}
	L.data[pos] = L.data[L.Length - 1];
	L.Length--;
	return true;
}

//Ex_2.2 顺序表逆置
bool Reverse(SeqList &L)
{
	int len = L.Length / 2;
	if (L.Length <= 0)
	{
		return false;
	}
	for (int i = 0; i < len; i++)
	{
		char temp = L.data[i];
		L.data[i] = L.data[L.Length - i - 1];
		L.data[L.Length - i - 1] = temp;
	}
	return true;
}

//Ex_2.3 删除顺序表中所有值为X的元素(方法一)
bool delAllX_1(SeqList &L,char c)
{
	int nums = 0;
	int len = L.Length;
	if (L.Length <= 0)
	{
		return false;
	}
	for (int i = 0; i < len; i++)
	{
		if (L.data[i] == c)
		{
			nums++;
			L.Length--;
		}
		else
		{
			L.data[i - nums] = L.data[i];
		}
	}
	return true;
}

//Ex_2.3 删除顺序表中所有值为X的元素(方法二)
bool delAllX_2(SeqList &L, char c)
{
	int pos = 0;
	int len = L.Length;
	if (L.Length <= 0)
	{
		return false;
	}
	for (int i = 0; i < len; i++)
	{
		if (L.data[i] != c)
		{
			L.data[pos++] = L.data[i];
		}
		else
		{
			L.Length--;
		}
	}
	return true;
}

//Ex2.4 有序顺序表删除s到t之间的元素
bool delSToT(SeqList &L, char s, char t)
{
	int i, j;
	if (s >= t || L.Length <= 0)
	{
		return false;
	}
	for (i = 0; i < L.Length && L.data[i] < s; i++)
		;
	if (i >= L.Length)
	{
		return false;
	}
	for (j = 0; j < L.Length && L.data[j] <= t; j++)
		;
	for (; j < L.Length; i++, j++)
	{
		L.data[i] = L.data[j];
	}
	L.Length = i;
	return true;
}

//Ex2.5 顺序表删除s到t之间的元素
bool delSToT_2(SeqList &L, char S, char T)
{
	int pos = 0;
	int len = L.Length;
	if (L.Length <= 0 || T <= S)
	{
		return false;
	}
	for (int i = 0; i < len; i++)
	{
		if (!(L.data[i] >= S &&L.data[i] <= T))
		{
			L.data[pos++] = L.data[i];
		}
		else
		{
			L.Length--;
		}
	}
	return true;
}
//Ex2.5 有序顺序表删除相同的元素
bool delSame(SeqList &L)
{
	int len = L.Length;
	if (L.Length <= 0)
	{
		return false;
	}
	for (int i = 0, j = 1; j < len; j++)
	{
		if (L.data[i] != L.data[j])
		{
			L.data[++i] = L.data[j];
		}
		else
		{
			L.Length--;
		}
	}
	return true;
}
int main()
{
	SeqList seqList;
	seqList.data = new char[InitiSize];
	seqList.Length = 0;
	seqList.MaxSize = InitiSize;
	for (int i = 1; i <= 6; i++)
	{
		ListInsert(seqList, i, 'a' + i);

		ListInsert(seqList, i, 'a');
		//ListInsert(seqList, i, 'a');

	}
	//Reverse(seqList);
	//delAllX_2(seqList, 'a');
	//delSToT_2(seqList, 'b', 'e');
	//delSame(seqList);
	for (int i = 0; i < seqList.Length; i++)
	{
		cout << seqList.data[i] << " ";
	}

	cout << seqList.Length << endl;

	system("pause");
}
