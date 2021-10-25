#include"iostream"
#include"vector"

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> nums(n+1);
        nums[0]=1;
        nums[1]=1;
        for(int i=2;i<=n;i++)
        {
            nums[i]=nums[i-2]+nums[i-1];
        }
        return nums[n];
    }
};