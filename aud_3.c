#include<stdio.h>
#include <string.h>

typedef struct Employee Employee;
typedef struct Company Company;

struct Employee{
    char ime[50];
    char embg[50];
    char section[50];
    int plata;
};
struct Company{
    char ime[50];
    Employee Employees[50];
    int broj_na_vraboteni;
};
void printEmployeesBelowAverageSalary(Company *comp, int br){
    int avg = 0;
    for (int j = 0; j < br; j++) {
        avg += comp->Employees[j].plata;
    }
    for (int j = 0; j < br; j++) {
        if(comp->Employees[j].plata < avg/br){
            printf("%s %s %s %d\n", comp->Employees[j].ime, comp->Employees[j].embg, comp->Employees[j].section, comp->Employees[j].plata);
        }
    }
}
void printHighestSalaryEmployee(Company *comp, int br, char *dep){
    int max_sal = 0;
    Employee max;
    for (int j = 0; j < comp->broj_na_vraboteni; j++) {
        if(strcmp(comp->Employees[j].section,dep)==0){
            if(comp->Employees[j].plata > max_sal){
                max_sal = comp->Employees[j].plata;
                max = comp->Employees[j];
            }
        }
    }
    printf("%s %s %s %d\n", max.ime, max.embg, max.section, max.plata);

}

int main(){
    int n;
    char sekcija[50];
    Company Companies[50];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s",Companies[i].ime);
        scanf("%d",&Companies[i].broj_na_vraboteni);
        for (int j = 0; j < Companies[i].broj_na_vraboteni; ++j) {
            scanf("%s %s %s %d", Companies[i].Employees[j].ime,Companies[i].Employees[j].embg,Companies[i].Employees[j].section,&Companies[i].Employees[j].plata );
        }
    }
    scanf("%s", sekcija);
    printf("Employees with salaries below the average:\n");
    for (int i = 0; i < n; i++) {
        printEmployeesBelowAverageSalary(&Companies[i], Companies[i].broj_na_vraboteni);
    }
    printf("Employees with highest salaries for given department:\n");
    for (int i = 0; i < n; i++) {
        printHighestSalaryEmployee(&Companies[i], Companies[i].broj_na_vraboteni,sekcija);
    }


}