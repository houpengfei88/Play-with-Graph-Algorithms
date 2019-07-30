#include <iostream>
#include "AdjMatrix.h"

int main() {
    std::string filename = "../g.txt";
    AdjMatrix *adjMatrix = new AdjMatrix(filename);
    adjMatrix->print();
    return 0;
}