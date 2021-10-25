#include"iostream"
#include"vector"

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<bool>> visited(image.size(),vector<bool>(image[0].size(),false));
        visited[sr][sc]=true;
        int target=image[sr][sc];
        image[sr][sc]=newColor;
        dfs(image,sr,sc,newColor,target,visited);
        return image;
    }
    void dfs(vector<vector<int>>& image,int x,int y,int newColor,int target,vector<vector<bool>>& visited)
    {
        int direction_x[4]={0,0,1,-1};
        int direction_y[4]={1,-1,0,0};
        for(int i=0;i<4;i++)
        {
            int new_x=x+direction_x[i];
            int new_y=y+direction_y[i];
            if(new_x>=0&&new_x<image.size()&&new_y>=0&&new_y<image[0].size()&&!visited[new_x][new_y]&&image[new_x][new_y]==target)
            {
                image[new_x][new_y]=newColor;
                visited[new_x][new_y]=true;
                dfs(image,new_x,new_y,newColor,target,visited);

            }
        }
        return;
    }
};
int main()
{
    vector<vector<int>> image(2,vector<int>(3,0));
    image[1][1]=1;
    image[1][2]=1;
    image[0][2]=1;
    Solution s;
    vector<vector<int>> result=s.floodFill(image,1,1,1);
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[0].size();j++)
        {
            cout<<result[i][j]<<",";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}