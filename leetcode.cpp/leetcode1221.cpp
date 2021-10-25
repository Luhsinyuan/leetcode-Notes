#include"iostream"
#include"string.h"
using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int length=s.size();
        int result=0;
        int count=0;
        for(int i=0;i<length;i++)
        {
            if(s[i]=='R')
            {
                count++;
            }
            if(s[i]=='L')
            {
                count--;
            }
            if(count==0)
            {
                result++;
            }
        }
        return result;
    }
};
int main()
{
    Solution s;
    string ss="RLLLLRRRLR";
    int result=s.balancedStringSplit(ss);
    cout<<result<<endl;
    system("pause");
    return 0;
}