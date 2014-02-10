class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        if((m+n) % 2 == 0)
           return ( findKth(A, m, B, n, (m+n+1)/2) + findKth(A, m, B, n, (m+n+2)/2) )/2.0;
        else
           return findKth(A, m, B, n, (m+n+1)/2);
    }
    
    double findKth(int A[], int m, int B[], int n, int k) {
        // find k_th element in A and B
        if(m > n) return findKth(B, n, A, m, k);
        if(m == 0) return B[k-1]; 
        if(k == 1) return min(A[0], B[0]);
        
        // m <= n
        int pa = min(k/2, m);
        int pb = k - pa;
        
        return (A[pa-1] <= B[pb-1]) ? findKth(A+pa, m-pa, B, n, pb) : findKth(A, m, B+pb, n-pb, pa);
    }
};
