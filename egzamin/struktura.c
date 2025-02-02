#include <stdio.h>
#include <string.h>

// Deklaracja struktury
struct Student {
    char name[50];
    int age;
};

// Zastosowanie typedef
typedef struct {
    char name[50];
    float salary;
} Employee;

int main() {
    struct Student student1 = {"Jan Kowalski", 21};
    Employee emp1;
    strcpy(emp1.name, "Adam Nowak");
    emp1.salary = 5000.0;

    printf("Student: %s, Wiek: %d\n", student1.name, student1.age);
    printf("Pracownik: %s, Wynagrodzenie: %.2f\n", emp1.name, emp1.salary);

    return 0;
}
