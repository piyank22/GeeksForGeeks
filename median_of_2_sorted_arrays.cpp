#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution 
{
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) 
    {    
        int sum = m + n;
        if(sum % 2 == 1) 
            return findKth(A, m, B, n, sum/2+1);
        else 
            return (findKth(A, m, B, n, sum/2)+findKth(A, m, B, n, sum/2+1))/2;        
    }
    
    double findKth(int A[], int m, int B[], int n, int k) 
    {   
        if(m > n) return findKth(B, n, A, m, k);
        if(m == 0) return B[k-1];
        if(k == 1) return min(A[0], B[0]);
        
        int aMin = min(m, k/2);
        int bMin = k - aMin;
        if(A[aMin-1] > B[bMin-1]) 
            return findKth(A, aMin, B+bMin, n - bMin, k - bMin);
        else
            return findKth(A+aMin, m-aMin, B, bMin, k - aMin);
    }
};

int main()
{
    Solution s;
    int A[] = {3,5,7,9,11,123,124,125,127};
    int B[] = {1,2,4,22,126};
    int n=
    cout << s.findMedianSortedArrays(A, 9, B, 5);
    
    return 0;
}