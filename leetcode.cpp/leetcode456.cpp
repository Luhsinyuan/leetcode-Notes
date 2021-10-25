#include"iostream"
#include"vector"
#include"stack"

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int length=nums.size();
        stack<int> dandiao;
        int two=INT64_MIN;
        dandiao.push(nums[length-1]);
        for(int i=length-2;i>=0;i--)
        {
            if(nums[i]<two)
            {
                return true;
            }
            while(!dandiao.empty()&&nums[i]>dandiao.top())
            {
                two=dandiao.top();
                dandiao.pop();
            }
            if(nums[i]>two)
            {
                dandiao.push(nums[i]);
            }
        }
        return false;
    }
};
int main()
{
    vector<int> nums={1,0,1,-4,-3};
    Solution s;
    if(s.find132pattern(nums))
    {
        cout<<"yes"<<endl;
    }
    else
    {
        cout<<"no"<<endl;
    }
    system("pause");
    return 0;
}