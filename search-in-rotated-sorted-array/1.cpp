class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int n = nums.size();
        if (n == 0) return -1;
        // [begin, end]
        int begin = 0, end = n - 1;
        while (begin < end) {
            const int mid = (begin + end)/2;
            if (nums[mid] > nums[end])
                begin = mid + 1;
            else
                end = mid;
        }
        const int rot = begin;
        // [begin, end)
        begin = 0, end = n;
        while (begin < end) {
            const int mid = (begin + end)/2;
            const int rotMid = (mid + rot)%n;
            if (nums[rotMid] == target) return rotMid;
            if (nums[rotMid] < target)
                begin = mid + 1;
            else
                end = mid;
        }
        return -1;
    }
};
