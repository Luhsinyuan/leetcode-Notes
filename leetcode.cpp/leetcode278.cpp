#include"iostream"
#include"vector"

using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        return binary_search(0,n-1)+1;
    }
    int binary_search(int left,int right)
    {
        while(left<right)
        {
            if(isBadVersion((left+right)/2))
                right=(left+right)/2;
            else
                left=(left+right)/2+1;
        }
        return left;
    }
};