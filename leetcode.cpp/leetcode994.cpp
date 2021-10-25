#include"iostream"
#include"vector"
#include"queue"

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        vector<vector<int>> step(grid.size(),vector<int>(grid[0].size(),0));
        queue<pair<int ,int>> q;
        int direction_x[4]={1,-1,0,0};
        int direction_y[4]={0,0,1,-1};
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                {
                    visited[i][j]=true;
                    q.emplace(make_pair(i,j));
                }
                else if(grid[i][j]==1)
                {
                    step[i][j]=-1;
                }
            }
        }
        while(!q.empty())
        {
            pair<int ,int> temp=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int new_x=temp.first+direction_x[i];
                int new_y=temp.second+direction_y[i];
                if(new_x>=0&&new_x<grid.size()&&new_y>=0&&new_y<grid[0].size()&&!visited[new_x][new_y]&&grid[new_x][new_y]==1)
                {
                    visited[new_x][new_y]=true;
                    step[new_x][new_y]=step[temp.first][temp.second]+1;
                    q.emplace(make_pair(new_x,new_y));
                }
            }
        }
        int max_num=0;
        for(int i=0;i<step.size();i++)
        {
            for(int j=0;j<step[0].size()j++)
            {
                if(step[i][j]==-1)
                {
                    return -1;
                }
                else
                {
                    max_num=max(max_num,step[i][j]);
                }
            }
        }
        return max_num;
    }
};