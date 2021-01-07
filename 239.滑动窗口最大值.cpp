/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
#include"iostream"
#include"vector"
#include"queue"

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> p;
        vector<int> answer;

        for(int i=0;i<k;i++)
        {
            p.emplace(nums[i],i);
        }
        answer.push_back(p.top().first);

        for(int i=k;i<nums.size();i++)
        {
            p.emplace(nums[i],i);
            while(p.top().second<i-k+1)
            {
                p.pop();
            }
            answer.push_back(p.top().first);
        }
        return answer;
    }
};
// @lc code=end

