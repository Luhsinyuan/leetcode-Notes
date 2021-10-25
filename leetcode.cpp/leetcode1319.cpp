#include"iostream"
#include"vector"
//TODO     莫名其妙的BUG,不知道哪里出了问题，思路是没问题的。。。
using namespace std;

class Solution {
public:
    void Union(int m,int n,int UFsets[])
    {
        while(UFsets[m]>=0)
        {
            m=UFsets[m];
        }
        while(UFsets[n]>=0)
        {
            n=UFsets[n];
        }
        if(m==n)
        {
            return;
        }
        else
        {
            if(UFsets[m]<UFsets[n])
        {
            UFsets[m]=UFsets[m]+UFsets[n];
            UFsets[n]=m;
        }
        else
        {
            UFsets[n]=UFsets[m]+UFsets[n];
            UFsets[m]=n;
        }
        }
        return;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int spare_count=0;
        int UFsets[n];
        for(int i=0;i<n;i++)
        {
            UFsets[i]=-1;
        }
        for(int i=0;i<connections.size();i++)
        {
            Union(connections[i][0],connections[i][1],UFsets);
        }
        for(int i=0;i<n;i++)
        {
            if(UFsets[i]==-1)
            {
                spare_count++;
            }
        }
        if(connections.size()-(n-spare_count-1)>=spare_count)
        {
            return spare_count;
        }
        else
        {
            return -1;
        }
    }
};
int main()
{
    vector<vector<int>> temp={{0,1},{0,2},{3,4},{2,3}};
    Solution s;
    int result=s.makeConnected(5,temp);
    cout<<result<<endl;
    system("pause");
    return 0;
}