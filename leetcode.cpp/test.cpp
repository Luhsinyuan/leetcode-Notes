#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void Put_out(int n,int k,vector<int>& ans);//输出函数声明

//===============================================完成该功能的函数===========================================

void Func(int n, int k, vector<int>& numlist)
{
	if (numlist.size() == n - 1)                     //当所求数的位数为n-1时，进行最后一位的特殊化处理，也是递归的终止条件
	{
		int temp = numlist[n - 2];                   //根据第n-1位的数字确定最后一位的值，将符合规范的值加入容器中构成完整的数字
		if (temp - k >= 0)
		{
			numlist.push_back(temp - k);
			Put_out(n,k,numlist);
			numlist.pop_back();
		}
		if (k != 0 && temp + k <= 9)            //当k为0时只执行一次输出操作
		{
			numlist.push_back(temp + k);
			Put_out(n,k,numlist);
			numlist.pop_back();
		}
		return;
	}
	else
	{
		if (numlist.size() == 0)                   //当容器中没有数值时确定数字第一位的值，范围为1-9
		{
			for (int i = 1; i <= 9; i++)
			{
				numlist.push_back(i);
				Func(n, k, numlist);
				numlist.pop_back();
			}
		}
		else                                   //当容器中的数值位数为一般数（不是0不是倒数第二位）时，对数值进行一般化处理，根据
		{                                      //前一位的数值确定下一位的数值，并进入递归继续进行该操作
			int temp = numlist.back();
			if (temp - k >= 0)
			{
				numlist.push_back(temp - k);
				Func(n, k, numlist);
				numlist.pop_back();
			}
			if (k != 0 && temp + k <= 9)       //当k为0时，确定下一位数值的操作只进行一次
			{
				numlist.push_back(temp + k);
				Func(n, k, numlist);
				numlist.pop_back();
			}
		}
	}
}

//=========================================================输出函数=========================================================

void Put_out(int n,int k,vector<int>& numlist)
{
	ofstream fout;
	fout.open("test.txt", ios_base::app | ios_base::out);
	int max_symbol = numlist[0] == 9 ? 1 : 0;                                       //判断当前容器中的数字是不是最大数，若是，则标识符为1；若不是，则标识符为0
	for (int i = 0; i < n; i++)
	{
		cout << numlist[i];                                                         //逐项输出数字的每一位
		fout << numlist[i];
		if (max_symbol == 1)                                                    //判断该数是不是最大数，如果偶数位的值都为9且奇数位的值都是9-k,
		{                                                                       //则是最大数，并将标识符置为1；若有一项不符，则不是最大数，并将标识符记为0
			if ((i % 2 == 1 && numlist[i] == 9 - k) || (i % 2 == 0 && numlist[i] == 9))
			{

			}
			else
			{
				max_symbol = 0;
			}
		}
	}
	if (max_symbol == 0)                                                        //在除最后一个数字（即最大值）以外的数后面输出“，”
	{
		cout << ",";
		fout << ",";
	}
	fout.close();
}

//===================================================输入的n,k值的合法性判断函数=========================================

bool Judge_legality(int n, int k)
{
	if (n <= 1 || k < 0 || k > 9)                                              //依要求，输入的位数n应该是一个大于1的正整数，每一位数值间的差k
	{                                                                          //应该是0-8的一个整数。若符合要求，返回true；若不符合，返回false
		return false;
	}
	else
	{
		return true;
	}
}

int main()
{
	vector<int> test;                                                         //容器，存储一个数字的每一位
	int n, k;                                                                 //n是数字的位数，k是每一位数值间的差
	cin >> n;
	cin >> k;
	if (Judge_legality(n, k))                                                 //判断输入的n、k是否合法，若合法，则执行相应功能；若不合法，则输出为空，结束程序
	{
		Func(n, k, test);
	}
	else
	{
		cout << " ";
	}
    system("pause");
	return 0;
}