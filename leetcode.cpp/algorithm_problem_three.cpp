#include"iostream"
#include"vector"
#include"algorithm"


using namespace std;
bool cmp(vector<int> numlist1,vector<int> numlist2)         //自我实现的比较算法，用于按照右端点大小排序
{
    return numlist1[1]<numlist2[1];
   
}

int min_remove(vector<vector<int>> intervals)               
{
    sort(intervals.begin(),intervals.end(),cmp);            //先将间隔按照右端点排序
    int end=intervals[0][1];                                //取到第一块间隔的右端点，要求下一块间隔要大于这个数字
    int num=1;                                              //计一块
    for(int i=1;i<intervals.size();i++)                     //从头到尾遍历所有的间隔
    {
        if(intervals[i][0]>=end)                            //倘若该块间隔的左端点大于上一块的右端点，那么证明这一块是不重叠的，
                                                            //而且由于按照右端点排过序了，这一块间隔的右端点是所有满足要求的间隔中最小的，即是最优的
        {
            end=intervals[i][1];                            //记录这一块的右端点
            num++;                                          //计数
        }
    }
    return intervals.size()-num;                            //总数减去留下来的块数，剩下的就是需要去掉的
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
