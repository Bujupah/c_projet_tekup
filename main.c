#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "database.c"
#include "employe.c"

void cliHeader();
void cliWelcome();
void cliMenuOptions();
void cliSpace(char, int);
void cliReadOption(int*);

void cliAddEmploye();
void cliDelEmploye();
void cliEditEmploye();
void cliGetAllEmploye();
void cliSearchEmployeById();
void cliSearchEmployeByName();
void cliSearchEmployeByAdr();
void cliSearchEmployeByDep();
void cliSearchEmployeByMale();
void cliSearchEmployeByFemale();
void cliQuit();

int main() {
  init_db();

  cliHeader();
  cliWelcome();
  cliHeader();

  int option;

  while(1) {
    cliHeader();
    cliMenuOptions();
    cliReadOption(&option);

    switch(option) {
      case 0: cliQuit();
        break;
      case 1: cliAddEmploye();
        break;
      case 2: cliDelEmploye();
        break;
      case 3: cliEditEmploye();
        break;
      case 4: cliGetAllEmploye();
        break;
      case 5: cliSearchEmployeById();
        break;
      case 6: cliSearchEmployeByName();
        break;
      case 7: cliSearchEmployeByDep();
        break;
      case 8: cliSearchEmployeByAdr();
        break;
      case 9: cliSearchEmployeByMale();
        break;
      case 10: cliSearchEmployeByFemale(); 
        break;
      default:
        printf("Option not implimented...");
    } 
  }
}

void cliHeader() {
  system("cls");
  printf("\t");
  cliSpace('=',65);
  printf("\n\t");
  cliSpace('=',18);
  printf("[C] [PROGRAMMING] [PROJECT]");
  cliSpace('=',18);
  printf("\n\t");
  cliSpace('=',65);
}

void cliWelcome() {
  printf("\n\n\n\n\n\t\t]--------------[ [ [ Bienvenu ] ] ]--------------[\n\n\n\n\n\n\n\t");
  system("pause");
}

void cliSpace(char ch,int n) {
    while(n--) putchar(ch);
}

void cliMenuOptions() {
  printf("\n\t\t\t\tMenu");
  printf("\n\n\n");
  printf("\n\n\t\t\t1.  Ajouter Employe");
  printf("\n\n\t\t\t2.  Supprimer Employe");
  printf("\n\n\t\t\t3.  Modifie Employe");
  printf("\n\n\t\t\t4.  Afficher la liste d\'employe");
  printf("\n\n\t\t\t5.  Recherche par ID");
  printf("\n\n\t\t\t6.  Recherche par Nom et Prenom");
  printf("\n\n\t\t\t7.  Recherche par Departement");
  printf("\n\n\t\t\t8.  Recherche par Adresse");
  printf("\n\n\t\t\t9.  Liste D\'Employees Male");
  printf("\n\n\t\t\t10. Liste D\'Employees Female");
  printf("\n\n\t\t\t0.  QUITE");
}

void cliReadOption(int *option) {
  printf("\n\n\t\tEntrer Votre Choix :--> ");
  scanf("%d", option);
}


void cliAddEmploye() {
  char addNew = 'y';
  struct Employe e;
  
  while (addNew == 'y' || addNew == 'Y') {

    printf("\n\n\t\tEntrer L\'ID de L\'Employe: ");
    scanf("%d",&e.id);

    printf("\n\n\t\tEntrer le Nom et le Prenom de L\'Employe: ");
    fflush(stdin);
    fgets(e.nom,100,stdin);
    e.nom[strlen(e.nom)-1]='\0';

    printf("\n\n\t\tEntrer le Poste de L\'Employe: ");
    fflush(stdin);
    fgets(e.poste,200,stdin);
    e.poste[strlen(e.poste)-1]='\0';

    printf("\n\n\t\ttEntrer la Sexe: ");
    fflush(stdin);
    fgets(e.sexe,10,stdin);
    e.sexe[strlen(e.sexe)-1]='\0';

    printf("\n\n\t\tEntrer le Departement de L\'Employe: ");
    fflush(stdin);
    fgets(e.departement,50,stdin);
    e.departement[strlen(e.departement)-1]='\0';

    printf("\n\n\t\tEntrer la Salaire de L\'Employe: ");
    scanf("%f",&e.sal);

    printf("\n\n\t\tEntrer l\'Adress de L\'Employe: ");
    fflush(stdin);
    fgets(e.addr,200,stdin);
    e.addr[strlen(e.addr)-1]='\0';

    printf("\n\n\t\tEntrer le Numuro de Telephon de L\'Employe: ");
    fflush(stdin);
    fgets(e.phone,50,stdin);
    e.phone[strlen(e.phone)-1]='\0';

    printf("\n\n\t\tEntrer L'E-mail de L\'Employe: ");
    fflush(stdin);
    fgets(e.mail,20,stdin);
    e.mail[strlen(e.mail)-1]='\0';

    STRING row = employeToCsvRow(&e);
    add_row(row);

    printf("\n\n\t\tVoulais-Vous Ajouter un Autre Employe? (Y/N)\t");
    fflush(stdin);

    addNew = getchar();
  }
}

void cliShowAllEmploye() {
  STRING* result;
  select_all(result);
}

void cliShowEmployeById(int id) {
  STRING buffer = malloc(sizeof(char)*BUFFER_SIZE);
  select_by_id(2, buffer);
  puts(buffer);
}

void cliDelEmploye() {}
void cliEditEmploye() {}
void cliGetAllEmploye() {
  STRING buffer[BUFFER_SIZE];
  select_all(buffer);
}
void cliSearchEmployeById() {
  STRING buffer = malloc(sizeof(char)*BUFFER_SIZE);
  select_by_id(4, buffer);
  cliSpace('\t', 3);
  puts(buffer);
  system("pause");
}
void cliSearchEmployeByName() {}
void cliSearchEmployeByAdr() {}
void cliSearchEmployeByDep() {}
void cliSearchEmployeByMale() {}
void cliSearchEmployeByFemale() {}
void cliQuit() {
  printf("Au revoir");
  exit(0);
}