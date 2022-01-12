class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        unordered_map<int, int> dict;
        vector<int> res(2);

        for (int i = 0; i < numbers.size(); i++)
        {
            auto it = dict.find(target - numbers[i]);
            if (it != dict.end())
            {
                res[0] = it->second + 1;
                res[1] = i + 1;
                return res;
            }
            dict.insert(make_pair(numbers[i], i)); // 0-index
        }
        return res;
    }
};