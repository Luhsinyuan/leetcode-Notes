#include"iostream"
#include"vector"
#include"stack"
#include"algorithm"

using namespace std;

class Solution {
public:
    string decodeString(string s) {
       stack<string> result;
       stack<int> argument;
       string temp;
       for(int i=0;i<s.size();i++)
       {
           if(s[i]>='a'&&s[i]<='z')
           {
               temp+=s[i];
           }
           else if(s[i]==']')
           {
               result.push(temp);
           }
           else if(s[i]>='0'&&s[i]<='9')
           {
               int bit_num=1;
               i++;
               while(s[i]>='0'&&s[i]<='9')
               {
                   bit_num++;
               }
               argument.push(atoi(s.substr(i,bit_num).c_str()));
               i+=bit_num;
           }
           else if()
           {
               while(result.top()!='[')
               {
                   temp.push_back(result.top());
                   result.pop();
               }
                reverse(temp.begin(),temp.end());
               result.pop();
               int repeat_time=result.top();
               while(repeat_time>0)
               {
                   
               }
           }
       } 
    }
};