/*Implement integer exponentiation. That is, implement the pow(x, y) function, where x and y are integers and returns x^y.

Do this faster than the naive method of repeated multiplication.*/

long long pow(long long x, long long y) {
    long long res = 1;
    while (y > 0) {
        if (y % 2 !=0)
            res = res * x;
        x = x * x;
        y=y/2;
    }
    return res;
}
