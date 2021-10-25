#include"iostream"
#include"cstring"

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ps=0;
        int pt=0;
        while(ps<s.size()&&pt<t.size())
        {
            if(s[ps]==t[pt])
        {
            ps++;
        }
        pt++;
        }
        if(ps==s.size())
        {
            return true;
        }
        else
        {
            return false;
        }

    }
};
int main()
{
    string s="gvc";
    string t="ahbgdc";
    Solution c;
    bool p=c.isSubsequence(s,t);
    if(p)
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