#include"iostream"
#include"vector"

using namespace std;

class Solution {
public:
    int result=1;
    int directx[4]={0,0,1,-1};
    int directy[4]={1,-1,0,0};
    int movingCount(int m, int n, int k) {
        vector<vector<bool> > visited(m,vector<bool>(n,false));
        visited[0][0]=true;
        dfs(0,0,k,m,n,visited);
        return result;
    }
    void dfs(int x,int y,int k,int m,int n,vector<vector<bool>>& visited)
    {
        for(int i=0;i<4;i++)
        {
            int ix=x+directx[i];
            int iy=y+directy[i];
            if(isLegal(ix,iy,k,m,n)&&!visited[ix][iy])
            {
                result++;
                visited[ix][iy]=1;
                dfs(ix,iy,k,m,n,visited);
            }
        }
    }
    bool isLegal(int x,int y,int k,int m,int n)
    {
        if(x>=m||x<0||y>=n||y<0)
            return false;
        int sum=0;
        int current=0;
        while(x>0)
        {
            current=x%10;
            x=x/10;
            sum+=current;
        }
        while(y>0)
        {
            current=y%10;
            y/=10;
            sum+=current;
        }
        if(sum>k)
            return false;
        return true;
    }
};
int main()
{
    Solution s;
    int result=s.movingCount(2,3,1);
    cout<<result<<endl;
    system("pause");
    return 0;
}