#include <string>
#include <vector>
#include <stack>

using namespace std;
struct Node {
    bool removed;
    Node* prev;
    Node* next;
};
Node NodeArr[10000001];

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    for (int i=1; i<n; i++) {
        NodeArr[i-1].next=&NodeArr[i];
        NodeArr[i].prev=&NodeArr[i-1];
    }
    
    Node* cursor=&NodeArr[k];
    stack<Node*> deleted;
    
    for (string str:cmd) {
        if (str[0]=='D') {
            int x=stoi(str.substr(2));
            while (x--) {
                cursor=cursor->next;
            }
        }
        else if (str[0]=='U') {
            int x=stoi(str.substr(2));
            while (x--) {
                cursor=cursor->prev;
            }
        }
        else if (str[0]=='C') {
            deleted.push(cursor);
            Node* up=cursor->prev;
            Node* down=cursor->next;
            cursor->removed=true;
            if (up) {
                up->next=down;
            }
            if (down){
                down->prev=up;
                cursor=down;
            }
            else {
                cursor=up;
            }
        }
        else {
            Node* recover=deleted.top();
            deleted.pop();
            recover->removed=false;
            Node* up=recover->prev;
            Node* down=recover->next;
            
            if (up) {
                up->next=recover;
            }
            if (down){
                down->prev=recover;
            }
        }
        
    }
    for (int i=0; i<n; i++) {
        if (NodeArr[i].removed) answer+='X';
        else answer+='O';
    }
    return answer;
}
