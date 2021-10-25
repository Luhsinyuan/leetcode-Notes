#include"iostream"
#include"vector"

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target<nums[0])
            return 0;
        else if(target>nums[nums.size()-1])
            return nums.size();
        int left=0;
        int right=nums.size();
        while(left<right)
        {
            if(target==nums[(left+right)/2])
                return (left+right)/2;
            else if(target<nums[(left+right)/2])
                right=(left+right)/2;
            else if(target>nums[(left+right)/2])
                left=(left+right)/2+1;
        }
        if(target<=nums[left])
            return left;
        else
            return left+1;
    }
};
int main()
{
    Solution s;
    vector<int> nums={1,3,5,6};
    int result=s.searchInsert(nums,2);
    cout<<result<<endl;
    system("pause");
    return 0;
}