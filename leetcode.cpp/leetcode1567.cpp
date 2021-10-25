#include"iostream"
#include"vector"

using namespace std;

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int pre_posi=0;
        int pre_nega=0;
        if(nums[0]>0)
            pre_posi=1;
        else if(nums[0]<0)
            pre_nega=1;
        int result=pre_posi;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>0)
            {
                pre_nega=pre_nega==0?0:pre_nega+1;
                pre_posi=pre_posi+1;
            }
            else if(nums[i]<0)
            {
                int new_pre_posi=pre_nega==0?0:pre_nega+1;
                int new_pre_nega=pre_posi+1;
                pre_posi=new_pre_posi;
                pre_nega=new_pre_nega;
            }
            else if(nums[i]==0)
            {
                pre_nega=0;
                pre_posi=0;
            }
            result=max(result,pre_posi);
        }
        return result;
    }
};
int main()
{
    vector<int> nums={1,-2,-3,4};
    Solution s;
    int result=s.getMaxLen(nums);
    system("pause");
    return 0;
}