#pragma once
#include <vector>
using namespace std;

// SPDX-License-Identifier: CC0-1.0
// Source: https://github.com/aqua-dhmo/cp-lib

// return primes less than or equal to N in ascending order
template <typename T>
vector<T> eratosthenes(int N) {
    vector<T> res;
    vector<bool> isprime(N + 1, true);
    isprime[0] = isprime[1] = false;
    for (int i = 4; i <= N; i += 2) isprime[i] = false;
    for (int i = 3; i*i <= N; i += 2) {
        if (!isprime[i]) continue;
        for (int j = i*i; j <= N; j += i) isprime[j] = false;
    }
    if (N >= 2) res.emplace_back(2);
    for (int i = 3; i <= N; i += 2) if (isprime[i]) res.emplace_back(i);
    return res;
}
