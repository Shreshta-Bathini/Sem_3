// ************************************************************
// DO NOT CHANGE ANYTHING IN THIS FILE
// ************************************************************
#include "common.h"
#include "deque-and-inheritance.h"

using namespace std;
int main() {
    string line;
    Queue<int>* q = nullptr;
    Stack<int>* s = nullptr;

    while (getline(cin, line)) {
        stringstream ss(line);
        string cmd;
        ss >> cmd;

        if (cmd == "queue") {
            string type; int cap; ss >> type >> cap;
            q = new Queue<int>(cap);
        } else if (cmd == "stack") {
            string type; int cap; ss >> type >> cap;
            s = new Stack<int>(cap);
        } else if (cmd == "push") {
            int val; ss >> val;
            if (q) q->push(val);
            if (s) s->push_back(val); 
        } else if (cmd == "pop") {
            if (q) cout << q->pop_front() << endl;
            if (s) cout << s->pop_back() << endl;
        } else if (cmd == "peek") {
            if (q) cout << q->peek_front() << endl;
            if (s) cout << s->peek_back() << endl;
        } else if (cmd == "print") {
            if (q) cout << *q << endl;
            if (s) cout << *s << endl;
        }
    }

    delete q;
    delete s;

    return 0;
}
