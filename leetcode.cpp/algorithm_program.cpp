#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int cout_times=-1;                                                       //用来判断是不是第一输出的数字
 
void Print_out(int n,int k,vector<int>& numlist)                                //输出函数
{
    cout_times++;
	ofstream fout;
	fout.open("print_test.txt", ios_base::app | ios_base::out);                                     
	if(cout_times>0)                                                         //对于逗号的判断
    {
        cout<<",";
        fout<<",";
    }
    for (int i = 0; i < n; i++)
	{
		cout << numlist[i];                                                    //逐项输出数字的每一位
		fout << numlist[i];
	}
	fout.close();
}



void recu_func(int n, int k, vector<int>& numlist)
{
	if (numlist.size() == n)                        //当每一位都有数字时，输出该数字
	{
		Print_out(n,k,numlist); 
        return;
	}
	else
	{
		if (numlist.size() == 0)                   //当容器中没有数值，确定数字第一位的值，范围为1-9
		{
			for (int i = 1; i <= 9; i++)
			{
				numlist.push_back(i);
				recu_func(n, k, numlist);
				numlist.pop_back();
			}
		}
		else                                   
		{                                      
			int temp = numlist.back();
			if (temp - k >= 0)
			{
				numlist.push_back(temp - k);
				recu_func(n, k, numlist);
				numlist.pop_back();
			}
			if (k != 0 && temp + k <= 9)            //当k为0时，确定下一位数值的操作只进行一次
			{
				numlist.push_back(temp + k);
				recu_func(n, k, numlist);
				numlist.pop_back();
			}
		}
	}
}





bool is_legal(int n, int k)                                                    //判断n和k的合法性
{
	if (k < 0 || k > 9||n <= 1)                                                //依要求，输入的位数n应该是一个大于1的正整数，每一位数值间的差k
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
	int n, k;                    
    cout<<"请输入n"<<endl;
                                                                             //n是数字的位数，k是每一位数值间的差
	cin >> n;

    cout<<"请输入k"<<endl;

	cin >> k;
	if (is_legal(n, k))                                                  //判断输入的n、k是否合法，若合法，则递归；若不合法，则输出为空，结束程序
	{
		recu_func(n, k, test);
	}
	else
	{
		cout << " ";
	}
    system("pause");
	return 0;
}