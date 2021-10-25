#include"iostream"
#include"vector"
#include"stack"


using namespace std;

class Solution {
public:
    bool result=true;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> state(numCourses,0);
        for(int i=0;i<numCourses&&result;i++)
        {
            if(state[i]==0)
            {
                dfs(i,prerequisites,state);
            }
        }
        return result;
    }
    void dfs(int course_num,vector<vector<int>>& pre,vector<int>& state)
    {
        if(!result)
        {
            return;
        }
        state[course_num]=1;
        for(int i=0;i<pre.size();i++)
        {
            if(pre[i][1]==course_num)
            {
                if(state[pre[i][0]]==1)
                {
                    result=false;
                    return;
                }
                else
                {
                    dfs(pre[i][0],pre,state);
                }
            }
        }
        state[course_num]=2;
    }
};
int main()
{
    vector<vector<int>> pre{{0,1}};
    Solution s;
    if(s.canFinish(2,pre))
    {
        cout<<"yes"<<endl;
    }
    system("pause");
    return 0;
}