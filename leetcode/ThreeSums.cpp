// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

// Time Complexity = O(n^2+nlogn) = 0(n)
// Space Complexity = O(n)
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> storage;
        // for loop that "hard codes" the first value and go into a two sum
        //  sorted method means that negative numbers are expected for the 0 result i.e. nums[i] <= 0
        for (size_t i = 0; i < nums.size() && nums[i] <= 0; ++i)
        {
            if (i == 0 || nums[i - 1] != nums[i])
                twoSum(storage, num, i);
        }
        return storage;
    }

    // index will always be the left most point that doesnt move. pinch left and right based on the result
    // of the summation. if a match occurs then shrink both positions. left will always be non-zero index-wise to check back
    void twoSum(vector<vector<int>> &storage, vector<int> &nums, int index)
    {
        for (size_t left = 0, right = nums.size() - 1; left < right;)
        {
            auto sum = nums[i] + nums[left] + nums[right];
            if (sum > 0)
            {
                --right;
            }
            if (sum < 0)
            {
                ++left;
            }
            else
            {
                storage.push_back({nums[i], nums[left], nums[right]});
                ++left;
                --right;
                // to avoid duplication, iterate the left side up
                while (nums[left] == nums[left - 1] && left < right)
                    ++left;
            }
        }
    }
};