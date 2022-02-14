// Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.
// [3, 4, 7, 2, -3, 1, 4, 2]

//Time Complexity O(n)
//Space Complexity O(n)
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        // <sum[i], number of occurances
        std::map<int, int> storage_map;
        // add 0 as thats a base condition
        storage_map.emplace(std::make_pair(0, 1));
        int sum = 0;
        int count = 0;
        for (auto &num_entry : nums)
        {
            sum += num_entry;
            auto storage_entry = storage_map.find(sum - k);
            if (storage_entry != storage_map.end())
            {
                count += storage_entry->second;
            }
            storage_map[sum]++;
        }
        return count;
    }
};