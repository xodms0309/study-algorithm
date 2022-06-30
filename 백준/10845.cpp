#include <iostream>
#include <vector>
using namespace std;
const int MAXSIZE = 10000;

template<typename T> class Queue {
private:
	int _front;
	int _back;
	T data[MAXSIZE];
public:
	Queue() {
		_front = -1;
		_back = -1;
	}
	~Queue(){}
	void push(T input) {
		this->data[this->_back + 1] = input;
		this->_back += 1;
		return;
	}
	T pop() {
		T res = this->data[this->_front + 1];
		this->_front += 1;
		return res;
	}
	int size() {
		return this->_back - this->_front;
	}
	bool empty() {
		return this->size() == 0 ? true : false;
	}
	T front() {
		T res = this->data[this->_front + 1];
		return res;
	}
	T back() {
		T res = this->data[this->_back];
		return res;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	Queue <int> q;
	while (n--) {
		string cmd;
		cin >> cmd;
		if (cmd == "push") {		
			int x;
			cin >> x;
			q.push(x);
		}
		else if (cmd == "pop") {
			if (q.empty()) cout << -1 << "\n";
			else  cout << q.pop() << "\n";
		}
		else if (cmd == "front") {
			if (q.empty()) cout << -1 << "\n";
			else cout << q.front() << "\n";
		}
		else if (cmd == "back") {
			if (q.empty()) cout << -1 << "\n";
			else cout << q.back() << "\n";
		}
		else if (cmd == "empty") {
			if (q.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (cmd == "size") {
			cout << q.size() << "\n";
		}
	}
}
