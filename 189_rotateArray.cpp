class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        // [0,1,2,3,4,5,6], 3 => [4,5,6,0,1,2,3] //前4個+3, 後3個-4
        //                        0 1 2 3 4 5 6  //前(n-k)個+k, 後k個-(n-k)
        k = k % nums.size();
        vector<int> tmp = nums;
        for (int i = 0; i < nums.size() - k; i++)
        {
            nums[i + k] = tmp[i];
        }
        for (int i = 0; i < k; i++)
        {
            nums[i] = tmp[nums.size() - k + i];
        }
    }
};