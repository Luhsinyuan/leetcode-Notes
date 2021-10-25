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
//     vector<vector<int>> result; // ��ŷ�����������ļ���
//     vector<int> path; // ������ŷ����������
//     void backtracking(int n, int k, int startIndex) {
//         if (path.size() == k) {
//             result.push_back(path);
//             return;
//         }
//         for (int i = startIndex; i <= n; i++) {
//             path.push_back(i); // ����ڵ� 
//             backtracking(n, k, i + 1); // �ݹ�
//             path.pop_back(); // ���ݣ���������Ľڵ�
//         }
//     }
// public:
//     vector<vector<int>> combine(int n, int k) {
//         result.clear(); // ���Բ�д
//         path.clear();   // ���Բ�д
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