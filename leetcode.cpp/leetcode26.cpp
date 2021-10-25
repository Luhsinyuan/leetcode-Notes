#include"iostream"
#include"vector"

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow=1;
        int fast=1;
        while(fast<nums.size())
        {
            if(nums[fast]!=nums[fast-1])
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
    vector<int> test={1,1,2};
    Solution s;
    int result =s.removeDuplicates(test);
    cout<<result<<endl;
    for(int i=0;i<result;i++)
    {
        cout<<test[i]<<endl;
    }
    system("pause");
    return 0;
}