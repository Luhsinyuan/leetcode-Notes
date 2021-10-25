#include"iostream"
#include"vector"
#include"math.h"

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c<3)
        return true;
        int temp=sqrt(c);
        int left=0;
        int right=temp;
        while(left<=right)
        {
            if(left*left+right*right==c)
            {
                return true;
            }
            else if(left*left+right*right<c)
            {
                left++;
            }
            else if(left*left+right*right>c)
            {
                right--;
            }
        }
        return false;
    }
};