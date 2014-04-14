// alternative
class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int sum = 0, max = INT_MIN;
            
        for(int i=0; i<n; i++)
        {
            sum += A[i];
            
            if(sum > max) max = sum;
                
            // rewind
            if(sum < 0) sum = 0;
        }
            
        return max;
    }
};


// alternative
class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int max = INT_MIN, sum = 0, maximum = INT_MIN;
        for(int i=0; i<n; i++)
        {
            if(A[i] > maximum) maximum = A[i];
        
            sum += A[i];
            if(sum < 0) sum = 0; // rewind
        
            if(sum > max) max = sum;
        }
     
        return (maximum < 0 ? maximum : max);
    }
};

// alternative
class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        for(int i=1; i<n; i++)
            A[i] += A[i-1];
        
        // it's the same problem as buying and selling stocks 
        int max = A[0], min = A[0], m = A[0];
        for(int i=1; i<n; i++)
        {
            if(max < A[i]-min)
                max = A[i]-min;
                
            if(A[i] < min)
                min = A[i];
                
            if(m < A[i]) m = A[i];
        }
        
        return max > m ? max : m;
    }
};

