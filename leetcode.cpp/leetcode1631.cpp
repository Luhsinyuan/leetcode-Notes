#include"iostream"
#include"vector"
#include"algorithm"
#include"cmath"

using namespace std;

class Solution {
public:
    int direction[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    
    void dfs(bool visited[],int x,int y,vector<vector<int>>& heights,int row,int col,int& min_cost,int& temp,int sub)
    {   
        if(x==row-1&&y==col-1)
        {
            min_cost=min(temp,min_cost);
        }
        else
        {
            for(int x=0;x<row;x++)
        {
            for(int y=0;y<col;y++)
            {
                for(int i=0;i<4;i++)
                {
                    int to_x=x+direction[i][0];
                    int to_y=y+direction[i][1];
                    if(to_x<row&&to_y<col&&to_x>=0&&to_y>=0&&visited[to_x*col+to_y]==0)
                    {
                        
                        int t_sub=heights[x][y]-heights[to_x][to_y];
                        temp=min(sub,temp);
                        dfs(visited,to_x,to_y,heights,row,col,min_cost,temp,t_sub);
                        visited[to_x*col+to_y]=0;
                    }
                }
            }
        }
        }
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row=heights.size();
        int col=heights[0].size();
        bool visited[row*col]{0}; 
        int min_cost=1000000;
        int temp=1000000;
        int sub=0;
        dfs(visited,0,0,heights,row,col,min_cost,temp,sub);
        return min_cost;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> heights{{1,2,2},{3,8,2},{5,3,5}};
    int result=s.minimumEffortPath(heights);
    cout<<result<<endl;
    system("pause");
    return 0;
}