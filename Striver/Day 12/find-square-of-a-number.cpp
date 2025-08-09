int square(int n)
{
    if(n == 0) return 0;
    if(n<0) n = -n;
    int x = n>>1;
    if(n & 1) return square(x) << 2 + x<<2 + 1; // 4x^2 + 4x + 1
    else return square(x) << 2; // 4x^2
}

// soln: https://www.geeksforgeeks.org/calculate-square-of-a-number-without-using-and-pow/