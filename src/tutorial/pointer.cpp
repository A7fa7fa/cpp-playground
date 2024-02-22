#include "tutorial.h"

void tutorial::pointer() {

    // this is a not a valid memory adress -> this is a nullptr.
    // all this are the same
    void* ptr1 = 0;
    void* ptr2 = NULL;
    void* ptr3 = nullptr;


    // declare a variable
    int var = 8;
    // get a memory adress from var with &
    // it is a int pointer because it is pointing to a memory adress that is holding an int
    // but types do not matter. it is useful for the manipulation of that memory and the compiler knows what should in that adress
    // but it is just an 32/64bit int that points to a memory
    int* varPtr = &var;
    log(*varPtr);
    double* varPtrDouble = (double*)&var;

    // dereferencing to get the value from pointer allows manipulation of value that is stored there
    *varPtr = 10;

    log(*varPtr);

    // this allocates 8 bytes of memory on the heap
    // buffer is a pointer to the beginning of the block of memory
    char* buffer = new char[8];
    memset(buffer, 0, 8);
    memset(buffer, '-', 8);
    // this just points to the first memory adress. so just the first value is printed
    log(*buffer);
    // sets the 6 element to 0
    memset(buffer+(5*sizeof(char)), 0, 1);
    log(*buffer);

    // this creates a pointer that points to a memroy that holds the pointer of buffer -> a pointer to a pointer that holds some value
    char** pointer = &buffer;

    delete[] buffer;



    char str[] = "almost every programmer should know memset!";
    memset(str,'-',6);
    log(str);



}