class Solution {
public:
  int removeDuplicates(int A[], int n) {
    if(n == 0) return 0;
	            
    int size = 1;
    for(int i=1; i<n; i++)
      {
	if(A[i] != A[size-1])
	  {
	    A[size++] = A[i];
	  }
      }
													        
    return size;
  }
};
