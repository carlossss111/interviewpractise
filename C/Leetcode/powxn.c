/*
50. Pow(x, n)
Medium

Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

Example 1:
Input: x = 2.00000, n = 10
Output: 1024.00000

Example 2:
Input: x = 2.10000, n = 3
Output: 9.26100

Example 3:
Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25

Constraints:
-100.0 < x < 100.0
-231 <= n <= 231-1
n is an integer.
Either x is not zero or n > 0.
-104 <= xn <= 104
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef SHOW
long double naiveApproach(long double x, int n){
    // This approach does not work because it is O(n).
    // E.g. x = 0.00001 and n = 2148483647 is too large
    
    long double xinit = x;
    
    // Positive Powers
    if (n > 0) {
        for(; n > 1; n--){
            x *= xinit;
        }
    }
    // Zeroth Power
    else if (n == 0) {
        x = 1;
    }
    // Negative Power
    else {
        for(; n < -1; n++){
            x *= xinit;
        }
        x = 1 / x;
    }
    
    return x;
}
#endif

/*
To do this properly, we need to use recursion.
This means we can do it in O(logn) time and O(logn) space.
N.B: it is logn space because of the recursive stack.

Example:
2^8 = 2^4 * 2^4
    = (2^2 * 2^2) * (2^2 * 2^2)
    = (2 * 2) * (2 * 2) * (2 * 2) * (2 * 2)

[x=2,n=0] When we reach the very bottom, n = 0 (because int 1/2 is truncated in C), hence we return 1.
[x=2,n=1] Above, 1 * 1 == 1. Since 1 % 2 == 0, return 2 * 1.
[x=2,n=2] Above that, we return 2 * 2 == 4.
[x=2,n=4] Then, we return 4 * 4 == 16.
[x=2,n=8] Finally, we return 16 * 16 == 256.
*/

long double recursiveApproach(long double x, long int n){
    // Base Cases
    if (x == 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }
    
    // Step by halfing power
    long double result = recursiveApproach(x, n / 2);

    // After getting the result from the power below, square.
    result *= result;
    
    // If an odd number, multiply once more
    if ( n % 2 == 1 ){
        return result * x;
    }
    
    return result;
}

long double myPow(long double x, long int n) {
    
    long int absn = n;
    if(n < 0)
        absn = -n;
    
    long double result = recursiveApproach(x, absn);
    
    if (n < 0)
        result = 1 / result;
    
    return result;
}

int main(int argc, char** argv){
    long double result = recursiveApproach(2, 8);
    printf("%Lf\n", result);
    return 0;
}