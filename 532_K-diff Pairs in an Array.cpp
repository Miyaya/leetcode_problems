class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        map<int, bool> m;
        set<pair<int, int>> s;
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (m.find(nums[i]) == m.end())
            {
                m[nums[i]] = 1;
            }
            else
            {
                m[nums[i]] += 1;
            }
        }

        for (int i = 0; i < nums.size(); i++)
        {
            int target = nums[i] + k;
            if (k == 0)
                m[target] -= 1;
            if (m.find(target) != m.end() && m[target] > 0)
            {
                m[target] -= 1;
                s.insert(make_pair(nums[i], target));
            }
        }
        res = s.size();
        return res;
    }
};