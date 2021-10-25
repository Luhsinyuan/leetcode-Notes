#include"iostream"
#include"vector"

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(target<nums[0]||target>nums[nums.size()-1])
            return -1;
        return binary_search(nums,0,nums.size(),target);
    }
    int binary_search(vector<int>& nums,int left,int right,int target)
    {
        while(left<right)
        {
            if(target==nums[(left+right)/2])
                return (left+right)/2;
            else if(target<nums[(left+right)/2])
            {
                right=(left+right)/2;
            }
            else if(target>nums[(left+right)/2])
            {
                left=(left+right)/2+1;
            }
        }
        return -1;
    }
};
int main()
{
    Solution s;
    vector<int> nums={5};
    int result=s.search(nums,5);
    cout<<result<<endl; 
    system("pause");
    return 0;
}