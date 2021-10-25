#include"iostream"
#include"vector"
#include"algorithm"

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int num=nums.size();
        int left=0;
        int right=0;
        while(right<num)
        {
            if(nums[right])
            {
                swap(nums[left],nums[right]);
                left++;
            }
            right++;
        }
    }
};

