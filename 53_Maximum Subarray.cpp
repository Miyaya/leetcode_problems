class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int curr = 0;
        int pre = curr;
        int max_num = INT_MIN;

        // sum>=0
        for (int i = 0; i < nums.size(); i++)
        {
            pre = max(pre + nums[i], 0);
            curr = max(pre, curr);
            if (nums[i] > max_num)
                max_num = nums[i];
        }

        // sum<0
        if (max_num < 0)
            curr = max_num;
        return curr;
    }

    // Kadane's algorithm
    // int maxSubArray(vector<int>& nums) {
    //     int curMax = 0, maxTillNow = INT_MIN;
    //     for(auto c : nums)
    //         curMax = max(c, curMax + c),
    //         maxTillNow = max(maxTillNow, curMax);
    //     return maxTillNow;
    // }
};