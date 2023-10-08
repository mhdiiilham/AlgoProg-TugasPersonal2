#include <stdio.h>

enum FieldOfStudy {
    COMPUTER_SCIENCE,
    MATHEMATICS,
    PHYSICS,
    OTHERS
};

struct Student {
    char name[128];
    int age;
    enum FieldOfStudy fieldOfStudy;
};

int main() {
    struct Student student1;
    student1.age = 21;

    return 0;
}