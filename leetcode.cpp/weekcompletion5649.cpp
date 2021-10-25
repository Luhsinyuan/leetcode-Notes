#include"iostream"
#include"vector"
using namespace std;
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> v;
        int temp=first;
        for(int i=0;i<encoded.size();i++)
        {
            v.push_back(temp);
            temp=temp^encoded[i];
        }
        v.push_back(temp);
        return v;
    }
};
int main()
{
    vector<int> v={1,2,3};
    Solution s;
    vector<int> temp=s.decode(v,1);
    for(int i=0;i<temp.size();i++)
    {
        cout<<temp[i]<<endl;
    }
    system("pause");
    return 0;
}