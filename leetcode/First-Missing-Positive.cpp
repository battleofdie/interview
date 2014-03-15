class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        // Let A[A[i] -1] = A[i]
        for(int i=0; i<n;)
        {
            if(A[i] > 0 && A[i] != i+1 && A[i] < n+1 && A[i] != A[A[i] -1])
            {
                int temp = A[A[i] - 1];
                A[A[i] - 1] = A[i];
                A[i] = temp;
            }
            else ++i;
        }
        
        int i=0;
        while(i<n && A[i] == i+1) i++;
        
        return i+1;
    }
};
