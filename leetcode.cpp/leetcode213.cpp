#include"iostream"
#include"vector"

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> max_num(nums.size());
        max_num[0]=0;
        max_num[1]=nums[0];
        for(int i=2;i<nums.size();i++)
        {
            max_num[i]=max(max_num[i-1],max_num[i-2]+nums[i-1]);
        }
        int num1=max_num[nums.size()-1];
        max_num[1]=nums[1];
        for(int i=2;i<nums.size();i++)
        {
            max_num[i]=max(max_num[i-1],max_num[i-2]+nums[i]);
        }
        int num2=max_num[nums.size()-1];
        return max(num1,num2);
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