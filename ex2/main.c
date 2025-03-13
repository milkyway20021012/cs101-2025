#include <stdio.h>
#include <string.h>

typedef struct employee
{
    int id;
    int age;
    float salary;
    char name[10];
} employee_t;

void emp_info(employee_t emp)
{
    printf("%d\n", emp.id);
    printf("%d\n", emp.age);
    printf("%f\n", emp.salary);
    printf("%s\n", emp.name);
}

int emp_aveage_age(employee_t emp[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += emp[i].age;
    }
    int ret = sum / n;
    return ret;
}

void emp_writefile(employee_t emp[], int n)
{
    FILE *fp = fopen("employee.bin", "wb+");
    for (int i = 0; i < n; ++i)
    {
        fwrite(&emp[i], sizeof(employee_t), 1, fp);
    }
    fclose(fp);
    return;
}

void emp_readfile(employee_t emp[], int n)
{
    FILE *fp = fopen("employee.bin", "rb");
    int i = 0;
    while (i < n && fread(&emp[i], sizeof(employee_t), 1, fp))
    {
        emp_info(emp[i]);
    }
    printf("\n");
    fclose(fp);
    return;
}

int main()
{
    employee_t emp[3];
    emp[0].id = 1;
    emp[0].age = 20;
    emp[0].salary = 30000.0;
    strcpy(emp[0].name, "IU");
    emp[1].id = 2;
    emp[1].age = 26;
    emp[1].salary = 36000.0;
    strcpy(emp[1].name, "taylor");
    emp[2].id = 3;
    emp[2].age = 31;
    emp[2].salary = 90000.0;
    strcpy(emp[2].name, "swift");
    emp_writefile(emp, 3);
    employee_t read_emp[3];
    emp_readfile(read_emp, 3);
    int ret = emp_aveage_age(emp, 3);
    
    printf("%d\n", ret);
    return 0;
}