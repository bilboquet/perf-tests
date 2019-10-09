#include "nth_prime.h"
#include <vector>
#include <iostream>

using std::cout;
using std::endl;

namespace nth_prime
{
bool is_prime(uint32_t pc, const uint32_t *const primes, uint32_t len)
{
    for (uint32_t i = 0; i < len; i++)
    {
        if (pc % primes[i] == 0)
        {
            return false;
        }
    }
    return true;
}

uint32_t nth(uint32_t n)
{
    if (n <= 1)
    {
        throw std::domain_error("weird");
    }

    uint32_t *primes = new uint32_t[n];
    uint32_t prime_candidate;
    primes[0] = 2; // first known prime

    for (uint32_t i = 1; i < n; i++)
    {
        prime_candidate = primes[i - 1] + 1;

        while (!is_prime(prime_candidate, primes, i))
        {
            prime_candidate++;
        }
        primes[i] = prime_candidate;
    }
    delete[] primes;
    return prime_candidate;
}
} // namespace nth_prime

int main()
{
    cout << nth_prime::nth(20002) << endl;
}
