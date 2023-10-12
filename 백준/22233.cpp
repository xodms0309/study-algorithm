#include <iostream>
#include <vector>
#include <unordered_set>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> cutWords(string original) {
    stringstream ss(original);
    char delim = ',';
    vector<string> v;
    string temp="";
    while (getline(ss, temp, delim)) {
        v.push_back(temp);
	}
	return v;
}


int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<string> keywords(n);
    unordered_set<string> s;

    
    for (int i=0; i<n; i++) {
        cin >> keywords[i];
        s.insert(keywords[i]);
    }
    
    for (int i=0; i<m; i++) {
        string written;
        cin >> written;
        vector<string> words = cutWords(written);
        for (int j=0; j<words.size(); j++) {
            if (s.find(words[j])!=s.end()) {
                s.erase(words[j]);
            }
        }
        
        cout << s.size() << "\n";
    }
}
