#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

void printStackReverse(stack<int>& toPrint);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    stack<int> trucks;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;

        bool destroyed = false;
        if (input < 0) {
            while (trucks.size() != 0) {
                if (trucks.top() > 0) {
                    if (trucks.top() > abs(input)) {
                        destroyed = true;

                        break;
                    }
                    else if (trucks.top() < abs(input)) {
                        trucks.pop();
                    }
                    else {
                        trucks.pop();
                        destroyed = true;
                        
                        break;
                    }
                }
                else {
					break;
                }
            }
        }

        if (!destroyed) {
            trucks.push(input);
        }
    }
    
    if (!trucks.empty()) {
        printStackReverse(trucks);
    }
    else {
        printf("%s", "\n");
    }

    return 0;
}

void printStackReverse(stack<int>& toPrint) {
    int temp;
    temp = toPrint.top();
    toPrint.pop();

    if (toPrint.size() != 0) {
        printStackReverse(toPrint);
    }

    printf("%d ", temp);
}