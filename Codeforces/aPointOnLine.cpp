#include <iostream>
#include <numeric>
using namespace std; 

// Using long long for large numbers up to 10^18
typedef long long ll;

ll extended_gcd(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = extended_gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

int main() {
    ll A, B, C;
    std::cin >> A >> B >> C;
    ll x, y;
    ll g = extended_gcd(std::abs(A), std::abs(B), x, y);

    if (std::abs(C) % g != 0) {
        std::cout << -1 << std::endl;
        return 0;
    }

    // Scale x, y and adjust signs
    x *= -C / g;
    y *= -C / g;
    if (A < 0) x = -x;
    if (B < 0) y = -y;

    std::cout << x << " " << y << std::endl;
    return 0;
}
