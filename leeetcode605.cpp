#include"iostream"
#include"vector"

using namespace std;


class Solution {
public:
	bool canPlace(vector<int> temp, int k)
	{
		if (temp[k] == 1)
		{
			return false;
		}
		else
		{
			if(k==0)
			{
				;
			}
			if (k == 0)
			{
				if (k+1<temp.size()&&temp[k + 1] == 1)
				{
					return false;
				}
			}
			else if (k == temp.size() - 1)
			{
				if (k-1>=0&&temp[k - 1] == 1)
				{
					return false;
				}
			}
			else
			{
				if (temp[k - 1] == 1 || temp[k + 1] == 1)
					return false;
			}
			return true;

		}
	}

	bool canPlaceFlowers(vector<int>& flowerbed, int n)
	{
		if (n == 0)
		{
			return true;
		}
		for (int i = 0; i < flowerbed.size(); i++)
		{
			if (canPlace(flowerbed,i))
			{
				n--;
				if (n <= 0)
				{
					return true;
				}
				flowerbed[i] = 1;
			}
		}
		return false;

	}
};
int main()
{
	vector<int> temp;
	temp.push_back(0);

	Solution s;
	if (s.canPlaceFlowers(temp, 1))
	{
		cout << "yes" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	system("pause");
	return 0;
}