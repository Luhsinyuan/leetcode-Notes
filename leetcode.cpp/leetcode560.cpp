#include"iostream"
#include"vector"
#include"unordered_map"

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp; 
        mp[0]=1;
        int pre=0;
        int result=0;
        for(int num:nums)
        {
            pre+=num;
            if(mp.find(pre-k)!=mp.end())
            {
                result+=mp[pre-k];
            }
            mp[pre]++;
        }  
        return result;     
    }
};