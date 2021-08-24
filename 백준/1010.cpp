#include <iostream>
using namespace std;

int main() {
    int T, N, M;
    int DP[31][31] = { 0 };
    cin >> T;
    while (T--){
        cin >> N >> M;
        for (int i = 1; i <= M; i++) {
            DP[1][i] = i;
        }

        for (int i = 2; i <= N; i++) {
            for (int j = 2; j <= M; j++) {
                DP[i][j] = DP[i - 1][j - 1] + DP[i][j - 1];
            }
        }
        cout << DP[N][M] << "\n";
    }
}
