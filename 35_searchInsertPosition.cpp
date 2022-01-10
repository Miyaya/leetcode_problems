class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        // [1,3,5,6]
        //    ^   ^

        int first = 0;
        int last = nums.size() - 1;
        int mid = 0;
        while (last - first >= 0)
        {
            mid = first + (last - first) / 2;
            if (nums[mid] < target)
            {
                first = mid + 1;
            }
            else if (nums[mid] > target)
            {
                last = mid - 1;
            }
            else
                return mid;
        }
        return last + 1;
    }
};