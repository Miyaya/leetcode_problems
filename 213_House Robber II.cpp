class Solution
{
public:
    int rob(vector<int> &nums)
    {

        int size = nums.size();
        if (size == 1)
            return nums[0];
        if (size == 2)
            return nums[0] > nums[1] ? nums[0] : nums[1];

        int r1 = robHouses(nums, 0, size - 2);
        int r2 = robHouses(nums, 1, size - 1);

        return r1 > r2 ? r1 : r2;
    }

    int robHouses(vector<int> &nums, int start, int end)
    {
        int pre = nums[start];
        int curr = nums[start + 1] > nums[start] ? nums[start + 1] : nums[start];
        for (int i = start + 2; i <= end; i++)
        {
            int robThis = nums[i] + pre;
            int dontRobThis = curr;

            pre = curr;
            curr = robThis > dontRobThis ? robThis : dontRobThis;
        }
        return curr;
    }
};