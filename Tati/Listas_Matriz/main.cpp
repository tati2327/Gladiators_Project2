#include <iostream>
#include "List.h"
#include "Matrix.h"

using namespace std;

int main() {

    List<int> l1;
    l1.add(2);
    l1.add(3);
    l1.add(5);

    l1.getNode(0)->next = l1.getNode(2)->next;

    return 0;
}