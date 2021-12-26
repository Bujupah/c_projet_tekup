#define EMP struct Employe
#define STRING char*
#define BUFFER_SIZE 500

struct Employe
{
    int id;
    char nom[100];
    char poste[10];
    float sal;
    char sexe[10];
    char departement[50];
    char addr[200];
    char phone[15];
    char mail[20];
    char created_at[12];
};

STRING employeToCsvRow(EMP *emp) {
    STRING date = malloc(sizeof(char) * 100);
    current_date(date);

    STRING row = malloc(sizeof(char) * BUFFER_SIZE);
    sprintf(row, "\n%d,%s,%s,%f,%s,%s,%s,%s,%s,%s", 
    (*emp).id, 
    (*emp).nom, 
    (*emp).poste, 
    (*emp).sal, 
    date,
    (*emp).sexe, 
    (*emp).departement, 
    (*emp).addr, 
    (*emp).phone, 
    (*emp).mail);
    return row;
}

void showEmploye(STRING* columns) {
    printf("\n\t\t\t ID: %s\n", columns[0]);
    printf("\t\t\t Nom et prenom: %s\n", columns[1]);
    printf("\t\t\t Poste: %s\n", columns[2]);
    printf("\t\t\t Salaire: %s\n", columns[3]);
    printf("\t\t\t Sexe: %s\n", columns[5]);
    printf("\t\t\t Departement: %s\n", columns[6]);
    printf("\t\t\t Adresse: %s\n", columns[7]);
    printf("\t\t\t Telephone: %s\n", columns[8]);
    printf("\t\t\t Email adresse: %s\n", columns[9]);
    printf("\t\t\t Date de creation: %s\n", columns[4]);
}
