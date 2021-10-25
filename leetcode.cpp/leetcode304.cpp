#include"iostream"
#include"vector"
#include"algorithm"
#include"math.h"


using namespace std;

class NumMatrix {
public:
    vector<vector<int>> t_sum;  
    NumMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> temp(m+1,vector<int>(n+1,0));
        for(int i=0;i<m+1;i++)
        {
            temp[i][0]=0;
        }
        for(int j=0;j<n+1;j++)
        {
            temp[0][j]=0;
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                temp[i][j]=temp[i][j-1]+temp[i-1][j]-temp[i-1][j-1]+matrix[i-1][j-1];
                // temp[i][j]=cur;

            }
        }
        t_sum=temp;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return t_sum[row2+1][col2+1]-t_sum[row2+1][col1>=0?col1:0]-t_sum[row1>=0?row1:0][col2+1]+t_sum[row1>=0?row1:0][col1>=0?col1:0];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
int main()
{
    vector<vector<int>> mat={{-1}};
    NumMatrix* Obj=new NumMatrix(mat);
    int result=Obj->sumRegion(0,0,0,0);
    cout<<result<<endl;
    return 0;
}