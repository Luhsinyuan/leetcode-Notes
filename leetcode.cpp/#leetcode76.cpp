#include"iostream"
#include"vector"

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        int num=cost.size();
        int dp[num];
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<cost.size();i++)
        {
            dp[i]=min(dp[i-1]+cost[i],dp[i-2]+cost[i]);
        }
        return dp[num-1];
    }
};
int main()
{
    vector<int> cost={1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    Solution s;
    int result=s.minCostClimbingStairs(cost);
    cout<<result<<endl;
    system("pause");
    return 0;
}