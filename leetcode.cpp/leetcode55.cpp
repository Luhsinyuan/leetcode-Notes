#include"iostream"
#include"vector"

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int longest=0;
        for(int i=0;i<=longest;i++)
        {
            longest=max(i+nums[i],longest);
            if(longest>=nums.size()-1)
            {
                return true;
            }
        }
        return false;
    }
};
int main()
{
    vector<int> v{2,3,1,1,4};
    Solution s;
    bool b=s.canJump(v);
    if(b)
    {
        cout<<"t"<<endl;
    }
    else
    {
        cout<<"f"<<endl;
    }
    system("pause");
    return 0;
}