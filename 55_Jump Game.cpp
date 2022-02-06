class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int reachable = 0;
        nums[nums.size() - 1] = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > reachable)
                return false;
            int farestCurr = nums[i] + i;
            reachable = reachable > farestCurr ? reachable : farestCurr;
        }
        return true;
    }
};