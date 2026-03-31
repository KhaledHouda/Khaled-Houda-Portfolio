//Author:Khaled Houda
// Date: 29.03.26.
//purpose: option2
//This program creates structs containing employee infos, specifically randomly generated salaries, departments, and social security numbers.


#include <time.h>
#include <stdlib.h>
#include <stdio.h>
double randGen(){ //i used this to generate between 0 and 100%
    return ((rand()%11)/10.0);
}

enum Department{HR, SALES, RESEARCH, SOFTWARE, EXECUTIVE};
char* getDepartmentName(enum Department department){
    switch(department){ //gets department name as string for printing later
        case HR:
            return "HR";
        case SALES:
            return "SALES";
        case RESEARCH:
            return "RESEARCH";
        case SOFTWARE:
            return "SOFTWARE";
        case EXECUTIVE:
            return "EXECUTIVE";
        default: return "HR";
    }


}
int HRSalaryGen(){
    int base = 20000;
    int offset = (int)(base*randGen());
    return (base+offset);
}
int salesSalaryGen(){
    int base = 30000;
    int offset = (int)(base*randGen());
    return (base+offset);
}
int researchSalaryGen(){
    int base = 40000;
    int offset = (int)(base*randGen());
    return (base+offset);
}
int softwareSalaryGen(){
    int base = 50000;
    int offset = (int)(base*randGen());
    return (base+offset);
}
int executiveSalaryGen(){
    int base = 100000;
    int offset = (int)(base*randGen());
    return (base+offset);
}

typedef struct{
     enum Department department;
     int annualSalary;
     unsigned int socialSecurityNumber;
}EmployeeProfile;

void chooseAndGenerateSalary(EmployeeProfile  *employee){ //checks department of employee and sets their salary
    switch(employee->department){
        case HR:
            employee->annualSalary = HRSalaryGen();
            break;
        case SALES:
            employee->annualSalary = salesSalaryGen();
            break;
        case RESEARCH:
            employee->annualSalary = researchSalaryGen();
            break;
        case SOFTWARE:
            employee->annualSalary = softwareSalaryGen();
            break;
        case EXECUTIVE:
            employee->annualSalary = executiveSalaryGen();
            break;
    }
}
unsigned int socialSecGenerator(int i){ //creates a 9 digit random SSN based on the Base-Offset-Jitter method with (practically) guaranteed through unique i for each employee
    return (100000000+(i*100000)+(rand()%100000));
}

int main(){
    srand(time(NULL)); //to change the seed of rand() for each run for some sort of randomness
    EmployeeProfile employeeList[10];
    for(int i = 0; i<10; i++){
        employeeList[i].socialSecurityNumber = socialSecGenerator(i);
        employeeList[i].department = (rand()%5);//modulo 5 because we want between 0 and 4 which are the numbers of each department
        chooseAndGenerateSalary(&employeeList[i]);
        unsigned int social = employeeList[i].socialSecurityNumber;
        int department = employeeList[i].department;
        int salary = employeeList[i].annualSalary;
        // Output formatting: Clean, one-line, human-readable strings
        printf("Employee %d infos: SSN: %u|department: %s|salary: %d\n",i,social, getDepartmentName(department),salary);

    }




}