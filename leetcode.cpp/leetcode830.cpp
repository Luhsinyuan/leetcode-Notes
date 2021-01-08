/*
 * @lc app=leetcode.cn id=830 lang=cpp
 *
 * [830] 较大分组的位置
 */

// @lc code=start
#include"iostream"
#include"vector"
#include"queue"
using namespace std;

class Solution {
    bool isEqual(string s,int k)
    {
        return s[k]==s[k+1]&&s[k+1]==s[k+2];
    }
public:
    vector<vector<int>> largeGroupPositions(string s) {
        
        vector<vector<int>> v;
        for(int i=0;i<s.size();)
        {
            int count=0;
            if(isEqual(s,i))
            {
                for(int j=i+3;j<s.size();j++)
                {
                    if(s[j]==s[j-1])
                    {
                        count++;
                    }
                    else
                    {
                        break;
                    }
                    
                }
                v.push_back({i,i+count+2});
                i=i+count+2;
            }
            else
            {
                i=i+1;
            }
            
        }

        return v;

    }
};
int main()
{
    string s="abcdddeeeeaabbbcd";
    Solution so;
    vector<vector<int>>a=so.largeGroupPositions(s);
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i][0]<<" "<<a[i][1]<<endl;
    }
    system("pause");
    return 0;
}
// @lc code=end

