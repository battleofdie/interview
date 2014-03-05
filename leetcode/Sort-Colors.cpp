class Solution {
public:
    void sortColors(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int r = -1, b = n, i = r+1;
        while(i < b)
        {
            if(A[i] == 0)
            { 
                // swap A[r+1] and A[i]; then i++,r++
                A[i++] = A[++r];
                A[r] = 0;
            }
            else if(A[i] == 2)
            {
                // swap A[b-1] and A[i]; then b--
                A[i] = A[--b];
                A[b] = 2;
            }
            else
                i++;
        }
    }
};
