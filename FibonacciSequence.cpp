#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<Windows.h>
using namespace std;

//递归写法
//long long FibonacciSeq(int n)
//{
//	if (n < 2)
//	{
//		return n;
//	}
//	return FibonacciSeq(n - 1) + FibonacciSeq(n - 2);
//}



// 非递归(方法一)
//long long FibonacciSeq(int n)
//{
//	long long f[3] = { 0, 1,n };
//
//	for (int i = 2; i <=n; i++)
//	{
//		f[2] = f[0] + f[1];
//		f[0] = f[1];
//		f[1] = f[2];
//	}
//	return f[2];
//}

//方法二
//long long FibonacciSeq(int n)
//{
//	long long fib[1000] = { 0, 1 };
//	
//	for (int i = 2; i <= n; i++)
//	{
//		fib[i] = fib[i - 1] + fib[i - 2];
//	}
//	long long ret = fib[n];
//	return ret;
//}

//long long FibonacciSeq( int n)
//{
//	//这里一定要判断边界条件，否则传的参数为0时，程序会因触发断点而崩溃
//	if (n ==0)
//	{
//		return 0;
//	}
//	long long *fib=new long long[n+1];
//	fib[0] = 0;
//	fib[1] = 1;
//	for (int i = 2;i <=n; i++)
//	{
//		fib[i] = fib[i - 1] + fib[i - 2];
//	}
//	long long ret = fib[n];
//	delete[] fib;
//	return ret;
//}

long long FibonacciSeq(int n)
{
	if (n == 0)
	{
		return 0;
	}
	long long *fib = (long long *)malloc(sizeof(long long)*(n + 1));
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	long long ret = fib[n];
	free(fib);
	return ret;
}

int main()
{
	cout << FibonacciSeq(0) << endl;
	cout << FibonacciSeq(1) << endl;
	cout << FibonacciSeq(2) << endl;
	cout << FibonacciSeq(3) << endl;
	cout << FibonacciSeq(4) << endl;
	cout << FibonacciSeq(5) << endl;
	cout << FibonacciSeq(6) << endl;
	cout << FibonacciSeq(7) << endl;
	cout << FibonacciSeq(8) << endl;

	int start = GetTickCount();
	cout << FibonacciSeq(100) << endl;
	int end = GetTickCount();
	cout <<end - start << endl;

	system("pause");
	return 0;
}