#include"iostream"
#include"vector"
#include"algorithm"
#include"math.h"


using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int layer=triangle.size();
        vector<vector<int>> result(triangle);
        for(int i=0;i<result.size();i++)
        {
            for(int j=0;j<result[i].size();j++)
            {
                result[i][j]=0;
            }
        }
        result[0][0]=triangle[0][0];
        result[1][0]=triangle[0][0]+triangle[1][0];
        result[1][1]=triangle[0][0]+triangle[1][1];
        for(int i=2;i<result.size();i++)
        {
            for(int j=0;j<result[i].size();j++)
            {
                if(j==0)
                {
                    result[i][j]=triangle[i][j]+result[i-1][0];
                }
                else if(j==result[i].size()-1)
                {
                    result[i][j]=triangle[i][j]+result[i-1][j-1];
                }
                else 
                {
                    result[i][j]=triangle[i][j]+min(result[i-1][j],result[i-1][j-1]);
                }
            }
        }
        return result[layer-1][result[layer-1].size()-1];
    }
};