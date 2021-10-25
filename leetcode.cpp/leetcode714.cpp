#include"iostream"
#include"vector"


using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> ans(prices.size(),vector<int>(2));
        ans[0][0]=0;
        ans[0][1]=-prices[0];
        for(int i=1;i<prices.size();i++)
        {
            ans[i][0]=max(ans[i-1][0],ans[i-1][1]+prices[i]-fee);
            ans[i][1]=max(ans[i-1][1],ans[i-1][0]-prices[i]);
        }
        return ans[prices.size()-1][0];
    }
};
int main()
{
    vector<int> price={1,3,2,8,4,9};
    Solution s;
    int result=s.maxProfit(price,2);
    return 0;
}