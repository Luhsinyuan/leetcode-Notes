#include"iostream"
#include"vector"
#include"algorithm"

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> concalute;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]!="+"&&tokens[i]!="-"&&tokens[i]!="*"&&tokens[i]!="/")
            {
                concalute.push_back(stoi(tokens[i]));
            }
            else
            {
                int current=0;
                int num1=concalute.back();
                concalute.pop_back();
                int num2=concalute.back();
                concalute.pop_back();
                if(tokens[i]=="+")
                {
                    current=num2+num1;
                }
                else if(tokens[i]=="-")
                {
                    current=num2-num1;
                }
                else if(tokens[i]=="*")
                {
                    current=num2*num1;
                }
                else if(tokens[i]=="/")
                {
                    current=num2/num1;
                }
                concalute.push_back(current);
            }
        }
        return concalute.back();

    }
};
int main()
{
    Solution s;
    vector<string> v;
    v.push_back("4");
    v.push_back("13");
    v.push_back("5");
    v.push_back("/");
    v.push_back("+");
    int answer=s.evalRPN(v);
    cout<<answer<<endl;
    system("pause");
    return 0;
}
