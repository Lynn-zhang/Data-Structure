
//////////////////////////////////////////////// By: Lynn-Zhang

#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;

#define M 10   //行
#define N 10   //列

struct Pos    //位置坐标
{
	int  _row;
	int _col;
};


void InitMaze(int* maze);      // 初始化迷宫数组
bool SearchMazePath(int *maze, Pos entry, stack<Pos>& paths);    // 利用栈回溯查找通路
void PrintMaze(int *maze);    // 打印迷宫
bool CheckIsAccess(int* maze, const Pos & next);    // 检查该位置是否合法


void InitMaze(int* maze)
{	
	struct WavHeadhWAV;
	FILE* fout = fopen("MazeMap.txt", "r");
	//FILE* fout = fopen("E:\\CODE\\迷宫\\迷宫\\MazeMap.txt", "r");
	//FILE* fout = fopen("C:\\Users\\admin\\Desktop\\MazeMap.txt", "r");
	if (fout == NULL)
	{
		cout << "can't find MazeMap.txt !" << endl<<endl;
		return;
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N;)
		{
			char ch = fgetc(fout);
			if (ch=='1'||ch=='0')
			{
				maze[i*N + j] = ch - '0';
				j++;
			}
		}
	}
	fclose(fout);
}
void PrintMaze(int *maze)   // 打印迷宫
{
	assert(maze);
	for (int i = 0; i < M; i++)
	{ 
		for (int j = 0; j < N; j++)
		{
			cout << maze[i*N + j] <<" " ;
		}
		cout << endl;
	}
	cout << endl;  
}
//bool SearchMazePath(int *maze, Pos entry, stack<Pos>& paths)   // 检查是否已经找到出口
//{
//	assert(maze);
//	paths.push(entry);
//	while (!paths.empty())
//	{
//		Pos cur = paths.top();
//		maze[cur._row*N+cur._col] = 2;
//		if (cur._row==M-1)
//		{
//			return true;
//		}
//		Pos next = cur;
//		next._col--;  //左
//		if (CheckIsAccess(maze, next))
//		{
//			paths.push(next);
//			maze[next._row*N + next._col] = 2;
//			continue;
//		}
//		next = cur;
//		next._col++; //右
//		if (CheckIsAccess(maze, next))
//		{
//			paths.push(next);
//			maze[next._row*N + next._col] = 2;
//			continue;
//		}
//		next = cur;
//		next._row--; //上
//		if (CheckIsAccess(maze, next))
//		{
//			paths.push(next);
//			maze[next._row*N + next._col] = 2;
//			continue;
//		}
//		next = cur;
//		next._row++; //下
//		if (CheckIsAccess(maze, next))
//		{
//			paths.push(next);
//			maze[next._row*N + next._col] = 2;
//			continue;
//		}
//		paths.pop();
//	}
//	return false;
//}


bool SearchMazePath(int *maze, Pos entry, stack<Pos>& paths)   // 检查是否已经找到出口,并实现迷宫的最优解
{
	assert(maze);
	stack<Pos>min;
	paths.push(entry);
	while (!paths.empty())
	{
		Pos cur = paths.top();
		maze[cur._row*N+cur._col] = 2;
		if (cur._row==M-1)
		{
			if (paths.size()< min.size() || min.size() == 0)
			{
				min = paths;
			}
			paths.pop();
			maze[min.top()._row*N + min.top()._col] = 1;
		}	
		Pos next = cur;
		next._col--;  //左
		if (CheckIsAccess(maze, next))
		{
			paths.push(next);
			maze[next._row*N + next._col] = 2;
			continue;
		}
		next = cur;
		next._col++; //右
		if (CheckIsAccess(maze, next))
		{
			paths.push(next);
			maze[next._row*N + next._col] = 2;
			continue;
		}
		next = cur;
		next._row--; //上
		if (CheckIsAccess(maze, next))
		{
			paths.push(next);
			maze[next._row*N + next._col] = 2;
			continue;
		}
		next = cur;
		next._row++; //下
		if (CheckIsAccess(maze, next))
		{
			paths.push(next);
			maze[next._row*N + next._col] = 2;
			continue;
		}
		paths.pop();
	}
	if (paths.empty()&&!min.empty())
	{
			maze[min.top()._row*N + min.top()._col] = 2;
			return true;
	}
	return false;
}

bool CheckIsAccess(int* maze, const Pos& next)    // 检查该位置是否合法
{
	assert(maze);
	if ((next._row >= 0 && next._row <= N) && (next._col >= 0 && next._col < M) && maze[next._row*N + next._col] == 0)
	{
		return true;
	}
	return false;
}
int main()
{
	int Maze[M][N] = { 0 };
	InitMaze((int*)Maze);
	cout << "The original labyrinth :" << endl<<endl;
	PrintMaze((int*)Maze); 

	stack<Pos>paths;
	Pos entry = { 2, 0 };
	if (SearchMazePath((int*)Maze, entry, paths))
	{
		cout << "success !" << endl<<endl;
	}
	PrintMaze((int*)Maze);

	system("pause");
	return 0;
}
