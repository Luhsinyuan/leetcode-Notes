#include"iostream"
#include"vector"
#include"algorithm"

using namespace std;
bool cmp(vector<int> a, vector<int> b)  //����ʵ�ֵ�������
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

		sort(intervals.begin(), intervals.end(), cmp);   //�����е����䰴���Ҷ�����
		int count = 1;            //��������¼ʣ�µ������м���
		int end = intervals[0][1];//����һ�����Ҷ˵���Ϊ��־
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