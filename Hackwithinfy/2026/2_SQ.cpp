#include <bits/stdc++.h>
using namespace std;

class Sq {
public:
    bool canWin(vector<int>& v, int M, int H, int start) {
        int i = start;
        while (M > 0 && i < v.size()) {
            int health = H;

            while (i < v.size()) {
                if (health > v[i]) {
                    health -= v[i];
                    i++;
                } else if (health == v[i]) {
                    i++;
                    break;
                } else {
                    break;
                }
            }
            M--;
        }
        return i == v.size();
    }

    int minRemove(vector<int>& v, int M, int H) {
        int n = v.size();

        for (int k = 0; k < n; k++) {
            if (canWin(v, M, H, k)) return k;
        }
        return n;
    }
};

int main() {
    int N, M, H;
    cout << "Enter N,M,H (Space separated) : "; 
    cin >> N >> M >> H;

    vector<int> v(N);
    cout << "Enter Villains Health" << endl; 
    for (int i = 0; i < N; i++){
        cin >> v[i];
    }

    Sq s;
    cout << "Minimum removable : " << s.minRemove(v, M, H) << endl;
}