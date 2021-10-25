#include"iostream"
#include"vector"
#include"algorithm"
#include"string.h"

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int left=0;
        int right=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' '||i==s.size()-1)
            {
                right=i;
                if(i==s.size()-1)
                    right++;
                vector<char> temp(s.begin()+left,s.begin()+right);
                vector<char> result=reverse(temp);
                for(int j=0;left<right;left++,j++)
                {
                    s[left]=result[j];
                }
                
                left=i+1;
            }
        }
        return s;
    }
    vector<char> reverse(vector<char>& s)
    {
        int left=0;
        int right=s.size()-1;
        while(left<=right)
        {
            swap(s[left],s[right]);
            left++;
            right--;
        }
        return s;
    }
};
int main()
{
    Solution s;
    string s1="Let's take LeetCode contest";
    string result=s.reverseWords(s1);
    cout<<result<<endl;
    system("pause");
    return 0;
}