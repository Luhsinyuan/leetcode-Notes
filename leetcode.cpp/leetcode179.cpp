#include"iostream"
#include"vector"
#include"algorithm"


using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
       vector<string> num2str;
       for(int num:nums)
       {
           num2str.push_back(to_string(num));
       }
       sort(num2str.begin(),num2str.end(),[](string x))
    }
};