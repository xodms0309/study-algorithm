#include <iostream>
#include <vector>
using namespace std;
const int MAXSIZE = 10000;

template<typename T> class Stack {
private:
	int _size;
	T data[MAXSIZE];
public:
	Stack() {
		_size = 0;
	}
	~Stack() {}
	void push(T input) {
		data[_size] = input;
		_size += 1;
	}
	T pop() {
		T temp = data[_size - 1];
		data[_size - 1] = 0;
		_size -= 1;
		return temp;
	}
	int size() {
		return _size;
	}
	bool empty() {
		return _size == 0 ?  true : false;
	}
	T top() {
		return data[_size - 1];
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	Stack<int> s;
	while (n--) {
		string cmd;
		cin >> cmd;
		if (cmd == "push") {
			int x;
			cin >> x;
			s.push(x);
		}
		else if (cmd == "top") {
			if (s.empty()) cout << "-1\n";
			else cout << s.top() << "\n";
		}
		else if (cmd == "pop") {
			if (s.empty())cout << "-1\n";
			else cout << s.pop() << "\n";
		}
		else if (cmd == "size") {
			cout << s.size() << "\n";
		}
		else if (cmd == "empty") {
			if (s.empty()) cout << "1\n";
			else cout << "0\n";
		}
	}
}
