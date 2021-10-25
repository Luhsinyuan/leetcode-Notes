#include"iostream"
#include"vector"
#include"string"

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int pro_zero_num=0;
        for(;pro_zero_num<s.size();pro_zero_num++)
        {
            if(s[pro_zero_num]!='0')
            {
                break;
            }
        }
        if(pro_zero_num!=0)
        {
            return 0;
        }
        int size=s.size();
        int result[size+1];
        result[0]=1;
        result[1]=1;
        for(int i=2;i<=size;i++)
        {
            int temp=atoi(s.substr(i-2,2).c_str());
            if(temp==0||(temp>26&&s[i-1]=='0'))
            { 
                return 0;
            }
            else if(temp<=26&&temp>=1&&s[i-1]=='0')
            {
                result[i]=result[i-2];
            }
            else if(s[i-2]=='0'||temp>26)
            {
                result[i]=result[i-1];
            }
            else if(temp<=26&&temp>=1)
            {
                result[i]=result[i-1]+result[i-2];
            }
        }
        return result[size];
    }
};
int main()
{
    string s="1026";
    Solution s1;
    int result=s1.numDecodings(s);
    cout<<result<<endl;
    system("pause");
    return 0;
}