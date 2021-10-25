#include"iostream"
#include"vector"

using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int sum=0;
        for(int i=0;i<chalk.size();i++)
        {
            sum+=chalk[i];
        }
        while(k>sum)
        {
            k-=sum;
        }
        for(int i=0;i<chalk.size();i++)
        {
            if(k-chalk[i]<0)
                return i;
            else
                k-=chalk[i];
        }
        return 0;
    }
};
int main()
{
    vector<int> chalk={3,4,1,2};
    Solution s;
    int result=s.chalkReplacer(chalk,25);
    cout<<result<<endl;
    system("pause");
    return 0;
}