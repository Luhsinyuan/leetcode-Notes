#include"iostream"
#include"vector"

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1)
        {
            return 0;
        }
        vector<int> jumps(nums.size(),INT32_MAX);
        jumps[0]=0;
        int jump_num=0;
        int begin=0;
        while(begin<nums.size())
        {
            jump_num=jumps[begin];
            for(int j=1;j<=nums[begin];j++)
            {
                jumps[begin+j]=jumps[begin+j]<jump_num+1?jumps[begin+j]:jump_num+1;
                // cout<<jumps[begin+j]<<endl;
                if(begin+j==nums.size()-1)
                    return jumps[nums.size()-1];
            }
            
            begin++;
        }
        return jumps[nums.size()-1];
    }
};
int main()
{
    vector<int> nums={1};
    Solution s;
    int result=s.jump(nums);
    cout<<result<<endl;
    system("pause");
    return 0;
}