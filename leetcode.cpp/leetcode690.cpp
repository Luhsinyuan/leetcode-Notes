#include"iostream"
#include"vector"

using namespace std;


class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};


class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        return dfs(employees,id);
    }
    int dfs(vector<Employee*> employees,int id)
    {
        Employee* temp;
        for(auto current:employees)
        {
            if(current->id==id)
            {
                temp=current;
                break;
            }
        }
        int result=temp->importance;
        for(int i=0;i<temp->subordinates.size();i++)
        {
            result+=dfs(employees,temp->subordinates[i]);
        }
        return result;
            
    }
};