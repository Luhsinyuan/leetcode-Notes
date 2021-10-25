#include"iostream"
#include"vector"
#include"map"

using namespace std;

class Solution {
public:
    map<pair<int,int>,int> dic;
    int minCost(vector<vector<int>>& costs) {
        /*int temp=min(memo_dfs(costs,costs.size(),0,0),memo_dfs(costs,costs.size(),0,1));
        return min(temp,memo_dfs(costs,costs.size(),0,2));*/
        return dyna_plan(costs);
    }
    
    //troditional recursion
    /*int dfs(vector<vector<int>> costs,int total_house,int house_num,int color)
    {
        if(total_house==house_num)
        {
            return 0;
        }
        int total_cost=costs[house_num][color];
        if(color==0)
        {
            total_cost+=min(dfs(costs,total_house,house_num+1,1),dfs(costs,total_house,house_num+1,2));
        }
        if(color==1)
        {
            total_cost+=min(dfs(costs,total_house,house_num+1,0),dfs(costs,total_house,house_num+1,2));
        }
        if(color==2)
        {
            total_cost+=min(dfs(costs,total_house,house_num+1,0),dfs(costs,total_house,house_num+1,1));
        }
        return total_cost;
    }*/
    // memorial recursion
    int memo_dfs(vector<vector<int>> costs,int total_house,int house_num,int color)
    {
        if(total_house==house_num)
        {
            return 0;
        }
        if(dic.find(make_pair(house_num,color))!=dic.end())
        {
            return dic[make_pair(house_num,color)];
        }
        
            int total_cost=costs[house_num][color];
            if(color==0)
            {
                total_cost+=min(memo_dfs(costs,total_house,house_num+1,1),memo_dfs(costs,total_house,house_num+1,2));
            }
            if(color==1)
            {
                total_cost+=min(memo_dfs(costs,total_house,house_num+1,0),memo_dfs(costs,total_house,house_num+1,2));
            }
            if(color==2)
            {
                total_cost+=min(memo_dfs(costs,total_house,house_num+1,0),memo_dfs(costs,total_house,house_num+1,1));
            }
            dic[make_pair(house_num,color)]=total_cost;
        return total_cost;
    }
    // dynamic planning
    int dyna_plan(vector<vector<int>> costs)
    {
       vector<vector<int>> min_cost(costs);
        for(int i=1;i<costs.size();i++)
        {
            for(int j=0;j<costs[0].size();j++)
            {
                if(j==0)
                {
                    min_cost[i][j]=min(min_cost[i-1][1],min_cost[i-1][2])+costs[i][j];
                }
                if(j==1)
                {
                    min_cost[i][j]=min(min_cost[i-1][0],min_cost[i-1][2])+costs[i][j];
                }
                if(j==2)
                {
                    min_cost[i][j]=min(min_cost[i-1][1],min_cost[i-1][0])+costs[i][j];
                }
            }
        }
        int min_num=INT32_MAX;
        for(int i=0;i<costs[0].size();i++)
        {
            if(min_cost[costs.size()-1][i]<min_num)
            {
                min_num=min_cost[costs.size()-1][i];
            }
        }
        return min_num;
};


int main()
{
    vector<vector<int>> costs={{17,2,17},{8,4,10},{6,3,19},{4,8,12}};
    Solution s;
    int result=s.minCost(costs);
    cout<<result<<endl;
    system("pause");
    return 0;
}