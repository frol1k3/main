#include <time.h>
#include <iostream>
#include <random>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    srand(time(0));
    bool flag = true;
    while (flag) {
        string answer;
        cout << "Если хотите бросить кости введите любую цифру кроме 0, для выхода введите 0: " << endl;
        cin >> answer;
        if (answer == "0") {
            flag = false;
        }
        else {
            int* player = new int[5];
            for (int i = 0; i < 5; i++) {
                player[i] = rand() % 6 + 1;
            }
            int* bot = new int[5];
            for (int i = 0; i < 5; i++) {
                bot[i] = rand() % 6 + 1;
            }
            
        }
    }
} 