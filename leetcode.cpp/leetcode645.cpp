#include"iostream"
#include"vector"
#include"algorithm"

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> result;
        if(nums[0]!=1)
        {
            result.insert(result.end(),1);
        }
        if(nums[nums.size()-1]!=nums.size())
        {
            result.insert(result.end(),nums.size());
        }
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
            {
                result.insert(result.begin(),nums[i]);
            }
            if(nums[i]-nums[i-1]==2)
            {
                result.insert(result.end(),nums[i-1]+1);
            }
        }
        return result;
    }
};
int main()
{
    vector<int> temp={3,2,2};
    Solution s;
    vector<int> result=s.findErrorNums(temp);
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<endl;
    }
    system("pause");
    return 0;
}