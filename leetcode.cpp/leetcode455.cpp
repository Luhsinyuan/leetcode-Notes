#include"iostream"
#include"vector"
#include"algorithm"
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int g_begin=0;
        int s_begin=0;
        int total=0;
        while(s_begin<s.size()&&g_begin<g.size())
        {
            if(g[g_begin]>s[s_begin])
            {
                s_begin++;
            }
            else
            {
                total++;
                g_begin++;
                s_begin++;
            }
        }
        return total;
    }
};
int main()
{
    vector<int> g={5,4,3,1,1};
    vector<int> s={1,1};
    Solution v;
    int result=v.findContentChildren(g,s);
    cout<<result<<endl;
    system("pause");
    return 0;
}