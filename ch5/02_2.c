#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

struct Employee {
    int emp_id;
    char name[20];
    char department[20];
    double salary;
};

int main(void) {
    int fd = open("employee",O_RDONLY);
    if (fd == -1) {
        perror("Fail to open employee file");
        exit(1);
    }

    struct Employee emp;
    printf("=== Employee Records ===\n");


    while (read(fd, &emp, sizeof(struct Employee)) > 0) {
        printf("ID: %4d | Name: %-8s | Department: %-11s | Salary: %.2lf USD\n",
               emp.emp_id, emp.name, emp.department, emp.salary);
    }

    close(fd);
    return 0;
}
