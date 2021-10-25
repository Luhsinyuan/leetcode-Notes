#include"iostream"
#include"vector"

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int iterator_1=0;
        int iterator_2=0;
        if(haystack.size()<needle.size())
        {
            return -1;
        }
        else if(needle.size()==0)
        {
            return 0;
        }
        else
        {
            while(iterator_1<haystack.size())
            {
                if(haystack[iterator_1]!=needle[iterator_2])
                {
                    iterator_1-=iterator_2;
                    iterator_2=0;
                }
                else
                {
                    iterator_2++;
                    if(iterator_2==needle.size())
                    {
                        return iterator_1-iterator_2+1;
                    }
                }
                iterator_1++;
            }
        }
        return -1;
    }
};
int main()
{
    string s1="";
    string s2="";
    Solution s;
    int result=s.strStr(s1,s2);
    cout<<result<<endl;
    system("pause");
    return 0;
}