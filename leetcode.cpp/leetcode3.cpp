#include"iostream"
#include"vector"
#include"unordered_set"

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> uno;
        int length=s.size();
        int right=0;
        int result=0;
        for(int i=0;i<length;i++)
        {
            if(i!=0)
            {
                uno.erase(s[i-1]);
            }
            while(right<length&&!uno.count(s[right]))
            {
                uno.insert(s[right]);
                right++;
            }
            result=max(result,right-i+1);
        }
        return result;
    }
};