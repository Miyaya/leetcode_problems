class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        // [-1,0,3,5,9,12], 9 => 4
        // [1,4,5,5,6], 3 => does not exist (strict ascending)
        // [5], 5 => 0

        int beginning = 0;
        int endding = nums.size() - 1;

        while (beginning <= endding)
        {
            int mid = (beginning + endding) / 2;

            //提升2.6倍runtime效率，看來很多邊界測資
            //if(nums[beginning]==target) return beginning;
            //if(nums[endding]==target) return endding;

            if (nums[mid] < target)
                beginning = mid + 1;
            else if (nums[mid] > target)
                endding = mid - 1;
            else
                return mid;
        }
        return -1;
    }
};