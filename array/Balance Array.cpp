// ----------------------------------------------- Balance Array ---------------------------------------------

// Problem Description

// Given an integer array A of size N. You need to count the number of special elements in the given array.

// A element is special if removal of that element make the array balanced.

// Array will be balanced if sum of even index element equal to sum of odd index element.

// Problem Constraints
// 1 <= N <= 105

// 1 <= A[i] <= 109

// Input Format
// First and only argument is an integer array A of size N.

// Output Format
// Return an integer denoting the count of special elements.

// Example Input
// Input 1:

//  A = [2, 1, 6, 4]
// Input 2:

//  A = [5, 5, 2, 5, 8]

// Example Output
// Output 1:

//  1
// Output 2:

//  2

// Example Explanation
// Explanation 1:

//  After deleting 1 from array : {2,6,4}
//     (2+4) = (6)
//  Hence 1 is the only special element, so count is 1
// Explanation 2:

//  If we delete A[0] or A[1] , array will be balanced
//     (5+5) = (2+8)
//  So A[0] and A[1] are special elements, so count is 2.


int Solution::solve(vector<int> &A) {
    int odd = 0, even = 0;
    for(int i = 0; i<A.size(); i++){
        if(i%2==0) even += A[i];
        else odd += A[i];
    }
    int count = 0;
    for(int i =0;i<A.size();i+=1){
        if(i%2 == 0){
            even -= A[i];
            if(even==odd) count++;
            odd+= A[i];
        }
        else{
            odd -= A[i];
            if(odd==even) count++;
            even+= A[i];
        }
    }
    return count;
}
