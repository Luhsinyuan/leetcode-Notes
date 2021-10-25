#include"iostream"
#include"vector"
#include"queue"
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_cost=0;
        int total_gas=0;
        for(int i=0;i<gas.size();i++)
        {
            total_gas+=gas[i];
            total_cost+=cost[i];
        }
        if(total_cost>total_gas)
        {
            return -1;
        }
        vector<int> sub(gas.size());
        for(int i=0;i<gas.size();i++)
        {
            sub[i]=gas[i]-cost[i];
        }
        queue<int> q;
        for(int i=0;i<sub.size();i++)
        {
            q.push(sub[i]);
        }
        int temp=0;
        int place=0;
        int i=0;
        while(!q.empty())
        {
            temp+=q.front();
            q.pop();
            if(temp<0)
            {
                i++;
                place=i;
                temp=0;
            }
            else
            {
                i++;
            }
        }
        return place;

    }
};
int main()
{
    vector<int> gas={1,2,3,4,5};
    vector<int> cost={3,4,5,1,2};

    Solution s;
    int result=s.canCompleteCircuit(gas,cost);
    cout<<result<<endl;
    system("pause");
    return 0;
}