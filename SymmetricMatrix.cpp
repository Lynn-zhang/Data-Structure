#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<assert.h>
using namespace std;

template<class T>
class SymmetricMatrix
{
public:
	SymmetricMatrix(T* array, size_t n)
	{
		_arraySize = n*(n + 1) / 2;
		_size = n;
		_array = new T[_arraySize];
		assert(array);
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				_array[i*(i + 1) / 2 + j] = array[i*n + j];
			}
		}
	}
	T& GetPos(size_t row, size_t col)    // 获取节点
	{
		if (row < col)    //如果该位置为上三角的，利用对称原理，交换该位置的行和列即可
		{
			swap(row, col);
		}
		return _array[row*(row + 1) / 2 + col];
	} 
	void Display()     //打印
	{
		for (int i = 0; i < _size; i++)
		{
			for (int j = 0; j < _size; j++)
			{
				if (i >= j)
				{
					cout << _array[i*(i + 1) / 2 + j] << " ";
				}
				else if (i<j)
				{
					cout << _array[j*(j + 1) / 2 + i] << " ";
				}
			}
			cout << endl;
		}
		cout << endl;
	}
private:
	T *_array;      //压缩矩阵
	size_t _size;   //方阵大小_size*_size
	size_t _arraySize;   //压缩矩阵的总大小
};

int main()
{
	int Matrix[][5] =    
	{
		{ 0, 1, 2, 3, 4 },
		{ 1, 0, 1, 2, 3 },
		{ 2, 1, 0, 1, 2 },
		{ 3, 2, 1, 0, 1 },
		{ 4, 3, 2, 1, 0 },

	};
	SymmetricMatrix<int> mat((int *)Matrix, 5);  //建立压缩矩阵，并用Matrix矩阵初始化
	mat.Display();
	cout << mat.GetPos(1, 2) << endl;
	system("pause");
	return 0;
}