#include"iostream"
#include"vector"
#include"algorithm"

using namespace std;
bool cmp(vector<int> a, vector<int> b)  //自我实现的排序函数
{
	if (a[1] < b[1])
	{
		return true;
	}
	else
	{
		return false;
	}

}
class Solution {
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {

		sort(intervals.begin(), intervals.end(), cmp);   //对所有的区间按照右端排序。
		int count = 1;            //计数，记录剩下的区间有几个
		int end = intervals[0][1];//将第一个的右端点作为标志
		for (int i = 1; i < intervals.size(); i++)
		{
			if (intervals[i][0] >= end)
			{
				end = intervals[i][1];
				count++;
			}
		}
		return intervals.size() - count;
	}
};
int main()
{
	vector<vector<int>> v(4);
	v[0].push_back(1);
	v[0].push_back(2);
	v[1].push_back(2);
	v[1].push_back(3);
	v[2].push_back(3);
	v[2].push_back(4);
	v[3].push_back(1);
	v[3].push_back(4);
	Solution s;
	cout << s.eraseOverlapIntervals(v) << endl;
    system("pause");
    return 0;
}