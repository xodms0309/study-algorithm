#include <iostream>

using namespace std;

bool check(string str, int start, int end) {
    int middle = (start+end)/2;
    
    int rightSum=0;
    int leftSum=0;
    
    for (int i=start; i<=middle; i++) {
        leftSum+=str[i]-'0';
    }
    for (int i=middle+1; i<=end; i++) {
        rightSum+=str[i]-'0';
    }
    
    if (leftSum==rightSum) return true;
    return false;
}

int main()
{
    string str;
    cin >> str;
    int answer=0;
    for (int i=0; i<str.length(); i++) {
        for (int j=i; j<str.length(); j++) {
            if ((j-i+1)%2!=0) continue; //길이가 2가 되지 않는 경우
            if (check(str, i, j)) {
                answer=max(answer, j-i+1);
            }
        }
    }
    cout << answer;
}
