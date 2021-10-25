#include"iostream"
#include"vector"
#include"map"

using namespace std;


class Solution {
public:
    bool result=false;
    map<int,bool> temp;
    map<int,int> temp1;
    bool canCross(vector<int>& stones) {
        int i=0;
        for(int stone:stones)
        {
            temp.emplace(stone,true);
            temp1.emplace(stone,i);
            i++;
        }
        dfs(0,1,stones.size(),stones);
        return result;
    }
    void dfs(int st_place,int tar_place,int end_place,vector<int> stones)
    {
        if(tar_place=end_place)
        {
            result=true;
            return ;
        }
        else if(tar_place>end_place)
        {
            return;
        }
        int gap=stones[tar_place]-stones[st_place];
        if(temp[stones[tar_place]+gap-1]==true&&gap-1>0)
        {
            dfs(tar_place,temp1[tar_place+gap-1],end_place,stones);
        }
        if(temp[tar_place+gap]==true&&gap>0)
        {
            dfs(tar_place,temp1[tar_place+gap],end_place,stones);
        }
        if(temp[tar_place+gap+1]==true&&gap+1>0)
        {
            dfs(tar_place,temp1[tar_place+gap+1],end_place,stones);
        }
    }
};
int main()
{
    Solution s;
    vector<int> stones={0,1,3,5,6,8,12,17};
    bool result=s.canCross(stones);
    if(result)
    {
        cout<<"yes"<<endl;
    }
    else
    {
        cout<<"no"<<endl;
    }
    system("pause");
    return 0;
}