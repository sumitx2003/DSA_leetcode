class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIdx = 0, maxIdx = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minIdx]) minIdx = i;
            if (nums[i] > nums[maxIdx]) maxIdx = i;
        }

        if (minIdx > maxIdx)
            swap(minIdx, maxIdx);

        return min({
            maxIdx + 1,                // remove from front
            n - minIdx,                // remove from back
            minIdx + 1 + (n - maxIdx)  // one front, one back
        });
    }
};
