#include"iostream"
#include"vector"

using namespace std;

class Solution {
public:
    int result=0; 
    int directx[4]={-1,1,0,0};
    int directy[4]={0,0,1,-1};
    int numIslands(vector<vector<char>>& grid) {
        int total_han=grid.size();
        if(total_han==0)
        {
            return 0;
        }
        int total_cul=grid[0].size();
        for(int i=0;i<total_han;i++)
        {
            for(int j=0;j<total_cul;j++)
            {
                if(grid[i][j]=='1')
                {
                    result++;
                    grid[i][j]='0';
                    dfs(i,j,grid);
                }
            }
        }
        return result;
    }
    void dfs(int x,int y,vector<vector<char>>& grid)
    {
        for(int i=0;i<4;i++)
        {
            int ix=x+directx[i];
            int iy=y+directy[i];
            if(isLegal(ix,iy,grid))
            {
                grid[ix][iy]='0';
                dfs(ix,iy,grid);
            }
        }
        return;
        
    }
    bool isLegal(int x,int y,vector<vector<char>>& grid)
    {
        if((x>=0&&x<grid.size())&&(y>=0&&y<grid[0].size())&&grid[x][y]=='1')
        {
            return true;
        }
        return false;
    }
};
int main()
{
    vector<vector<char>> grid{
  {'1','1','1','1','0'},
  {'1','1','0','1','0'},
  {'1','1','0','0','0'},
  {'0','0','0','0','0'}
    };
    Solution s;
    int result=s.numIslands(grid);
    cout<<result<<endl;
    system("pause");
    return 0;
}