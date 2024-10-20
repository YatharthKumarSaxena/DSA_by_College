// Iterative soution of Tower of Hanoi
// Don't do amendment in code otherwise program will malfunction
// Run the code in this file as int main function is provided
#include <iostream>
#include <stack>
using namespace std;

struct Frame {
    int n;      // Number of disks
    char beg;   // Source rod
    char aux;   // Auxiliary rod
    char end;   // Destination rod
    int step;   // Current step in the process
};

void towerOfHanoi(int N, char BEG, char AUX, char END) {
    stack<Frame> st;
    st.push({N, BEG, AUX, END, 1});  // Initial frame with step = 1

    while (!st.empty()) {
        Frame &f = st.top();

        switch (f.step) {
            case 1:
                if (f.n == 1) {
                    cout << "Move disk from " << f.beg << " to " << f.end << endl;
                    st.pop();  // Frame done, pop it
                } else {
                    f.step = 2;
                    st.push({f.n - 1, f.beg, f.end, f.aux, 1});
                }
                break;

            case 2:
                cout << "Move disk from " << f.beg << " to " << f.end << endl;
                f.step = 3;
                break;

            case 3:
                st.pop();
                st.push({f.n - 1, f.aux, f.beg, f.end, 1});
                break;
        }
    }
}

int main() {
    int N;
    cout << "Enter the number of disks: ";
    cin >> N;
    towerOfHanoi(N, 'A', 'B', 'C');
    return 0;
}