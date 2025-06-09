# Lab07A: Operator Overloading – C++ Lab Module

## Objective
In this lab, you will explore **operator overloading** in C++. You will overload the `+` operator for a custom class so that you can conveniently modify object values using intuitive syntax. Operator overloading improves code readability and provides functionality similar to built-in types.

---

## Key Concepts
- Operator overloading
- Class methods and constructors
- Encapsulation and accessors
- Writing concise and intuitive code

---

## Task

You are given a partially implemented `FamilyVacation` class that tracks the number of **days** and **people** involved in a vacation. Your task is to:

1. Overload the `+` operator so that it allows you to extend the vacation by a certain number of days using `vacation = vacation + days`.
2. Ensure that the number of people remains unchanged during this operation.
3. Create two vacation objects and demonstrate the operator's behavior by modifying the first vacation and assigning the result to a second vacation.

### Input Format

The program should read the number of **days** and **people** from standard input:
```
7
3
```

### Output Format

Your program should produce output as follows:
```
First vacation: Days: 7, People: 3
Second vacation: Days: 12, People: 3
```

---

## Provided Template

Below is the starting template for students. You must fill in the missing code to correctly overload the `+` operator.

```cpp
#include <iostream>
using namespace std;

class FamilyVacation {
   public:
      void  SetNumDays(int dayCount);
      void  SetNumPeople(int peopleCount);
      void  Print() const;

      // TODO: Overload + operator to add days to the vacation
      FamilyVacation operator+(int moreDays);

   private:
      int   numDays;
      int   numPeople;
};

void FamilyVacation::SetNumDays(int dayCount) {
   numDays = dayCount;
}

void FamilyVacation::SetNumPeople(int peopleCount) {
   numPeople = peopleCount;
}

// TODO: Define the overloaded + operator
// The returned vacation should have the new number of days
// but the same number of people

void FamilyVacation::Print() const {
   cout << "Days: " << numDays << ", People: " << numPeople << endl;
}

int main() {
   FamilyVacation firstVacation;
   FamilyVacation secondVacation;
   int userDays;
   int userPeople;

   cin >> userDays;
   cin >> userPeople;

   cout << "First vacation: ";
   firstVacation.SetNumDays(userDays);
   firstVacation.SetNumPeople(userPeople);
   firstVacation.Print();

   cout << "Second vacation: ";
   secondVacation = firstVacation + 5;
   secondVacation.Print();

   return 0;
}
```

---

## Expected Behavior

When the user inputs:
```
7
3
```

The output should be:
```
First vacation: Days: 7, People: 3
Second vacation: Days: 12, People: 3
```

---
## Submission Instructions
- Verify your program and output with your TA
```


