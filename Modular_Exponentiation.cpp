// For a given a, b and MOD, find a raised to the power b modulo MOD
// Solution is given in O(log b) complexity

#include <iostream>

typedef long long int ll;

ll MOD;

ll power(ll a, ll b)
{
    a %= MOD;
    if (a == 0)
    {
        return 0;
    }
    ll ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans *= a;
            ans %= MOD;
        }
        a *= a;
        a %= MOD;
        b >>= 1;
    }
    return ans;
}

int main()
{
    ll a, b;
    printf("Enter the value of a, b, and MOD\n");
    scanf("%lld %lld %lld", &a, &b, &MOD);
    printf("%lld raised to the power %lld modulo %lld is %lld", a, b, MOD, power(a, b));
}
