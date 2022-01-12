class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        // [-4,-1,  0,3,10] => [16,1,0,9,100] => [0,1,9,16,100]
        //   ^         ^
        // [1,2,3,4,5,6,7] => [1,4,9,16,25,36,49]
        //  ^
        // [-3,-1,  0] => [0,1,9]
        //        ^ ^

        int s = nums.size();
        int minus = 0;
        while (nums[minus] < 0 && minus < nums.size() - 1)
        {
            minus += 1;
        }
        vector<int> positiveNums;
        for (int i = minus; i < nums.size(); i++)
            positiveNums.push_back(nums[i]);

        nums.erase(nums.begin() + minus, nums.end());
        vector<int> res;

        while (res.size() < s)
        {
            if (positiveNums.size() > 0 && (nums.size() == 0 ||
                                            positiveNums[0] * positiveNums[0] < nums.back() * nums.back()))
            {
                res.push_back(positiveNums[0] * positiveNums[0]);
                positiveNums.erase(positiveNums.begin());
            }
            else
            {
                res.push_back(nums.back() * nums.back());
                nums.erase(nums.end() - 1);
            }
        }

        return res;
    }
};

// 1. push_back太耗效能
// 2. 不需要宣告2個vector
// 3. 以下做法直觀且linear complexity
// class Solution
// {
// public:
//     vector<int> sortedSquares(vector<int> &nums)
//     {
//         int sz = nums.size();
//         vector<int> ans(sz);
//         int l = 0, r = sz - 1;
//         while (sz--)
//         {
//             if (abs(nums[l]) > abs(nums[r]))
//             {
//                 ans[sz] = nums[l] * nums[l];
//                 l++;
//             }
//             else
//             {
//                 ans[sz] = nums[r] * nums[r];
//                 r--;
//             }
//         }
//         return ans;
//     }
// };
