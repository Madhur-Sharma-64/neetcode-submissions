class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int i1 = 0;
        int i2 = 0;
        vector<int> comb;

        while ( i1 < n && i2 < m ) {
            if ( nums1[i1] < nums2[i2] ) {
                comb.push_back(nums1[i1]);
                i1++;
            } else {
                comb.push_back(nums2[i2]);
                i2++;
            }
        }

        while (i1 < n) comb.push_back(nums1[i1++]);
while (i2 < m) comb.push_back(nums2[i2++]);

        int c = (n+m)/2;
        if ( (n+m) %2 == 0 ) return (double)(comb[c] + comb[c-1])/2;

        return comb[c];
    }
};
