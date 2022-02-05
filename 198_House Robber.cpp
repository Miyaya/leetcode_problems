class Solution
{
public:
    int rob(vector<int> &nums)
    {

        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return nums[0] > nums[1] ? nums[0] : nums[1];
        vector<int> maxRob(nums.size(), 0);
        maxRob[0] = nums[0];
        maxRob[1] = nums[0] > nums[1] ? nums[0] : nums[1];

        for (int i = 2; i < nums.size(); i++)
        {
            int n1 = nums[i] + maxRob[i - 2];
            int n2 = maxRob[i - 1];
            maxRob[i] = n1 > n2 ? n1 : n2;
        }
        return maxRob.back();
    }
};