#include"iostream"
#include"vector"
#include"string"

using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())
        {
            return false;
        }
        int length1=s1.size();
        int left=0;
        int right=length1+left-1;
        vector<int> windows1(26);
        vector<int> windows2(26);
        for(int i=0;i<s1.size();i++)
        {
            windows1[s1[i]-'a']++;
            windows2[s2[i]-'a']++;
        }
        while(right<s2.size()-1)
        {
            if(windows1==windows2)
            {
                return true;
            }
            else
            {
                windows2[s2[left++]-'a']--;
                windows2[s2[++right]-'a']++;
            }
        }
        return windows1==windows2;
    }
};
int main()
{
    string s1("ab");
    string s2("cbac");
    Solution s;
    bool b=s.checkInclusion(s1,s2);
    if(b)
    {
        cout<<"yes"<<endl;
    }
    else
    {
        cout<<"no"<<endl;
    }
    system("pause");
    return 0;
}