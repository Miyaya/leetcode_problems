class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size() - 1;
        vector<int> coverage(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++)
        {
            coverage[i] = i + nums[i];
        }

        int counter = 0;
        while (n > 0)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (coverage[i] >= n)
                {
                    n = i;
                    counter += 1;
                    break;
                }
            }
        }
        return counter;
    }
};