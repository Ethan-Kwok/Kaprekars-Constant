#include <iostream>
#include <string>
#include <math.h>
#include <list>

using namespace std;

long leastToGreatest(int dig[], int numDig) {
    for (int i = 0; i < numDig - 1; i++) {
        for (int j = 0; j < numDig - 1 - i; j++) {
            if (dig[j] < dig[j + 1]) {
                int temp = dig[j];
                dig[j] = dig[j + 1];
                dig[j + 1] = temp;
            }
        }
    }

    long output = 0;
    for (int i = 0; i < numDig; i++) {
        output += dig[i] * pow (10, i);
    }

    return output;
}


long greatestToLeast(int dig[], int numDig) {
    for (int i = 0; i < numDig - 1; i++) {
        for (int j = 0; j < numDig - 1 - i; j++) {
            if (dig[j] > dig[j + 1]) {
                int temp = dig[j];
                dig[j] = dig[j + 1];
                dig[j + 1] = temp;
            }
        }
    }

    long output = 0;
    for (int i = 0; i < numDig; i++) {
        output += dig[i] * pow (10, i);
    }

    return output;
}


int countdigit(long input) {
    if (input == 0) return 1;
    int count = 0;
    while (input != 0) {
        input = input/10;
        count++;
    }
    return count;
}


int main() {
    long input;
    cout << "Input: ";
    cin >> input;
    list<long>mlist;
    int count = 0;

    for (int i = 0; i < 9999; i++) {
        for (long const& j : mlist) {
            if (input == j) goto EXIT;
        }
        mlist.push_back(input);

        int numDig = countdigit(input);
        int dig[numDig];
        for (int j = 0; j < numDig; j++) {
            dig[j] = int (input / pow (10, j)) % 10;
        }
        
        long ltog = leastToGreatest(dig, numDig);
        long gtol = greatestToLeast(dig, numDig);
        //cout << "ltog: " << ltog << ". gtol: " << gtol << ". difference: " << gtol - ltog << endl;  
        input = gtol - ltog;
        count++;
    }
    EXIT: cout << "Order of outputs: ";
    for (long const& i : mlist) {
        cout << i << " ";
    }
    cout << endl << "First repeated value: " << input << endl;
    cout << "Number of iterations: " << count << endl;
}