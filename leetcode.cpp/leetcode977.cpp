#include"iostream"
#include"vector"
#include"algorithm"

using namespace std;

// Solution 1
/*
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
            nums[i]=nums[i]*nums[i];
        sort(nums.begin(),nums.end());
        return nums;
    }
};
*/
// Solution 2 Ë«Ö¸Õë
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int num=nums.size();
        vector<int> ans(num);
        for(int i=0,j=num-1,pos=num-1;i<j;)
            {
                if(nums[i]*nums[i]>nums[j]*nums[j])
                {
                    ans[pos]=nums[i]*nums[i];
                    i++;
                }
                else 
                {
                    ans[pos]=nums[j]*nums[j];
                    j--;
                }
                pos--;
            }
        return ans;
    }
};

