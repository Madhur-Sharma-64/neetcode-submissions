class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int>& A = nums1;
        vector<int>& B = nums2;
        int total = n+m;
        int half = (total+1)/2;

        if ( n > m ) {
            swap(A, B);
            swap(n, m);
        }

        int l = 0;
        int r = n;

        while ( l <= r ) {
            int i = (r+l)/2;
            int j = half-i;

            int Aleft = i > 0 ? A[i-1] : INT_MIN;
            int Aright = i < n ? A[i] : INT_MAX;
            int Bleft = j > 0 ? B[j-1] : INT_MIN;
            int Bright = j < m ? B[j] : INT_MAX;

            if ( Aleft <= Bright && Bleft <= Aright ) {
                if ( total % 2 != 0 ) return max(Aleft, Bleft);

                return (max(Aleft, Bleft) + min(Aright, Bright))/2.0;

            } else if ( Aleft > Bright ) r = i-1;
            else l = i+1;

        }

        return -1;
    }
};
