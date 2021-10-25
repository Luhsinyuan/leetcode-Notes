#include"iostream"
#include"vector"
#include"algorithm"
using namespace std;
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> num;
        int top=0;
        if(nums.size()!=0)
        {
            num.push_back(nums[0]);
            top++;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=num[top])
            {
                num.push_back(nums[i]);
                i++;
                top++;
            }
            else
            {
                i++;
            }
        }
    }
    
    int add(int val) {

    }
};