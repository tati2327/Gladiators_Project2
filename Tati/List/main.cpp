#include <iostream>
#include "List.h"

using namespace std;

int main() {

    List<string> list;
    list.add("Hello");
    list.add("Another message");
    list.add("Third message!");
    cout << list[1] <<endl;
    return 0;
}