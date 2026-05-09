#include <vector>
using namespace std;
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int res = 0;
        int l = 0;//双指针
        int r = height.size() - 1;
        while (l < r)
        {
            int area = (r - l) * min(height[l], height[r]);
            res = max(res, area);
            if (height[l] < height[r])//短板限制面积 移动长板面积一定变小
            {                         //
                ++l;
            }
            else
            {
                --r;
            }
        }
        return res;
    }
};