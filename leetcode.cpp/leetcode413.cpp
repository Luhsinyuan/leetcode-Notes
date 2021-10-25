#include"iostream"
#include"vector"
#include"algorithm"
#include"math.h"


using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<3)
            return 0;
        vector<int> ans(nums.size()+1,0);
        ans[0]=0;
        ans[1]=0;
        ans[2]=0;
        for(int i=3;i<=ans.size();i++)
        {
            int j=i;
            while(j>0)
            {
                ans[i]+=ans[j-1];
                j--;
            }
            for(int x=i-3;x>=0;x--)
            {
                if(check(x,i-1,nums))
                    ans[i]++;
            }
        }
        return ans[nums.size()];
    }
    bool check(int start,int end,vector<int> nums)
    {
        for(int i=start;i+2<=end;i++)
        {
            if(nums[i+1]-nums[i]!=nums[i+2]-nums[i+1])
                return false;
        }
        return true;
    }
};
int main()
{
    vector<int> nums={1,2,3,4};
    Solution s;
    int result=s.numberOfArithmeticSlices(nums);
    return 0;
}