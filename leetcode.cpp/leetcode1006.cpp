#include"iostream"
#include"vector"
#include"stack"

using namespace std;

class Solution {
public:
    int clumsy(int N) {
        int opera_num=0;
        stack<int> result;
        result.push(N);
        N--;
        while(N>0)
        {
            switch(opera_num%4)
            {
                case 0:result.top()*=N;break;
                case 1:result.top()/=N;break;
                case 2:result.push(N);break;
                case 3:result.push(-N);break;
            }
            N--;
            opera_num++;
        }
        int result_num=0;
        while(!result.empty())
        {
            result_num+=result.top();
            result.pop();
        }
        return result_num;
    }
};
int main()
{
    Solution s;
    int result=s.clumsy(10);
    cout<<result<<endl;
    system("pause");
    return 0;
}