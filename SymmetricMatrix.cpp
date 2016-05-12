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
	T& GetPos(size_t row, size_t col)    // ��ȡ�ڵ�
	{
		if (row < col)    //�����λ��Ϊ�����ǵģ����öԳ�ԭ��������λ�õ��к��м���
		{
			swap(row, col);
		}
		return _array[row*(row + 1) / 2 + col];
	} 
	void Display()     //��ӡ
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
	T *_array;      //ѹ������
	size_t _size;   //�����С_size*_size
	size_t _arraySize;   //ѹ��������ܴ�С
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
	SymmetricMatrix<int> mat((int *)Matrix, 5);  //����ѹ�����󣬲���Matrix�����ʼ��
	mat.Display();
	cout << mat.GetPos(1, 2) << endl;
	system("pause");
	return 0;
}