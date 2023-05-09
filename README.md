# Rational Class
This project is a C++ implementation of a Rational class, which allows for basic arithmetic operations on fractions. The class provides methods for addition, subtraction, multiplication, and division of Rational objects, as well as overloaded operators for comparison and assignment.



## Usage
### Create a Rational object
```cpp
Rational r1;
Rational r2(1);
Rational r3(1, 3);
```

### Use operators to perform arithmetic operations
```cpp
Rational r3 = r1 + r2;
Rational r4 = r1 - r2;
Rational r5 = r1 * r2;
Rational r6 = r1 / r2;
```

### Compare Rational objects
```cpp
bool equals = (r1 == r2);
bool not_equals = (r1 != r2);
bool less_than = (r1 < r2);
bool greater_than = (r1 > r2);
bool less_than_or_equals = (r1 <= r2);
bool greater_than_or_equals = (r1 >= r2);
```

### Input/Output Rational objects
```cpp
std::cin >> r1;
std::cout << r1;
```


## Testing:
The project includes a set of tests to verify the correctness of the Rational class. These tests cover a range of scenarios, including basic arithmetic operations, edge cases, and comparison with other types.