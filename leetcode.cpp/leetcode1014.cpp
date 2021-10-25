#include"iostream"
#include"vector"

using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxnum=0;
        int left=0;
        int right=0;
        vector<int> ans(values.size(),0);
        ans[0]=values[0];
        for(int i=1;i<values.size();i++)
        {
            maxnum=max(maxnum,left-i+values[i]+values[left]);
            if(maxnum==left-i+values[i]+values[left])
            {
                right=i;
            }
        }
        return maxnum;
    }
};