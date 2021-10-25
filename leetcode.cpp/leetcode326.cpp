#include"iostream"
#include"vector"
#include"algorithm"
#include"math.h"


using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        int i=0;
        while(>3)
        {
            i++;
        }
        if(n-pow(3,i)==0)
            return true;
        return false;
    }
};
int main()
{
    Solution s;
    bool result=s.isPowerOfThree(27);
    return 0;
}