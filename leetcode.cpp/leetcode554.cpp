#include"iostream"
#include"vector"
#include"unordered_map"

using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> mp;
        int height=wall.size();
        for(auto width:wall)
        {
            int pre=0;
            int block_num=width.size();
            for(int i=0;i<block_num-1;i++)
            {
                pre+=width[i];
                mp[pre]++;
            }
        }
        int max_num=0;
        for(auto temp_pair:mp)
        {
            if(temp_pair.second>max_num)
            max_num=temp_pair.second;
        }
        return height-max_num;
    }
};