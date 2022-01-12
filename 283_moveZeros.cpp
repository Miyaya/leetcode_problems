class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        // [0,1,0,3,12]
        //  - 1 - 2  2
        // 1,-,0,3,12
        // 1,3,-,-,12
        // 1,3,12,-,-
        int counter = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                nums[i - counter] = nums[i];
            }
            else
            {
                counter += 1;
            }
        }
        for (int i = 0; i < counter; i++)
        {
            nums[nums.size() - 1 - i] = 0;
        }
    }
};