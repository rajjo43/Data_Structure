#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseQueue(queue<int>& q) {
    stack<int> s;
    
    // Transfer all elements from queue to stack
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }
    
    // Transfer all elements back from stack to queue in reversed order
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

int main() {
    int T;
    cin >> T; // number of test cases

    while (T--) {
        int N;
        cin >> N; // number of elements in the queue
        
        queue<int> q;
        
        // Input elements in the queue
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            q.push(x);
        }
        
        // Reverse the queue
        reverseQueue(q);
        
        // Output the reversed queue
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
        cout << endl;
    }

    return 0;
}
