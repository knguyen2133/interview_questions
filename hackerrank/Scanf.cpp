//Input consists of the following space-separated values: int, long, char, float, and double, respectively.
//Print each element on a new line in the same order it was received as input.
//Note that the floating point value should be correct up to 3 decimal places and the double to 9 decimal places.
//3 12345678912345 a 334.23 14049.30493

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int a =0 ;
    long b = 0;
    char c=0;
    float d= 0.0;
    double e = 0.0;
    
    scanf("%d %ld %c %f %lf", &a, &b, &c, &d, &e);
    printf("%d\n%ld\n%c\n%.3f\n%.9lf", a, b, c, d, e);
    
    return 0;
}