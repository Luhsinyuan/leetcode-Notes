#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void Put_out(int n,int k,vector<int>& ans);//�����������

//===============================================��ɸù��ܵĺ���===========================================

void Func(int n, int k, vector<int>& numlist)
{
	if (numlist.size() == n - 1)                     //����������λ��Ϊn-1ʱ���������һλ�����⻯����Ҳ�ǵݹ����ֹ����
	{
		int temp = numlist[n - 2];                   //���ݵ�n-1λ������ȷ�����һλ��ֵ�������Ϲ淶��ֵ���������й�������������
		if (temp - k >= 0)
		{
			numlist.push_back(temp - k);
			Put_out(n,k,numlist);
			numlist.pop_back();
		}
		if (k != 0 && temp + k <= 9)            //��kΪ0ʱִֻ��һ���������
		{
			numlist.push_back(temp + k);
			Put_out(n,k,numlist);
			numlist.pop_back();
		}
		return;
	}
	else
	{
		if (numlist.size() == 0)                   //��������û����ֵʱȷ�����ֵ�һλ��ֵ����ΧΪ1-9
		{
			for (int i = 1; i <= 9; i++)
			{
				numlist.push_back(i);
				Func(n, k, numlist);
				numlist.pop_back();
			}
		}
		else                                   //�������е���ֵλ��Ϊһ����������0���ǵ����ڶ�λ��ʱ������ֵ����һ�㻯��������
		{                                      //ǰһλ����ֵȷ����һλ����ֵ��������ݹ�������иò���
			int temp = numlist.back();
			if (temp - k >= 0)
			{
				numlist.push_back(temp - k);
				Func(n, k, numlist);
				numlist.pop_back();
			}
			if (k != 0 && temp + k <= 9)       //��kΪ0ʱ��ȷ����һλ��ֵ�Ĳ���ֻ����һ��
			{
				numlist.push_back(temp + k);
				Func(n, k, numlist);
				numlist.pop_back();
			}
		}
	}
}

//=========================================================�������=========================================================

void Put_out(int n,int k,vector<int>& numlist)
{
	ofstream fout;
	fout.open("test.txt", ios_base::app | ios_base::out);
	int max_symbol = numlist[0] == 9 ? 1 : 0;                                       //�жϵ�ǰ�����е������ǲ�������������ǣ����ʶ��Ϊ1�������ǣ����ʶ��Ϊ0
	for (int i = 0; i < n; i++)
	{
		cout << numlist[i];                                                         //����������ֵ�ÿһλ
		fout << numlist[i];
		if (max_symbol == 1)                                                    //�жϸ����ǲ�������������ż��λ��ֵ��Ϊ9������λ��ֵ����9-k,
		{                                                                       //�����������������ʶ����Ϊ1������һ����������������������ʶ����Ϊ0
			if ((i % 2 == 1 && numlist[i] == 9 - k) || (i % 2 == 0 && numlist[i] == 9))
			{

			}
			else
			{
				max_symbol = 0;
			}
		}
	}
	if (max_symbol == 0)                                                        //�ڳ����һ�����֣������ֵ����������������������
	{
		cout << ",";
		fout << ",";
	}
	fout.close();
}

//===================================================�����n,kֵ�ĺϷ����жϺ���=========================================

bool Judge_legality(int n, int k)
{
	if (n <= 1 || k < 0 || k > 9)                                              //��Ҫ�������λ��nӦ����һ������1����������ÿһλ��ֵ��Ĳ�k
	{                                                                          //Ӧ����0-8��һ��������������Ҫ�󣬷���true���������ϣ�����false
		return false;
	}
	else
	{
		return true;
	}
}

int main()
{
	vector<int> test;                                                         //�������洢һ�����ֵ�ÿһλ
	int n, k;                                                                 //n�����ֵ�λ����k��ÿһλ��ֵ��Ĳ�
	cin >> n;
	cin >> k;
	if (Judge_legality(n, k))                                                 //�ж������n��k�Ƿ�Ϸ������Ϸ�����ִ����Ӧ���ܣ������Ϸ��������Ϊ�գ���������
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