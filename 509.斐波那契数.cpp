/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        int list[31]={0};
        list[0]=0;
        list[1]=1;
        if(list[n]==0)
        {
            for(int i=2;i<=n;i++)
        {
            list[i]=list[i-1]+list[i-2];
        }
        }
        
        return list[n];
    }
};
// @lc code=end

