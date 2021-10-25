#include"iostream"
#include"vector"
#include"algorithm"
#include"string.h"

using namespace std;

class Solution {
public:
    int reverse(int x) {
       long long temp=0;
       while(x!=0)
       {
           int last_bit=x%10;
           temp=temp*10+last_bit;
           x/=10;
       }
       return (int)temp==temp?(int)temp:0;
    }
};
int main()
{
    Solution s;
    int x=-123;
    int result=s.reverse(x);
    cout<<result<<endl;
    system("pause");
    return 0;
}