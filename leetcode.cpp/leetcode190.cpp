#include"iostream"
#include"vector"
#include"math.h"

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string num;
        for(int i=0;i<32;i++)
        {
            if(n&(1<<i))
            {
                num.push_back(1);
                cout<<1<<endl;
            }
            else
            {
                num.push_back(0);
                cout<<0<<endl;
            }
        }
        unsigned int result=0;
        for(int i=31;i>=0;i--)
        {
            if(num[31-i]!=0)
            {
                result+=pow(2,i);
            }
        }
        return result;
    }
};
int main()
{
    unsigned int a=3221225471;
    Solution s;
    unsigned int result=s.reverseBits(a);
    cout<<result<<endl;
    system("pause");
    return 0;
}