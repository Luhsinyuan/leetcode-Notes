#include"iostream"
#include"vector"
#include"queue"

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        queue<int> sub;
        for(int i=0;i<bills.size();i++)
        {
            sub.push(bills[i]-5);
        }
        int last[3]={0,0,0};
        while(!sub.empty())
        {
            if(sub.front()==0)
            {
                last[1]++;
                sub.pop();
            }
            else if(sub.front()==5)
            {
                last[2]++;
                last[1]--;
                sub.pop();
            }
            else if(sub.front()==15)
            {
                sub.pop();
                last[3]++;
                if(last[2]!=0)
                {
                    last[2]--;
                    last[1]--;
                }
                else
                {
                    last[1]=last[1]-3;
                }
            }
            if(last[0]<0||last[1]<0||last[2]<0)
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    vector<int> v{5,5,10};
    Solution s;
    bool b=s.lemonadeChange(v);
    if(b)
    {
        cout<<"t"<<endl;
    }
    else
    {
        cout<<"f"<<endl;
    }
    system("pause");
    return 0;
}