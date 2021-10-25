#include"iostream"
#include"vector"


using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> max_num(prices.size()+1,0);
        max_num[0]=0;
        max_num[1]=0;
        for(int i=0;i<max_num.size();i++)
        {
            max_num[i]=max(max_num[i-1],max_num[i-2]+prices)
        }
    }
};