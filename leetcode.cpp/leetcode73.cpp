#include"iostream"
#include"vector"

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int lines=matrix[0].size();
        vector<int> zero_rows;
        vector<int> zero_lines;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<lines;j++)
            {
                if(matrix[i][j]==0)
                {
                    zero_rows.push_back(i);
                    zero_lines.push_back(j);
                }
            }
        }
        while(!zero_rows.empty())
        {
            for(int m=0;m<lines;m++)
            {
                matrix[zero_rows.back()][m]=0;
            }
            zero_rows.pop_back();
        }
        while(!zero_lines.empty())
        {
            for(int m=0;m<rows;m++)
            {
                matrix[m][zero_lines.back()]=0;
            }
            zero_lines.pop_back();
        }
    }
};
int main()
{
    Solution s;
    vector<vector<int>> v;
    v.push_back({1,1,1});
    v.push_back({0,1,1});
    v.push_back({1,1,1});
    s.setZeroes(v);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<v[i][j]<<"    ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}