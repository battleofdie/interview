class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        while(m && n)
        {
            if(A[m-1] > B[n-1])
                A[m+n-1] = A[--m];
            else
                A[m+n-1] = B[--n];
        }
       
        while(n) A[n-1] = B[--n];
    }
};
