#include"iostream"
#include"vector"
#include"algorithm"
#include"math.h"


using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> result(matrix);
        if(matrix.size()==1)
        {
            return result[0][0];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j==0)
                {
                    result[i][j]=matrix[i][j]+min(result[i-1][0],result[i-1][1]);
                }
                else if(j==n-1)
                {
                    result[i][j]=matrix[i][j]+min(result[i-1][j-1],result[i-1][j]);
                }
                else 
                {
                    result[i][j]=matrix[i][j]+min(min(result[i-1][j+1],result[i-1][j]),result[i-1][j-1]);
                }
            }
        }
        int min_num=INT32_MAX;
        for(int i=0;i<n;i++)
        {
            min_num=min(min_num,result[n-1][i]);
        }
        return min_num;
    }
};
int main()
{
    vector<vector<int>> matrix={{-19,57},{-40,-5}};
    Solution s;
    int result=s.minFallingPathSum(matrix);
    return 0;
}