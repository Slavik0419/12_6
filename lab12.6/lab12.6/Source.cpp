#include <iostream>

using namespace std;

struct Elem {
    Elem* link;
    int info;
};

void enqueue(Elem*& first, Elem*& last, int value) {
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->link = NULL;
    if (last != NULL)
        last->link = tmp;
    last = tmp;
    if (first == NULL)
        first = tmp;
}

int dequeue(Elem*& first, Elem*& last) {
    Elem* tmp = first->link;
    int value = first->info;
    delete first;
    first = tmp;
    if (first == NULL)
        last = NULL;
    return value;
}

int main() {
    int numbers[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    Elem* odd_first = NULL, * odd_last = NULL;
    Elem* even_first = NULL, * even_last = NULL;
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            enqueue(even_first, even_last, numbers[i]);
        }
        else {
            enqueue(odd_first, odd_last, numbers[i]);
        }
    }
    cout << "Odd queue: ";
    Elem* cur = odd_first;
    while (cur != NULL) {
        cout << cur->info << " ";
        cur = cur->link;
    }
    cout << endl;
    cout << "Even queue: ";
    cur = even_first;
    while (cur != NULL) {
        cout << cur->info << " ";
        cur = cur->link;
    }
    cout << endl;
    return 0;
}
