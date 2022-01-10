// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        //[1,2,3,4*,5*]
        //[1,2,3*]
        //[1,2*]
        //[1*,2*]

        int first = 1;
        int last = n;
        int mid = (last - first) / 2 + first;
        // better than (first+last)/2 <- might overflow

        while (isBadVersion(mid) == isBadVersion(mid - 1))
        {
            if (!isBadVersion(mid))
            {
                first = mid + 1;
            }
            else if (isBadVersion(mid))
            {
                last = mid - 1;
            }
            mid = (last - first) / 2 + first;
        }
        return mid;
    }
};