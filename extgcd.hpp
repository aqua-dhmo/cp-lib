using ll = long long;

// SPDX-License-Identifier: CC0-1.0
// from kactl (https://github.com/kth-competitive-programming/kactl)

// find integers (x, y) s.t. ax + by = gcd(a, b) and return gcd(a, b)
// guaranteed that |x| <= |b / gcd(a, b)| && |y| <= |a / gcd(a, b)|
// requirement: a, b >= 0 && (a, b) != (0, 0)
// keywords: extended Euclidean, Bezout coefficients
ll extgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) return x = 1, y = 0, a;
    ll d = extgcd(b, a % b, y, x);
    return y -= a/b * x, d;
}
