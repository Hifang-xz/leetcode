// 暴力循环
#include <vector>    //强迫症
using namespace std; // 强迫症
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<int> a;
        vector<vector<int>> b;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue; // 去重
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue; // 去重
                for (int k = j + 1; k < nums.size(); ++k)
                {
                    if (k > j + 1 && nums[k] == nums[k - 1])
                        continue; // 去重
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        b.push_back(temp);
                    }
                }
            }
        }
        return b;
    }
};
// 排序 + 双指针
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> v;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;  // 去重
            int l = i + 1; // 双指针
            int r = nums.size() - 1;
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0)
                {
                    v.push_back({nums[i], nums[l], nums[r]});
                    ++l;
                    --r;
                    while (l < r && nums[l] == nums[l - 1])
                        l++; // 去重
                    while (l < r && nums[r] == nums[r + 1])
                        r--; // 去重
                }
                else if (sum < 0)
                {
                    ++l;
                } // 小于0 左侧指针右移
                else
                {
                    --r;
                } // 大于0 右侧指针左移
            }
        }
        return v;
    }
};
