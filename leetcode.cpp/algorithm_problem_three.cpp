#include"iostream"
#include"vector"
#include"algorithm"


using namespace std;
bool cmp(vector<int> numlist1,vector<int> numlist2)         //����ʵ�ֵıȽ��㷨�����ڰ����Ҷ˵��С����
{
    return numlist1[1]<numlist2[1];
   
}

int min_remove(vector<vector<int>> intervals)               
{
    sort(intervals.begin(),intervals.end(),cmp);            //�Ƚ���������Ҷ˵�����
    int end=intervals[0][1];                                //ȡ����һ�������Ҷ˵㣬Ҫ����һ����Ҫ�����������
    int num=1;                                              //��һ��
    for(int i=1;i<intervals.size();i++)                     //��ͷ��β�������еļ��
    {
        if(intervals[i][0]>=end)                            //�����ÿ�������˵������һ����Ҷ˵㣬��ô֤����һ���ǲ��ص��ģ�
                                                            //�������ڰ����Ҷ˵��Ź����ˣ���һ�������Ҷ˵�����������Ҫ��ļ������С�ģ��������ŵ�
        {
            end=intervals[i][1];                            //��¼��һ����Ҷ˵�
            num++;                                          //����
        }
    }
    return intervals.size()-num;                            //������ȥ�������Ŀ�����ʣ�µľ�����Ҫȥ����
}

int main()
{
    vector<vector<int>> temp;
    temp.push_back({1,2});
    temp.push_back({2,3});
    //temp.push_back({1,2});
    //temp.push_back({1,3});
    for(int i=0;i<temp.size();i++)
    {
        cout<<"[";
        for(int j=0;j<2;j++)
        {
            cout<<temp[i][j];
            if(j==0)
            {
                cout<<",";
            }
        }
        cout<<"]";
    }
    cout<<endl;
    cout<<min_remove(temp)<<endl;
    system("pause");
    return 0;

}
