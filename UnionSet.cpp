//并查集

#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class UnionSet
{
public:
	UnionSet(size_t size)
		:_size(size)
		, _array(new int[size])
	{
		for (int i = 0; i < size; i++)
		{ //将集合的每个元素都初始化为-1
			_array[i] = -1;
		}
	}
	//合并两个集合
	void Merge(int root1, int root2)
	{
		while (_array[root2] >= 0)
		{
			root2 = _array[root2];
		}
		while (_array[root1] >= 0)
		{
			root1 = _array[root1];
		}
		_array[root1] += _array[root2];
		_array[root2] = root1;
	}
	//查找root对应集合的（根）代表元素
	int Find(int root)
	{
		while (_array[root]>=0)
		{
			root = _array[root];
		}
		return root;
	}
	//打印
	void Print()
	{
		for (int i = 0; i < _size; i++)
		{
			cout << _array[i] << " ";
		}
		cout << endl;
	}

public:
	int* _array;
	size_t _size;
};

	//计算朋友圈个数
int friends(int n, int m, int r[][2]) //n元素个数，m为每个朋友圈元素个数
{
	UnionSet uf(n + 1);
	//初始化朋友圈
	for (int i =0 ; i <= m; i++)
	{
		int first = r[i][0];
		int second = r[i][1];
		uf.Merge(first, second);
	}
	uf.Print();
	//计算朋友圈的个数
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		if (uf._array[i] < 0)
		{
			count++;
		}
	}
	return count;
}

int main()
{
	/*UnionSet ust(10);

	ust.Merge(0, 6);
	ust.Merge(0, 7);
	ust.Merge(0, 8);
	ust.Merge(1, 4);
	ust.Merge(1, 9);
	ust.Merge(2, 3);
	ust.Merge(2, 5);
	ust.Print();
	cout << "4所属集合的代表元素："<<ust.Find(4) << endl;
	cout << "9所属集合的代表元素：" << ust.Find(9) << endl << endl;

	ust.Merge(0, 1);
	ust.Print();
	cout << "4所属集合的代表元素：" << ust.Find(4) << endl;
	cout << "9所属集合的代表元素：" << ust.Find(9) << endl << endl;*/

	int r[][2] = { { 1, 2 },{ 2, 3 },{4, 5} };
	cout << "朋友圈的个数：" << friends(5, 2, r) <<endl<< endl;

	system("pause");
	return 0;
}
