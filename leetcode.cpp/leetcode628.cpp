#include"iostream"
#include"vector"
#include"algorithm"
using namespace std;
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            cout<<nums[i]<<endl;
        }
        return max(nums[0]*nums[1]*nums[nums.size()-1],nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3]);
    }
};
int main()
{
    vector<int> nums={-100,-99,1,2,3};
    Solution s;
    int result=s.maximumProduct(nums);
    cout<<result<<endl;
    system("pause");
    return 0;
}