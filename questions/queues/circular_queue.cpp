#include <stdexcept>
#include <vector>
#include <iostream>

using namespace std;

class Queue {
public:
    explicit Queue(size_t capacity) : _entries(capacity) {}

    void Enqueue(int x) {
        if (num_of_entries == _entries.size()) {
            rotate(_entries.begin(), _entries.begin() + _head, _entries.end());
            _head = 0; _tail = num_of_entries;
            _entries.resize(_entries.size() * kScaleFactor);
        }
        _entries[_tail] = x;
        _tail = (_tail+1) % _entries.size(); ++num_of_entries;
    }

    int Dequeue() {
        if (!num_of_entries) {
            throw length_error("No entries in the queue");
        }
        int x = _entries[_head];
        _head = (_head+1)%_entries.size(); --num_of_entries;
        return x;
    }

    size_t size() const { return num_of_entries; }

    void Print() {
        size_t ptr = _head;

        for (size_t i = 0; i<num_of_entries; i++) {
            cout << _entries[ptr] << " ";
            ptr = (ptr+1)%num_of_entries;
        }
    }


private:
    vector<int> _entries;
    size_t _head = 0, _tail = 0, num_of_entries = 0;
    int kScaleFactor = 2;
};


int main() {

    Queue q(4);
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    cout << q.Dequeue() << endl;
    q.Enqueue(5);
    q.Print();

    return 0;
}



/*

A - alpha
B - bravo
C - charlie
D - delta
E - echo
F - foxtrot
G - golf
H - hotel
I - India
J - juliette
K - kilo
L - lima
M - mike
N - november
O - oscar
P - papa
Q - quebec
R - romeo
S - sierra
T - tango
U - uniform
V - victor
W - whiskey
X - x-ray
Y - yankee
Z - zulu


K - kilo
A - apple
R - romeo
I - india
Y - yankee
A - apple
W - whiskey
A - apple
S - sierra
A - apple
M - mike

M - mike
A - apple
J - juliette
U - uniform
W - whiskey
A - apple
N - november
A - apple

G - google
A - apple
M - mike
A - apple
G - google
E - echo

D - delta
O - oscar
G - google

A - apple
D - delta
H - hotel
I - india
T - tango
H - hotel
A - apple

W - whiskey
E - echo
E - echo
R - romeo
A - apple
S - sierra
I - india
R - romeo
I - india

D - delta
I - india
A - apple
S - sierra



*/