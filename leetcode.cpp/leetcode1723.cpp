#include"iostream"
#include"vector"

using namespace std;

class Solution {
public:
    vector<int>* seprate_work;
    int minimumTimeRequired(vector<int>& jobs, int k) {
        vector<int>* temp=new vector<int>(jobs.size());
        seprate_work=temp;
    }
    void dfs(vector<int> jobs,int worker_num,int total_num)
    {
        if(worker_num>total_num)
        {
            return;
        }
        for(int i=0;i<jobs.size();i++)
        {
            
        }
    }
};