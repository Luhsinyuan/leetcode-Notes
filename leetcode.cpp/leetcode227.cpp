#include"iostream"
#include"vector"
#include"string"
#include"stack"

using namespace std;

class Solution {
public:
    bool high_level(char a,char b)
    {
        if((a=='*'||a=='/')&&(b=='+'||b=='-'))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int calculate(string s) {
        string Postfix;
        stack<char> operators;
        int length=s.size();
        for(int i=0;i<length;i++)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                Postfix+=s[i];
                int isnum=i+1;
                while(s[isnum]>='0'&&s[isnum]<='9')
                {
                    Postfix+=s[isnum];
                    isnum++;
                }
                Postfix += " ";
                i=isnum-1;
            }
            else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
            {
                if(operators.empty())
                {
                    operators.push(s[i]);
                }
                else
                {
                   if(!high_level(s[i],operators.top()))
                   {
                       while(!operators.empty()&&!high_level(s[i],operators.top()))
                       {
                           Postfix+=operators.top();
                           operators.pop();
                       }
                   }
                   operators.push(s[i]);
                }
            }
        }
        while(!operators.empty())
        {
            Postfix+=operators.top();
            operators.pop();
        }
        stack<int> tocalculate;
        for (int i = 0; i < Postfix.size(); i++)
	{
		if (Postfix[i] <= '9' && Postfix[i] >= '0')
		{
			int bitNum = 1;
			for (int j = i + 1; j < Postfix.length(); j++)
			{
				if (Postfix[j] <= '9' && Postfix[j] >= '0')
				{
					bitNum++;
				}
				else
				{
					break;
				}
			}
			int num = atoi(Postfix.substr(i, bitNum).c_str());
			tocalculate.push(num);
			i += bitNum;
		}
		else if (Postfix[i] == '+' || Postfix[i] == '-' || Postfix[i] == '*' || Postfix[i] == '/')
		{
			int tempResult;
			int num2 = tocalculate.top();
			tocalculate.pop();
			int num1 = tocalculate.top();
			tocalculate.pop();
			switch (Postfix[i])
			{
			case '+':tempResult = num1 + num2; break;
			case '-':tempResult = num1 - num2; break;
			case '*':tempResult = num1 * num2; break;
			case '/':tempResult = num1 / num2; break;
			default:
				break;
			}
			tocalculate.push(tempResult);
		}
	}
       return tocalculate.top();
    }
};
int main()
{
    Solution s;
    string s1="42/21+3";
    int answer=s.calculate(s1);
    cout<<answer<<endl;
    system("pause");
    return 0;
}