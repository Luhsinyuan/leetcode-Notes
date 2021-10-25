#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int cout_times=-1;                                                       //�����ж��ǲ��ǵ�һ���������
 
void Print_out(int n,int k,vector<int>& numlist)                                //�������
{
    cout_times++;
	ofstream fout;
	fout.open("print_test.txt", ios_base::app | ios_base::out);                                     
	if(cout_times>0)                                                         //���ڶ��ŵ��ж�
    {
        cout<<",";
        fout<<",";
    }
    for (int i = 0; i < n; i++)
	{
		cout << numlist[i];                                                    //����������ֵ�ÿһλ
		fout << numlist[i];
	}
	fout.close();
}



void recu_func(int n, int k, vector<int>& numlist)
{
	if (numlist.size() == n)                        //��ÿһλ��������ʱ�����������
	{
		Print_out(n,k,numlist); 
        return;
	}
	else
	{
		if (numlist.size() == 0)                   //��������û����ֵ��ȷ�����ֵ�һλ��ֵ����ΧΪ1-9
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
			if (k != 0 && temp + k <= 9)            //��kΪ0ʱ��ȷ����һλ��ֵ�Ĳ���ֻ����һ��
			{
				numlist.push_back(temp + k);
				recu_func(n, k, numlist);
				numlist.pop_back();
			}
		}
	}
}





bool is_legal(int n, int k)                                                    //�ж�n��k�ĺϷ���
{
	if (k < 0 || k > 9||n <= 1)                                                //��Ҫ�������λ��nӦ����һ������1����������ÿһλ��ֵ��Ĳ�k
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
	int n, k;                    
    cout<<"������n"<<endl;
                                                                             //n�����ֵ�λ����k��ÿһλ��ֵ��Ĳ�
	cin >> n;

    cout<<"������k"<<endl;

	cin >> k;
	if (is_legal(n, k))                                                  //�ж������n��k�Ƿ�Ϸ������Ϸ�����ݹ飻�����Ϸ��������Ϊ�գ���������
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