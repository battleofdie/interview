class Solution {
public:
   double findMedianSortedArrays(int A[], int m, int B[], int n) {
      // Note: The Solution object is instantiated only once and is reused by each test case.
      return ( findKth(A, m, B, n, (m+n+1)>>1) + findKth(A, m, B, n, (m+n+2)>>1) )/2.0;
   }
    
   double findKth(int A[], int m, int B[], int n, int k) {
      // find k_th element in A and B
      if(m > n) return findKth(B, n, A, m, k);
      if(m == 0) return B[k-1]; 
      if(k == 1) return min(A[0], B[0]);
        
      // m <= n
      int pa = min(k>>1, m);
        
      return (A[pa-1] <= B[k-pa-1]) ? findKth(A+pa, m-pa, B, n, k-pa) : findKth(A, m, B+k-pa, n-k+pa, pa);
   }
};
