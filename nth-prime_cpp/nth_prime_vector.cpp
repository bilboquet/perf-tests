#include "nth_prime.h"
#include <vector>
#include <iostream>

using std::cout;
using std::endl;

namespace nth_prime
{
bool is_prime(uint32_t pc, std::vector<uint32_t> &primes)
{
    for (auto p : primes)
    {
        if (pc % p == 0)
        {
            return false;
        }
    }
    return true;
}

uint32_t nth(uint32_t n)
{
    if (n <= 0)
    {
        throw std::domain_error("weird");
    }

    std::vector<uint32_t> primes; // allocate a vector of n int to store the nth first prime numbers
    primes.reserve(n);  // weird we can't preallocate when initializing

    primes.push_back(2); // first known prime

    for (uint32_t i = 1; i < n; i++)
    {
        auto prime_candidate = primes[i - 1] + 1;

        while (!is_prime(prime_candidate, primes))
        {
            prime_candidate++;
        }
        primes.push_back(prime_candidate);
    }
    return primes[n - 1];
}
} // namespace nth_prime}

int main()
{
    cout << nth_prime::nth(20002) << endl;
}
