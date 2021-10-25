#include"iostream"
#include"vector"
#include"algorithm"
#include"math.h"


using namespace std;

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> t_sum(m+1,vector<int>(n+1,0));
        for(int i=0;i<m+1;i++)
        {
            t_sum[i][0]=0;
        }
        for(int j=0;j<n+1;j++)
        {
            t_sum[0][j]=0;
        }
        int target=1;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                int sum=t_sum[i][j-1]+t_sum[i-1][j]-t_sum[i-1][j-1]+mat[i-1][j-1];
                t_sum[i][j]=sum;
            }
        }
        vector<vector<int>> result(m,vector<int>(n,0));
        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                int rd_x=i+k<=m?i+k:m;
                int rd_y=j+k<=n?j+k:n;
                int ru_x=i-k-1>=0?i-k-1:0;
                int ru_y=j-k-1>=0?j-k-1:0;
                int temp=t_sum[rd_x][rd_y]-t_sum[rd_x][ru_y]-t_sum[ru_x][rd_y]+t_sum[ru_x][ru_y];
                result[i-1][j-1]=temp;
            }
        }
        return result;
    }
};
int main()
{
    vector<vector<int>> mat={{1,2,3},{4,5,6},{7,8,9}};
    Solution s;
    vector<vector<int>> result=s.matrixBlockSum(mat,1);
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[0].size();j++)
        {
            cout<<result[i][j]<<endl;
        }
    }
    return 0;
}