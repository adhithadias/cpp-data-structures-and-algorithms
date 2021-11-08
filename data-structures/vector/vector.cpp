#include <vector>
#include <iostream>

using namespace std;


int main (int argc, char* argv[]) {

    int n = 3;
    // Create a vector of size n with
    // all values as 10.
    vector<int> vect1(n, 10);

    vector<int> v1;
    cout << "v.size(): " << v1.size() << endl;

    vector<int> v2{ 1, 2, 3, 4, 5 };
    // capacity
    cout << "v.size(): " << v2.size() << endl;
    cout << "v.max_size(): " << v2.max_size() << endl;
    cout << "v.capacity(): " << v2.capacity() << endl;
    cout << "v.empty(): " << v2.empty() << endl;

    cout << "v.resize(n) changes the size and v.reserve(n) changes the capacity\n";
    cout << "cannot set capacity to a lesser value than the size\n";
    v2.resize(10);
    v2.reserve(4);
    cout << "v.size(): " << v2.size() << endl;
    cout << "v.max_size(): " << v2.max_size() << endl;
    cout << "v.capacity(): " << v2.capacity() << endl;  
    
    cout << "calling v.shrink_to_fit() reduces the capacity back to size\n"; 
    v2.shrink_to_fit(); 
    cout << "v.size(): " << v2.size() << endl;
    cout << "v.max_size(): " << v2.max_size() << endl;
    cout << "v.capacity(): " << v2.capacity() << endl; 

    // iterators
    vector<int>::iterator it = v2.begin();
    cout << "The vector elements in original order are:\n";
    for (; it != v2.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    vector<int>::reverse_iterator rit = v2.rbegin();
    cout << "The vector elements in reverse order are:\n";
    for (; rit != v2.rend(); rit++)
        cout << *rit << " ";
    cout << endl;


    // element access
    cout << "0th element: " << v2.at(0) << endl;
    cout << "1st element: " << v2[1] << endl;
    cout << "front: " << v2.front() << endl;
    cout << "back: " << v2.back() << endl;

    int* p = v2.data(); // p is a pointer
    *p = 100;
    cout << "0th element: " << *p << endl;
    cout << "1st element: " << *(++p) << endl;
    cout << "1st element: " << *p << endl;
    cout << "2nd element: " << p[2] << endl;
    

    
    // // Insert head, index, tail
    // v.insert(v.begin(), value);             // head
    // v.insert(v.begin() + index, value);     // index
    // v.push_back(value);                     // tail

    // // Remove head, index, tail
    // v.erase(v.begin());             // head
    // v.erase(v.begin() + index);     // index
    // v.pop_back();                   // tail

    // // Clear
    // v.clear();

    return 0;
}