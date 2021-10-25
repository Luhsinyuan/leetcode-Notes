#include"iostream"
#include"vector"
#include"map"
#include"algorithm"

using namespace std;

// solution 1

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> num_times;
        vector<int> no_repeat;
        sort(nums.begin(),nums.end());
        int last_num=nums[0];
        no_repeat.push_back(last_num);
        num_times[last_num]++;
        for(int i=1;i<nums.size();i++)
        {
            num_times[nums[i]]++;
            if(nums[i]!=last_num)
            {
                no_repeat.push_back(nums[i]);
                last_num=nums[i];
            }
        }
        
        vector<int> max_scores(num_times.size()+1);
        max_scores[0]=0;
        max_scores[1]=no_repeat[0]*num_times[no_repeat[0]];
        int last_deleted=no_repeat[0];
        for(int i=2;i<no_repeat.size()+1;i++)
        {
            int current=no_repeat[i-1];
            if(last_deleted==current+1||last_deleted==current-1)
            {
                int temp=max(max_scores[i-1],max_scores[i-2]+no_repeat[i-1]*num_times[no_repeat[i-1]]);
                max_scores[i]=temp;
                if(max_scores[i]!=max_scores[i-1])
                {
                    last_deleted=no_repeat[i-1];
                }
            }
            else
            {
                int temp=max_scores[i-1]+no_repeat[i-1]*num_times[no_repeat[i-1]];
                max_scores[i]=temp;
                last_deleted=no_repeat[i-1];
            }
        }
        return max_scores[no_repeat.size()];
    }
};

// solution 2

// class Solution {
// public:
//     int deleteAndEarn(vector<int>& nums) {
//        int max_val=0;
//        for(int val:nums)
//        {
//            max_val=max(val,max_val);
//        }
//        vector<int> total_num(max_val+1);
//        for(int val:nums)
//        {
//            total_num[val]+=val;
//        }
//        return rob(total_num);
//     }
//     int rob(vector<int>& nums)
//     {
//         vector<int> max_num(nums.size()+1);
//         max_num[0]=0;
//         max_num[1]=nums[0];
//         for(int i=2;i<=nums.size();i++)
//         {
//             max_num[i]=max(max_num[i-1],max_num[i-2]+nums[i-1]);
//         }
//         return max_num[nums.size()];
//     }
// };
int main()
{
    vector<int> nums={8,10,4,9,1,3,5,9,4,10};
    Solution s;
    int result=s.deleteAndEarn(nums);
    cout<<result<<endl;
    system("pause");
    return 0;
}