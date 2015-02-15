#include <stdio.h>
#include <string.h>

void replace(char buffer[], char replacement, size_t size) {
    size_t count = 0;
    while (*buffer != '\0' && count++ < size) {
        *buffer = replacement;
        buffer++;
    }
}

typedef struct _employee {
    char name[10];
    int age;
} Employee;

typedef struct _item {
    int partNumber;
    int quantity;
    int binNumber;
} Item;

int main(int argc, char const* argv[])
{
    char firstName[8] = "1234567";
    char middleName[8] = "1234567";
    char lastName[8] = "1234567";

    middleName[-2] = 'X';
    middleName[0] = 'X';
    middleName[10] = 'X';

    printf("%p %s\n", firstName, firstName);
    printf("%p %s\n", middleName, middleName);
    printf("%p %s\n", lastName, lastName);


    // http://inaz2.hatenablog.com/entry/2014/03/14/151011
    // char name[8];
    // strcpy(name, "Alexander");
    // replace(name, '+', sizeof(name));
    // printf("%s\n", name);

    int buffer[20];
    int* pbuffer = buffer;
    int i;

    // for (i = 0; i < sizeof(buffer); i++) {
    for (i = 0; i < (sizeof(buffer)/sizeof(int)); i++) {
        printf("count: %i\n", i);
        *(pbuffer++) = 0;
    }

    int num = 2147483647;
    int* pi = &num;
    short* ps = (short *)pi;
    printf("pi: %p Value(16): %x Value(10): %d\n", pi, *pi, *pi);
    printf("ps: %p Value(16): %x Value(10): %d\n", ps, (unsigned short)*ps, (unsigned short)*ps);

    Employee employee;

    char* ptr = employee.name;
    printf("ptr %p\n", ptr);
    ptr += sizeof(employee.name);
    printf("ptr %p\n", ptr);

    Item part = { 12345, 35, 107 };
    int* pi1 = &part.partNumber;
    printf("Part number: %d\n", *pi1);
    pi1++;
    printf("Quantity: %d\n", *pi1);
    pi1++;
    printf("Bin number: %d\n", *pi1);

    int* pi2 = &part.partNumber;
    printf("Part number: %d\n", *pi2);
    pi2 = &part.quantity;
    printf("Quantity: %d\n", *pi2);
    pi2 = &part.binNumber;
    printf("Bin number: %d\n", *pi2);

    printf("Part number: %d\n", part.partNumber);
    printf("Quantity: %d\n", part.quantity);
    printf("Bin number: %d\n", part.binNumber);

    return 0;
}
