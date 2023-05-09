#include "tests.h"
#include "rational.h"

int main() {
    std::cout << "Start: Testing..." << std::endl;
    TestInitialization();
    TestArithmeticOperations();
    TestUnaryOperators();
    TestRelationalOperators();
    TestInputOutputOperations();
    std::cout << "End: All tests passed successfully.";
    return 0;
}