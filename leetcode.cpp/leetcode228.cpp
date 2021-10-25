#include"iostream"
#include"vector"
#include"string"
using namespace std;
// TODO:整形转换为字符串，恶心人
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int i=0;
        int n=nums.size();
        int low=0;
        int high=0;
        while(i<n)
        {
            low=i;
            i++;
            while(i<n&&nums[i]==nums[i-1]+1)
            {
                i++;
            }
            high=i-1;
            string temp=to_string(nums[low]);
            if(low<high)
            {
                temp.append("->");
                temp.append(to_string(nums[high]));
            }
            result.emplace_back(temp);
        }
        return result;
    }
};
int main()
{
    vector<int> v={-1};
    Solution s;
    vector<string> test=s.summaryRanges(v);
    for(int i=0;i<test.size();i++)
    {
        for(int j=0;j<test[i].size();j++)
        {
            cout<<test[i][j];
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}