class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // 1,2,5,3,6,7,8
        // b   s b     s

        // 7,1,5,3,6,4
        //   b s b s

        if (prices.size() == 1)
            return 0;
        int b;
        int start = prices[1] > prices[0] ? 0 : 1;

        b = prices[start];
        int res = 0;
        for (int i = start + 1; i < prices.size(); i++)
        {
            if (prices[i] < prices[i - 1])
            {
                res += (prices[i - 1] - b); // sell
                b = prices[i];
            }
        }

        res += prices.back() - b;
        return res;
    }
};