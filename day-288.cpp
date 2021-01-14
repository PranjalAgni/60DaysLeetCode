/*
Minimum Operations to Reduce X to Zero

Solution
You are given an integer array nums and an integer x. In one operation, you can
either remove the leftmost or the rightmost element from the array nums and
subtract its value from x. Note that this modifies the array for future
operations.

Return the minimum number of operations to reduce x to exactly 0 if it's
possible, otherwise, return -1.



Example 1:

Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x
to zero. Example 2:

Input: nums = [5,6,7,8,9], x = 4
Output: -1
Example 3:

Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the
first two elements (5 operations in total) to reduce x to zero.


Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 104
1 <= x <= 109
*/

// Simple two pointer solution
class Solution {
   public:
    int ans = INT_MAX;
    int minOperations(vector<int>& nums, int x) {
        int total = 0, n = nums.size();
        for (int num : nums) total += num;
        int need = total - x, cur = 0, longest = 0;
        if (need == 0) return n;
        int l = 0, r = 0;
        while (l < n && r < n) {
            if (cur < need) {
                cur += nums[r++];
            } else if (cur > need) {
                cur -= nums[l++];
            } else {
                longest = max(longest, r - l);
                cur -= nums[l++];
            }
        }
        if (cur == need) longest = max(longest, r - l);
        if (longest == 0) return -1;
        return n - longest;
    }
};