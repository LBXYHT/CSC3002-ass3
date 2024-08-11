/*
 * File: intarray.cpp
 * ------------------
 * This file inplements the intarray.h interface.
 */

#include "error.h"
#include "intarray.h"
#include "strlib.h"
using namespace std;

/*
 * Implementation notes: IntArray constructor and destructor
 * ---------------------------------------------------------
 * The constructor allocates an array to hold the values and initializes
 * each element to 0;
 */

IntArray::IntArray(int n) {
   array = new int[n];
   nElements = n;
   for (int i = 0; i < n; i++) {
       array[i] = 0;
   }

   // TODO: initialize each element to 0

}

IntArray::~IntArray() {
    delete array;
    // TODO: free the array

}

/*
 * Implementation notes: size, get, and put
 * ----------------------------------------
 * Given the data structure, each of these methods is straightforward.
 */

int IntArray::size() {
    int size = sizeof(*array) + 1/*/sizeof(array[0])*/;
    return size;
    // TODO: a function returns the number of elements in the IntArray.

}

int IntArray::get(int index) {
    int size = IntArray::size();
    if (index < 0 || index >= size) {
        cout << "Please enter correct index number! ";
        return 0;
    }

    return array[index];
//    TODO: a function returns the element at position index. If index is outside the vector bounds,
//    get should call error with an appropriate message.


}

void IntArray::put(int index, int value) {
    int size = IntArray::size();
    if (index < 0 || index >= size) {
        cout << "Please enter correct index number! ";
    } else {
        array[index] = value;
    }
//    TODO: a function that assigns value to the element at position index. As with get, the
//    put method should call error if index is out of bounds.

}

/*
 * Implementation notes: operator []
 * ---------------------------------
 * The selction operator is identical to get except for the fact that it
 * returns its result by reference.
 */

int & IntArray::operator[](int index) {
    int size = IntArray::size();
    if (index < 0 || index >= size) {
        cout << "Please enter correct index number! ";
        error("Index number is invalid.");
    } else {
        return array[index];
        cout << "Please assign a value: ";
        int PutValue;
        cin >> PutValue;
        IntArray::put(index, PutValue);
    }

    //TODO
}

/*
 * Implementation notes: copy constructor and assignment operator
 * --------------------------------------------------------------
 * These methods make it possible to pass a IntArray by value or
 * assign one IntArray to another.
 */

IntArray::IntArray(const IntArray & src) {
    int *oldArray = array;
    array = new int[sizeof(src)];
    for (int i = 0; i < sizeof(src); i++) {
        array[i] = oldArray[i];

    }
    delete[] oldArray;
    //TODO

}

IntArray & IntArray::operator=(const IntArray & src) {
    array = new int[src.nElements];
    for (int i = 0; i < src.nElements; i++) {
        array[i] = src.array[i];
    }
    nElements = src.nElements;
    //TODO
    return *this;
}


/* Test program */

/*
 * Function: test
 * Usage: test(str, value, expected);
 * ----------------------------------
 * Generates a line of test output, making sure that the value of value
 * is equal to the expected parameter.
 */

void test(string str, int value, int expected) {
   cout << str << " -> " << value;
   if (value != expected) cout << " (should be " << expected << ")";
   cout << endl;
}

int P2a_test() {
   IntArray array(5);
   test("array.size()", array.size(), 5);
   for (int i = 0; i < 5; i++) {
      test("array.get(" + integerToString(i) + ")", array.get(i), 0);
      cout << "array.put(" << i << ", " << i << ");" << endl;
      array.put(i, i);
      test("array.get(" + integerToString(i) + ")", array.get(i), i);
   }
   return 0;
}

int P2b_test() {
   IntArray array(5);
   test("array.size()", array.size(), 5);
   for (int i = 0; i < 5; i++) {
      test("array[" + integerToString(i) + "]", array[i], 0);
      cout << "array[" << i << "] = " << i << ";" << endl;
      array[i] = i;
      test("array[" + integerToString(i) + "]", array[i], i);
   }
   return 0;
}

int P2c_test() {
   IntArray v1(5);
   test("v1.size()", v1.size(), 5);
   for (int i = 0; i < 5; i++) {
      test("v1[" + integerToString(i) + "]", v1[i], 0);
      cout << "v1[" << i << "] = " << i << ";" << endl;
      v1[i] = i;
      test("v1[" + integerToString(i) + "]", v1[i], i);
   }
   IntArray v2;
   v2 = v1;
   test("v2.size()", v2.size(), 5);
   for (int i = 0; i < 5; i++) {
      test("v2[" + integerToString(i) + "]", v2[i], i);
   }
   return 0;
}

