// You are given two integer arrays nums1 and nums2, 
// sorted in non-decreasing order, and two integers m and n,
// representing the number of elements in nums1 and nums2 respectively.
// Merge nums1 and nums2 into a single array sorted in non-decreasing order.
// The final sorted array should not be returned by the function,
// but instead be stored inside the array nums1. 
// To accommodate this, nums1 has a length of m + n,
// where the first m elements denote the elements that should be merged, 
// and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(!nums2.size())
        {
          return;
        }
      
        // cast a loop around the first vector and have conditions to involve the second one
        int n_index = 0;
        int m_index = 0;
        for( auto it = nums1.begin(); it != nums1.end(); ++it )
        {
        // we will pop the vector and insert the new one when we see a case where the second vector is preferred to fit
        //base condition compare nums 1 to nums 2 in their respective indexes
            if((m_index >= m) || ((n_index < n) &&(*it >= nums2[n_index] )))
            {
                nums1.pop_back();
                nums1.insert(it, nums2[n_index]);
                ++n_index;
            }
            else{
                ++m_index;
            }

        }
    }
};