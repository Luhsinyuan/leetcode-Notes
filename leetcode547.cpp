#include"iostream"
#include"vector"
using namespace std;

class Solution {
public:
    void Unoin(int i,int j,vector<int>& list,int& count)
    {
        while(list[i]>0)
        {
            i=list[i];
        }
        while(list[j]>0)
        {
            j=list[j];
        }
        if(i==j)
        {
            return;
        }
        else
        {
            if(list[i]<list[j])
            {
                list[j]=i;
                list[i]--;
            }
            else
            {
                list[i]=j;
                list[j]--;
            }
            count--;
            return;  
        }
    }
    int UFsets(vector<vector<int>> temp)
    {
        int num=temp.size();
        int count=num;
        vector<int> list(num);
        for(int i=0;i<num;i++)
        {
            list[i]=-1;
        }
        for(int i=0;i<num;i++)
        {
            for(int j=0;j<temp[i].size();j++)
            {
                if(temp[i][j]==1)
                {
                    if(i!=j)
                    {
                        Unoin(i,j,list,count);
                    }
                }
            }
        }

        return count;
         
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
       return UFsets(isConnected);
    }
};
int main()
{
    vector<vector<int>> v;
    v.push_back({1});
   /* v.push_back({0,1,1,1});
    v.push_back({1,1,1,0});
    v.push_back({0,1,0,1});*/
    Solution s;
    cout<<s.findCircleNum(v)<<endl;
    system("pause");
    return 0;
}