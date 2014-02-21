class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int s = 0, e = n-1;
        while(s <= e)
        {
            int mid = s + (e-s)/2;
            if(target > A[mid]) s = mid+1;
            else if(target < A[mid]) e = mid-1;
            else return mid;
        }
        
        return s;
    }
};
