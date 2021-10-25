#include"iostream"
#include"vector"


using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;
    vector<vector<int>> combine(int n, int k) {
        dfs(n,1,k);
        return result;
    }
    void dfs(int n,int index,int k)
    {
        if(temp.size()==k)
        {
            result.push_back(temp);
            return;
    
        }
        for(int i=index;i<=n;i++)
        {
            temp.push_back(i);
            dfs(n,i+1,k);
            temp.pop_back();
        }

    }
};

// class Solution {
// private:
//     vector<vector<int>> result; // 存放符合条件结果的集合
//     vector<int> path; // 用来存放符合条件结果
//     void backtracking(int n, int k, int startIndex) {
//         if (path.size() == k) {
//             result.push_back(path);
//             return;
//         }
//         for (int i = startIndex; i <= n; i++) {
//             path.push_back(i); // 处理节点 
//             backtracking(n, k, i + 1); // 递归
//             path.pop_back(); // 回溯，撤销处理的节点
//         }
//     }
// public:
//     vector<vector<int>> combine(int n, int k) {
//         result.clear(); // 可以不写
//         path.clear();   // 可以不写
//         backtracking(n, k, 1);
//         return result;
//     }
// };

int main()
{
    Solution s;
    vector<vector<int>> result=s.combine(4,2);
    return 0;
}