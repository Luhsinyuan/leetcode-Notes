#include"iostream"
#include"algorithm"
#include"vector"
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>::iterator it;
        it=nums.begin();
        if(nums.size()>1)
        {
            if(nums.size()-k<0);
            {
                k=k%nums.size();
            }
            it=it+nums.size()-k;
            reverse(nums.begin(),it);

            reverse(it,nums.end());

            reverse(nums.begin(),nums.end());
        }
    }
};
int main()
{
    vector<int> temp={-1,-100,3,99};
    Solution s;
    s.rotate(temp,100);
    for(int i=0;i<temp.size();i++)
    {
        cout<<temp[i]<<endl;
    }
    system("pause");
    return 0;
}