#pragma once
#include <vector>
using namespace std;

// SPDX-License-Identifier: CC0-1.0
// Source: https://github.com/aqua-dhmo/cp-lib
template <typename T>
vector<T> linear_sieve(int N) {
    vector<T> res;
    vector<int> lp(N + 1);
    for (int i = 2; i <= N; ++i) {
        if (!lp[i]) {
            lp[i] = i;
            res.emplace_back(i);
        }
        for (int j = 0; i * res[j] <= N; ++j) {
            lp[i * res[j]] = res[j];
            if (res[j] == lp[i]) break;
        }
    }
    return res;
}
