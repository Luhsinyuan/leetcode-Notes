#include"iostream"
#include"vector"

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size=nums.size();
        if(size==0)
        {
            return 0;
        }
        int slow=0;
        int fast=0;
        while(fast<size)
        {
            if(nums[fast]!=val)
            {
                nums[slow]=nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
};
int main()
{
    vector<int> nums={3,2,3,2,3,2,3,2,3};
    Solution s;
    int result=s.removeElement(nums,2);
    for(int i=0;i<result;i++)
    {
        cout<<nums[i]<<endl;
    }
    system("pause");
    return 0;
}