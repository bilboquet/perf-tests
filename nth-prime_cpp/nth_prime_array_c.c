#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

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
        return 0;
    }

    uint32_t primes[n];
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

    return prime_candidate;
}

int main()
{
    printf("%u\n", nth(20002));
}
