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
    int fd = open("employee",O_WRONLY | O_CREAT | O_TRUNC, 0600);

    if ((fd ==-1)) {
        perror("faile to open");
        exit(2);
    }


    struct Employee e_database[4] = {
        {1001, "Alice", "HR", 3500.50},
        {1002, "Bob", "Engineering", 5200.75},
        {1003, "Charlie", "Sales", 4100.00},
        {1004, "Trudy", "Marketing", 6100.00}
    };

    lseek(fd, 0L, SEEK_SET);
    write(fd, &e_database, 4 * sizeof(struct Employee));

    close(fd);
    printf("Employee data written successfully.\n");
    return 0;
}
