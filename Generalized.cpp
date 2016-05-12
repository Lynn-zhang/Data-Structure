#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;

//设置枚举类型，利用枚举变量来记录每个节点的类型
enum  Type
{
	HEAD,
	VALUE,
	SUB,
};

//构造节点
struct GeneralizedNode
{
	Type _type;       //类型
	GeneralizedNode* _next;  //指向同层的下一个节点
	union
	{
		char _value;    //有效值
		GeneralizedNode* _subLink;     // 指向子表的指针
	};
	
	GeneralizedNode(Type type = HEAD, char value = '0')
	:_value(value)
	,_type(type)
	, _next(NULL)
	{
		if (_type == SUB)
		{
			_subLink = NULL;
		}
	}
};

//广义表
class Generalized
{
public:
	//无参的构造函数,建立空的广义表
	Generalized()    
		:_head(NULL)
	{}
    //建造广义表，有参数的构造函数
	Generalized(const char* str)   
		:_head(NULL)
	{
		_head = _CreatList(str);
	}
	//打印广义表
	void Print()
	{
		_Print(_head);
		cout << endl;
	}
	//获取值节点的个数
	size_t Amount()
	{
		return _Amount(_head);
	}
	//获取广义表的深度
	size_t Depth()
	{
		return _Depth(_head);
	}
	//拷贝构造
	Generalized(const Generalized& g)
	{
		_head = _Copy(g._head);
	}
	////赋值运算符的重载
	Generalized& operator=(const Generalized& g)
	{
		if (this != &g)
		{
			_Destory(_head);
			_head=_Copy(g._head);
		}
		return *this;
	}
	////析构函数
	~Generalized()
	{
		_Destory(_head);	
	}

protected:
	void _Print(GeneralizedNode* head)
	{
		if (head == NULL)
		{
			cout << "Generalized table is NULL" << endl;
			return;
		}
		GeneralizedNode* cur = head;
		while (cur)
		{
			if (cur->_type == HEAD)
			{
				cout << '(';
			}
			else if (cur->_type == VALUE)
			{
				cout << cur->_value;
				if (cur->_next)
				{
					cout << ',';
				}
			}
			else if (cur->_type == SUB)
			{
				_Print(cur->_subLink);
				if (cur->_next)
				{
					cout << ',';
				}				
			}
			cur = cur->_next;
		}
		cout << ')';
	}
	GeneralizedNode* _CreatList(const char*& str)
	{
		assert(*str == '(');
		GeneralizedNode* head = new GeneralizedNode(HEAD,'0');
		GeneralizedNode* cur = head;
		str++;
		while (str != '\0')
		{
			if ((*str >= '0'&&*str <= '9') || (*str >= 'a'&&*str <= 'z') || (*str >= 'A'&&*str <= 'Z'))
			{
				cur->_next = new GeneralizedNode(VALUE, *str);
				cur = cur->_next;
			}
			else if (*str == '(')
			{
				cur->_next = new GeneralizedNode(SUB);
				cur = cur->_next;
				cur->_subLink = _CreatList(str);
			}
			else if (*str == ')')
			{
				return head;
			}
			str++;
		}
		return head;
	}
	size_t _Amount(GeneralizedNode* head)
	{
		GeneralizedNode* begin = head;
		size_t count = 0;
		while (begin)
		{
			if (begin->_type == VALUE)
			{
				count++;
			}
			if (begin->_type == SUB)
			{
				count += _Amount(begin->_subLink);
			}
			begin = begin->_next;
		}
		return count;
	}
	size_t _Depth(GeneralizedNode* head)
	{
		if (_head == NULL)
		{
			return 0;
		}
		size_t dp=0;
		GeneralizedNode* cur = head;
		size_t max = 0;
		while (cur)
		{
			if (cur->_type == SUB)
			{
				dp=_Depth(cur->_subLink);
				if (max < dp)
				{
					max = dp;
				}
			}
			cur = cur->_next;
		}
		return max+1;
	}
	GeneralizedNode* _Copy(GeneralizedNode* head)
	{
		if (head == NULL)
		{
			return NULL;
		}
		GeneralizedNode* cur = head;
		GeneralizedNode* begin = new GeneralizedNode(HEAD);
		GeneralizedNode* bg = begin;
		cur = cur->_next;
		while (cur)
		{
			if (cur->_type == VALUE)
			{
				bg->_next = new GeneralizedNode(VALUE,cur->_value);
				bg = bg->_next;
			}
			if (cur->_type == HEAD)
			{
				bg->_next = new GeneralizedNode(HEAD);
				bg = bg->_next;
			}
			if (cur->_type == SUB)
			{
				bg->_next = new GeneralizedNode(SUB);
				bg = bg->_next;
				bg->_subLink=_Copy(cur->_subLink);
			}
			cur = cur->_next;
		}
			return begin;
	}
	void _Destory(GeneralizedNode* head)
	{
		if (head == NULL)
		{
			return;
		}
		while (head)
		{
			GeneralizedNode* begin = head->_next;
			if (head->_type == SUB)
			{
				_Destory(head->_subLink);
			}
			delete head;
			head = begin;
		}
	}
protected:
	GeneralizedNode* _head;
};

////广义表
//class Generalized
//{
//public:
//	//无参的构造函数,建立空的广义表
//	Generalized();
//	//建造广义表，有参数的构造函数
//	Generalized(const char* str);
//	//打印广义表
//	void Print();
//	//获取值节点的个数
//	size_t Amount();
//	//获取广义表的深度
//	size_t Depth();
//	//拷贝构造
//	Generalized(const Generalized& g);
//	////赋值运算符的重载
//	Generalized& operator=(const Generalized& g);
//	////析构函数
//	~Generalized();
//
//protected:
//	void _Print(GeneralizedNode* head);
//	GeneralizedNode* _CreatList(const char*& str);
//	size_t _Amount(GeneralizedNode* head);
//	GeneralizedNode* _Copy(GeneralizedNode* head);
//	void _Destory(GeneralizedNode* head);
//protected:
//	GeneralizedNode* _head;
//};


void Test()
{
	//Generalized list = ("(a,b)");
	//Generalized list = ("(a,b,(c,(t,(p,m,(l))),d),(e,(f),g),l,o)");
	//Generalized list = ("(a,b,(c,d))");
	Generalized list = ("(a,b,(c,d),(e,(f),g))");
	//Generalized list = ("");
	list.Print();
	/*size_t size=list.Size();
	cout << size << endl;
	size_t dp=list.Depth();
	cout << dp << endl;*/
	Generalized list1("(a,b,(c,d))");
	list1.Print();
	list1 = list;
	list1.Print();
	cout << list1.Amount() << endl;

}

int main()
{
	Test();
	system("pause");
	return 0;
}