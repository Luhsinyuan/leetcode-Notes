#include"iostream"
#include"vector"
#include"algorithm"
#include"queue"
using namespace std;
//TODO 动态规划问题，放假后搞明白。

    bool cmp(vector<int> a,vector<int> b)
    {
        if(a[1]<b[1])
        {
            return true;
        }
        return false;
    }
class Solution {
public:

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> v;
        for(int i=0;i<prices.size();i++)
        {
            v.push_back({i,prices[i]});
        }
        sort(v.begin(),v.end(),cmp);


        int fir=0;
        int end=prices.size()-1;
        while(v[fir][0]>v[end][0])
        {
            fir++;
        }
        return v[end][1]-v[fir][1];
    }
};

int main()
{
    Solution s;
    vector<int> temp={7,1,5,3,6,4};
    
    cout<<s.maxProfit(temp)<<endl;
    system("pause");
    return 0;
}