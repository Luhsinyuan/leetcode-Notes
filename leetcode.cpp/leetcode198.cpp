#include"iostream"
#include"vector"

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> max_num(nums.size()+1);
        max_num[0]=0;
        max_num[1]=nums[0];
        for(int i=2;i<=nums.size();i++)
        {
            max_num[i]=max(max_num[i-1],max_num[i-2]+nums[i-1]);
        }
        return max_num[nums.size()];
    }
};
int main()
{
    vector<int> temp={1,2,3,1};
    Solution s;
    int result =s.rob(temp);
    cout<<result<<endl;
    system("pause");
    return 0;
}