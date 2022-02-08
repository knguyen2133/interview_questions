// Given an array of strings strs, group the anagrams together. You can return the answer in any order.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

// Time Complexity: O(nklog(k)) single pass through the list and sorted
// Space Complexity: O(nk) The map and the result data structure
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> result;
        std::map<string, vector<string>> storage;
        //cast a loop around the entries of the vector strings
        for (auto const str_entry : strs)
        {
            //sort the entry and find key based off it
            auto sorted_str = str_entry;
            sort(sorted_str.begin(), sorted_str.end());

            storage[sorted_str].push_back(str_entry);
        }

        for (auto const &[key, value] : storage)
        {
            result.push_back(value);
        }

        return result;
    }
};