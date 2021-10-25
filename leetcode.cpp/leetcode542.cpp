#include"iostream"
#include"vector"
#include"queue"

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> ans(mat.size(),vector<int>(mat[0].size(),0));
        vector<vector<bool>> visited(mat.size(),vector<bool>(mat[0].size(),false));
        int direction_x[4]={1,-1,0,0};
        int direction_y[4]={0,0,1,-1};
        queue<pair<int,int>> q;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==0)
                {
                    q.emplace(make_pair(i,j));
                    visited[i][j]=true;
                }
            }
        }
        while(!q.empty())
        {
            pair<int ,int> temp=q.front();
            for(int i=0;i<4;i++)
            {
                int new_x=temp.first+direction_x[i];
                int new_y=temp.second+direction_y[i];
                if(new_x>=0&&new_x<mat.size()&&new_y>=0&&new_y<mat[0].size()&&!visited[new_x][new_y])
                {
                    visited[new_x][new_y]=true;
                    ans[new_x][new_y]=ans[temp.first][temp.second]+1;
                    q.emplace(make_pair(new_x,new_y));
                }
            }
            q.pop();
        }
        return ans;
    }
    
};
int main()
{
    vector<vector<int>> mat(3,vector<int>(3,0));
    mat[1][1]=1;
    mat[2][0]=1;
    mat[2][1]=1;
    mat[2][2]=1;
    Solution s;
    vector<vector<int>> ans=s.updateMatrix(mat);
    return 0;
}