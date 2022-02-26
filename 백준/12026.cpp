#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;	

int main() {
	int N;
	cin >> N;
	vector<char> block(1001);
	vector <int> energy(1001, 1000000);
	for (int i = 1; i <= N; i++) {
		cin >> block[i];
	}
	energy[1] = 0;
	for (int i = 1; i <N; i++) {
		for (int j = i+1; j <= N; j++) {
			if ((block[i] == 'B' && block[j] == 'O')||(block[i] == 'O' && block[j] == 'J')||(block[i] == 'J' && block[j] == 'B')) {
				energy[j] = min(energy[j], energy[i] + (j - i) * (j - i));
			}
			else continue;
		}
	}
	if (energy[N] == 1000000) cout << -1;
	else cout << energy[N];
}
