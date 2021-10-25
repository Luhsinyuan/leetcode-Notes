#include"iostream"
#include"vector"

using namespace std;

class Solution {
public:
    vector<string> result;
    vector<string> letterCombinations(string digits) {
        vector<string> phone;
        phone.push_back("000");
        phone.push_back("000");
        phone.push_back("abc");
        phone.push_back("def");
        phone.push_back("ghi");
        phone.push_back("jkl");
        phone.push_back("mno");
        phone.push_back("pqrs");
        phone.push_back("tuv");
        phone.push_back("wxyz");
        string temp;
        dfs(temp,phone,digits,0);
        return result;
    }
    void dfs(string temp_s,vector<string> phone,string s,int pos)
    {
        if(pos==s.size()&&temp_s!="")
        {
            result.push_back(temp_s);
            return;
        }
        else if(pos==s.size()&&temp_s=="")
        {
            return;
        }
        int position=s[pos]-'0';
        for(int i=0;i<phone[position].size();i++)
        {
            temp_s+=phone[position][i];
            dfs(temp_s,phone,s,pos+1);
            temp_s.pop_back();
        }
        return ;
    }
};
int main()
{
    vector<string> result1;
    Solution s;
    result1=s.letterCombinations("");
    for(auto s1:result1)
    {
        cout<<s1<<endl;
    }
    system("pause");
    return 0;
}