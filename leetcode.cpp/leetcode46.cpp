#include"iostream"
#include"vector"
#include"algorithm"


using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums,0,nums.size());
        return result;
    }
    void backtrack(vector<int>& temp,int index,int total_length)
    {
        if(index==total_length)
        {
            result.push_back(temp);
            return;
        }
        for(int i=index;i<total_length;i++)
        {
            swap(temp[i],temp[index]);
            backtrack(temp,index+1,total_length);
            swap(temp[i],temp[index]);
        }
    }
};