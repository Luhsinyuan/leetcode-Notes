#include"iostream"
#include"vector"
#include"algorithm"
#include"math.h"


using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        result.push_back(1);
        for(int i=1;i<=rowIndex;i++)
        {
            vector<int> temp=result;
            result.clear();
            for(int j=0;j<=i;j++)
            {
                if(j==0)
                {
                    result.push_back(temp[0]);
                }
                else if(j==i)
                {
                    result.push_back(temp[i-1]);
                }
                else 
                {
                    result.push_back(temp[j]+temp[j-1]);
                }
            }
        }
        return result;
    }
};