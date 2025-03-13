#include <stdio.h>
#include <string.h>

typedef struct employee
{
    int em_id;
    char em_name[10];
    int em_age;
    char em_phone[12];
    float em_slary;
} employee_t;

void employee_info(employee_t employee_1)
{
    printf("%d\n", employee_1.em_id);
    printf("%s\n", employee_1.em_name);
    printf("%d\n", employee_1.em_age);
    printf("%s\n", employee_1.em_phone);
    printf("%f\n", employee_1.em_slary);
}

int emp_aveage_age(employee_t emp[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += emp[i].em_age;
    }
    return sum / n;
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
    while (fread(&emp[i], sizeof(employee_t), 1, fp))
    {
        printf("[%d] %d %s\n", i, emp[i].em_id, emp[i].em_name);
        ++i;
    }
    fclose(fp);
    return;
}
int main()
{
    employee_t emp[3];
    emp[0].em_id = 1;
    emp[0].em_age = 20;
    emp[0].em_slary = 30000.0;
    strcpy(emp[0].em_name, "IU");
    emp[1].em_id = 2;
    emp[1].em_age = 26;
    emp[1].em_slary = 36000.0;
    strcpy(emp[1].em_name, "taylor");
    emp[2].em_id = 3;
    emp[2].em_age = 31;
    emp[2].em_slary = 90000.0;
    strcpy(emp[2].em_name, "swift");
    emp_writefile(emp, 3);
    employee_t read_emp[10];
    emp_readfile(read_emp, sizeof(read_emp[0]) / sizeof(read_emp[0]));
    for (int i = 0; i < 3; i++)
    {
        employee_info(read_emp[i]);
    }
    int ret = emp_aveage_age(emp, 3);
    printf("%d\n", ret);
    return 0;
}