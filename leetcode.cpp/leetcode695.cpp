#include"iostream"
#include"vector"

using namespace std;

class Solution {
public:
    int cu_num=0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result=0;
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(!visited[i][j]&&grid[i][j]==1)
                {
                    cu_num=1;
                    visited[i][j]=true;
                    dfs(grid,i,j,visited);
                    result=max(result,cu_num);
                }
            }
        }
        return result;
    }
    void dfs(vector<vector<int>>& grid,int x,int y,vector<vector<bool>>& visited)
    {
        int direction_x[4]={0,0,1,-1};
        int direction_y[4]={1,-1,0,0};
        for(int i=0;i<4;i++)
        {
            int new_x=x+direction_x[i];
            int new_y=y+direction_y[i];
            if(new_x>=0&&new_x<grid.size()&&new_y>=0&&new_y<grid[0].size()&&!visited[new_x][new_y]&&grid[new_x][new_y]==1)
            {
                visited[new_x][new_y]=true;
                cu_num++;
                dfs(grid,new_x,new_y,visited);
            }
        }
        return;
    }
};
int main()
{
    vector<vector<int>> grid(2,vector<int>(3,0));
    grid[1][1]=1;
    grid[1][2]=1;
    grid[0][2]=1;
    Solution s;
    int result=s.maxAreaOfIsland(grid);
    cout<<result<<endl;
    system("pause");
    return 0;
}