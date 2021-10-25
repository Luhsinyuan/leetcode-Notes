#include"iostream"
#include"vector"
#include"math.h"

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int num=0;
        for(int i=0;i<32;i++)
        {
            if(n&(1<<i))
            {
                num++;
            }
        }
        return num;
    }
};
int main()
{
    Solution s;
    unsigned int a=142315;
    int answer=s.hammingWeight(a);
    cout<<answer<<endl;
    system("pause");
    return 0;
}