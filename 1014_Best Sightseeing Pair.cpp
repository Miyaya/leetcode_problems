class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &values)
    {
        // 4,19,19,18,22
        // 4,20,21,21,26 vi
        // 4,18,17,15,18 vj
        // 4,18,18,18,18 vj_accumulative

        // find max: values[i]+max(vj_accumulative[i+1:end])
        vector<int> vj_accumu(values.size(), values.back() - values.size() + 1);
        for (int i = values.size() - 2; i >= 0; i--)
        {
            vj_accumu[i] = max(values[i] - i, vj_accumu[i + 1]);
        }

        int res = INT_MIN;
        for (int i = 0; i < values.size() - 1; i++)
        {
            res = max(res, values[i] + i + vj_accumu[i + 1]);
        }
        return res;
    }
};