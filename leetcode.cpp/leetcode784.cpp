#include"iostream"
#include"vector"
using namespace std;

class Solution {
public:
    string temp;
    vector<string> result;
    vector<string> letterCasePermutation(string s) {
        dfs(0,s.size(),s);
        return result;
    }
    void dfs(int index,int total_length,string s)
    {
        if(index>=total_length)
        {
            result.push_back(temp);
            return;
        }
        if((s[index]>='a'&&s[index]<='z')||(s[index]>='A'&&s[index]<='Z'))
        {
            temp.push_back(s[index]);
            dfs(index+1,total_length,s);
            temp.pop_back();
            if(s[index]>='a'&&s[index]<='z')
                temp.push_back(s[index]-32);
            else 
                temp.push_back(s[index]+32);
            dfs(index+1,total_length,s);
            temp.pop_back();
        }
        else
        {
            temp.push_back(s[index]);
            dfs(index+1,total_length,s);
            temp.pop_back();
        }
    }
};
int main()
{
    string s="3z4";
    Solution s1;
    vector<string> res=s1.letterCasePermutation(s);
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<endl;
    }
    system("pause");
    return 0;
}