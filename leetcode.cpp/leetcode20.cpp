#include"iostream"
#include"vector"
#include"string"

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        char exp[10000];
        int top=-1;
        int i=0;
        while(i<s.size())
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{')
            {
                exp[++top]=s[i];
                i++;
            }
            else if(s[i]==')')
            {
                if(top!=-1&&exp[top]=='(')
                {
                    top--;
                    i++;
                }
                else
                {
                    return false;
                }
            }
            else if(s[i]==']')
            {
                if(top!=-1&&exp[top]=='[')
                {
                    top--;
                    i++;
                }
                else
                {
                    return false;
                }
            }
            else if(s[i]=='}')
            {
                if(top!=-1&&exp[top]=='{')
                {
                    top--;
                    i++;
                }
                else
                {
                    return false;
                }
            }
        }
        if(top==-1)
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
    string s("[[[[[[[[[[[[[[[[[[[");
    Solution s1;
    bool b=s1.isValid(s);
    return 0;
}