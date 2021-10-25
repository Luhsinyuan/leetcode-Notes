#include"iostream"
#include"vector"

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> sum;
        sum.push_back(0);
        int sum_temp=0;
        int max=INT64_MIN;
        for(int i=0;i<nums.size();i++)
        {
            sum_temp+=nums[i];
            sum.push_back(sum_temp);
        }
        int min=sum[0];
        for(int i=1;i<sum.size();i++)
        {
            if(sum[i]-min>max)
            {
                max=sum[i]-min;
            }
            min=min<sum[i]?min:sum[i];
        }
        return max;
    }
};
int main()
{
    vector<int> nums={-1};
    Solution s;
    int result=s.maxSubArray(nums);
    cout<<result<<endl;
    system("pause");
    return 0;
}