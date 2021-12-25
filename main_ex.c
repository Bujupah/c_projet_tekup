#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "database.c"

#define Employe struct emp

void ajoute(FILE * fp);
FILE * supp(FILE * fp);
void modife(FILE * fp);
void afficher(FILE * fp);
void recherche(FILE *fp);
void recherchenom(FILE *fp);
void recherchedep(FILE *fp);
void rechercheaddr(FILE *fp);

void impChar(char ch,int n);
void entete();


struct emp
{
    int id;
    char nom[100];
    char poste[10];
    float sal;
    char jdate[8];
    char sexe[10];
    char departement[50];
    char addr[200];
    char phone[15];
    char mail[20];
};


int main()
{
    FILE * fp;
    Employe e;
    int option;
    char autre;

    if((fp=fopen("basedonnes.txt","r"))==NULL)
    {
        if((fp=fopen("basedonnes.txt","w"))==NULL)
        {
            printf("Erreur d'ouvrir la base de donn�es!");
            return 0;
        }
    }
    entete();
    bienvenu();
    entete();

    while(1)
    {
        entete();
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

        printf("\n\n\t\tEntrer Votre Choix :--> ");
        scanf("%d",&option);

        switch(option)
        {
        case 0:
            return 1;
            break;
        case 1:
            ajoute(fp);
            break;
        case 2:
            fp=supp(fp);
            break;
        case 3:
            modife(fp);
            break;
        case 4:
            afficher(fp);
            break;
        case 5:
            recherche(fp);
            break;
        case 6:
            recherchenom(fp);
            break;
        case 7:
            recherchedept(fp);
            break;
        case 8:
            rechercheaddr(fp);
            break;
        case 9:
            maleemp(fp);
            break;
        case 10:
            femaleemp(fp);
            break;
        default:
            break;

        }
    }
}

void bienvenu()
{
    printf("\n\n\n\n\n\t\t--------------[ [ [ Bienvenu ] ] ]--------------[\n\n\n\n\n\n\n\t");
    system("pause");
}

void impChar(char ch,int n)
{
    while(n--)
    {
        putchar(ch);
    }
}


void entete()
{
    system("cls");
    printf("\t");
    impChar('=',65);
    printf("\n\t");
    impChar('=',16);
    printf("[PROJET] [PROGRAMMATION] [C]");
    impChar('=',16);
    printf("\n\t");
    impChar('=',65);

}



void ajoute(FILE * fp)
{
    entete();

    printf("\n\t\t\t\Ajouter un Employe");
    char autre='y';
    Employe e;

    fseek(fp,0,SEEK_END);
    while(autre=='y'||autre=='Y')
    {
        printf("\n\n\t\tEntrer L\'ID de L\'Employe: ");
        scanf("%d",&e.id);

        printf("\n\n\t\tEntrer le Nom et le Prenom de L\'Employe: ");
        fflush(stdin);
        fgets(e.nom,100,stdin);
        e.nom[strlen(e.nom)-1]='\0';

        printf("\n\n\t\tEntrer le Poste de L\'Employe: ");
        fflush(stdin);
        fgets(e.poste,10,stdin);
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

        fwrite(&e,sizeof(e),1,fp);

        printf("\n\n\t\tVoulais-Vous Ajouter un Autre Employe? (Y/N)\t");
        fflush(stdin);
        autre=getchar();
    }
}


FILE * supp(FILE * fp)
{
    entete();
    printf("\n\t\t\t\Suppression");
    Employe e;
    int flag=0,tempid,siz=sizeof(e);
    FILE *ft;

    if((ft=fopen("temp.txt","wb+"))==NULL)
    {
        printf("\n\n\t\t\t\\t!!! Erreur !!!\n\t\t");
        system("pause");
        return fp;
    }

    printf("\n\n\tEntrer l\'Id de l\'emloyee ");
    printf("\n\n\t\t\tID No. : ");
    scanf("%d",&tempid);

    rewind(fp);


    while((fread(&e,siz,1,fp))==1)
    {
        if(e.id==tempid)
        {
            flag=1;
            printf("\n\tL\'Employe avec l'ID %d , Nom: %s de %s a ete supprime!",e.id, e.nom,e.departement);
            continue;
        }

        fwrite(&e,siz,1,ft);
    }


    fclose(fp);
    fclose(ft);

    remove("basedonnes.txt");
    rename("temp.txt","basedonnes.txt");

    if((fp=fopen("basedonnes.txt","r"))==NULL)
    {
        printf("erreur");
        return  NULL;
    }

    if(flag==0) printf("\n\n\t\t!!!! Employe introuvable! \n\t");

    impChar('-',65);
    printf("\n\t");
    system("pause");
    return fp;
}



void modife(FILE * fp)
{
    entete();
    printf("\n\t\t\t\Modifier Employe");
    Employe e;
    int i,flag=0,tempid,siz=sizeof(e);
    float sal;

    printf("\n\n\tEntre Id  d\'Employe � modifier ");
    scanf("%d",&tempid);

    rewind(fp);

    while((fread(&e,siz,1,fp))==1)
    {
        if(e.id==tempid)
        {
            flag=1;
            break;
        }
    }

    if(flag==1)
    {
        fseek(fp,-siz,SEEK_CUR);
        printf("\n\n\t\tIntrouvable!");
        printf("\n\n\t\tEntere les donne�s de l\'Employe");

        printf("\n\n\t\tEntrer L\'ID de L\'Employe: ");
        scanf("%d",&e.id);

        printf("\n\n\t\tEntrer le nom et le prenom: ");
        fflush(stdin);
        fgets(e.nom,100,stdin);
        e.nom[strlen(e.nom)-1]='\0';

        printf("\n\n\t\tEntrer le Poste de L\'Employe: ");
        fflush(stdin);
        fgets(e.poste,10,stdin);
        e.poste[strlen(e.poste)-1]='\0';

        printf("\n\n\t\tEntrer le sex: ");
        fflush(stdin);
        fgets(e.sexe,10,stdin);
        e.sexe[strlen(e.sexe)-1]='\0';

        printf("\n\n\t\tEntrer Departement: ");
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

        fwrite(&e,sizeof(e),1,fp);
    }
    else printf("\n\n\t\t!!!! Employe Introuvable! !!!!");
    printf("\n\n\t");
    system("pause");

}

void afficher(FILE * fp)
{
    entete();
    printf("\n\t\t\tList  of Employes");
    Employe e;
    int i,siz=sizeof(e);

    rewind(fp);

    while((fread(&e,siz,1,fp))==1)
    {
        printf("\n\n\t\tID : %d",e.id);
        printf("\n\n\t\tNom : %s",e.nom);
        printf("\n\n\t\tPoste : %s",e.poste);
        printf("\n\n\t\tSexe : %s",e.sexe);
        printf("\n\n\t\tDepartement : %s",e.departement);
        printf("\n\n\t\tSalaire : %.2f",e.sal);
        printf("\n\n\t\tPRESENT ADDRESS : %s",e.addr);
        printf("\n\n\t\tNumuro de Telephon : %s",e.phone);
        printf("\n\n\t\tE-MAIL : %s\n\n\t",e.mail);
        impChar('=',65);
    }
    printf("\n\n\n\t");
    printf("\n\n\t");
    system("pause");
}


void recherche(FILE *fp)
{
    entete();
    printf("\n\t\t\t\Recherche");
    int tempid,flag,siz,i;
    Employe e;
    char autre='y';
    siz=sizeof(e);

    while(autre=='y'||autre=='Y')
    {
        printf("\n\n\tSaisir l\'ID de l\'Employe : ");
        scanf("%d",&tempid);
        rewind(fp);
        while((fread(&e,siz,1,fp))==1)
        {
            if(e.id==tempid)
            {
                flag=1;
                break;
            }
        }

        if(flag==1)
        {
            printf("\n\n\t\tID : %d",e.id);
            printf("\n\n\t\tNom : %s",e.nom);
            printf("\n\n\t\tPoste : %s",e.poste);
            printf("\n\n\t\tSexe : %s",e.sexe);
            printf("\n\n\t\tDepartement : %s",e.departement);
            printf("\n\n\t\tSalaire : %.2f",e.sal);
            printf("\n\n\t\tPRESENT ADDRESS : %s",e.addr);
            printf("\n\n\t\tNumuro de Telephon : %s",e.phone);
            printf("\n\n\t\tE-MAIL : %s\n\n\t",e.mail);
            impChar('=',65);
        }
        else printf("\n\n\t\t!!!! Employe Introuvable! !!!!");
        printf("\n\n\t\t Voulez vous essayer avec un autre ID? (Y/N)");
        fflush(stdin);
        autre=getchar();
    }
}

void recherchenom(FILE *fp)
{
    entete();
    printf("\n\t\t\t\Recherche Par le Nom");
    int flag,siz,i;
    Employe e;
    char autre='y';
    char nom[100];
    siz=sizeof(e);

    while(autre=='y'||autre=='Y')
    {
        printf("\n\n\tSaisir le nom de l\'Employe : ");
        fflush(stdin);
        fgets(nom,100,stdin);
        nom[strlen(nom)-1]='\0';
        rewind(fp);
        while((fread(&e,siz,1,fp))==1)
        {
            if(strcmp(e.nom,nom)==0)
            {
                flag=1;
                break;
            }
        }

        if(flag==1)
        {
            printf("\n\n\t\tID : %d",e.id);
            printf("\n\n\t\tNom : %s",e.nom);
            printf("\n\n\t\tPoste : %s",e.poste);
            printf("\n\n\t\tSexe : %s",e.sexe);
            printf("\n\n\t\tDepartement : %s",e.departement);
            printf("\n\n\t\tSalaire : %.2f",e.sal);
            printf("\n\n\t\tPRESENT ADDRESS : %s",e.addr);
            printf("\n\n\t\tNumuro de Telephon : %s",e.phone);
            printf("\n\n\t\tE-MAIL : %s\n\n\t",e.mail);
            impChar('=',65);
        }
        else printf("\n\n\t\t!!!! L\'Employe %s Introuvable! !!!!", nom);
        printf("\n\n\t\t Voulez vous essayer avec un autre ID? (Y/N)");
        fflush(stdin);
        autre=getchar();
    }
}


void recherchedept(FILE *fp)
{
    entete();
    printf("\n\t\t\t\Recherche Par la Departement");
    int flag,siz,i;
    Employe e;
    char autre='y';
    char dep[100];
    siz=sizeof(e);

    while(autre=='y'||autre=='Y')
    {
        printf("\n\n\tSaisir la Departement de l\'Employe : ");
        fflush(stdin);
        fgets(dep,100,stdin);
        dep[strlen(dep)-1]='\0';
        rewind(fp);

        while((fread(&e,siz,1,fp))==1)
        {
            if(strcmp(e.departement,dep)==0)

            {
                flag=1;
                break;
            }
        }

        if(flag==1)
        {
            printf("\n\n\t\tID : %d",e.id);
            printf("\n\n\t\tNom : %s",e.nom);
            printf("\n\n\t\tPoste : %s",e.poste);
            printf("\n\n\t\tSexe : %s",e.sexe);
            printf("\n\n\t\tDepartement : %s",e.departement);
            printf("\n\n\t\tSalaire : %.2f",e.sal);
            printf("\n\n\t\tPRESENT ADDRESS : %s",e.addr);
            printf("\n\n\t\tNumuro de Telephon : %s",e.phone);
            printf("\n\n\t\tE-MAIL : %s\n\n\t",e.mail);
            impChar('=',65);
        }
        else printf("\n\n\t\t!!!! L\'Employees de la Departement %s Introuvable! !!!!", dep);
        printf("\n\n\t\t Voulez vous essayer avec un autre ID? (Y/N)");
        fflush(stdin);
        autre=getchar();
    }
}

void rechercheaddr(FILE * fp)
{
    entete();
    printf("\n\t\t\t\Recherche par Adresse");
    Employe e;
    int i,siz=sizeof(e);
    char adr[100];
    printf("\n\n\tSaisir l\'adresse de l\'Employe : ");
    fflush(stdin);
    fgets(adr,100,stdin);
    adr[strlen(adr)-1]='\0';
    rewind(fp);
    while((fread(&e,siz,1,fp))==1)
    {
        if(strcmp(e.addr,adr)==0)

        {
            printf("\n\n\t\tID : %d",e.id);
            printf("\n\n\t\tNom : %s",e.nom);
            printf("\n\n\t\tDepartement : %s",e.poste);
            printf("\n\n\t\tPHONE : %s",e.phone);
            printf("\n\n\t\tE-MAIL : %s\n\t",e.mail);
            impChar('=',65);
        }
    }
    printf("\n\n\n\t");
    printf("\n\n\t");
    system("pause");
}

void maleemp(FILE * fp)
{
    entete();
    printf("\n\t\t\t\Liste des Employee Male");
    Employe e;
    int i,siz=sizeof(e);

    rewind(fp);

    while((fread(&e,siz,1,fp))==1)
    {
        if((strcmp(e.sexe,"M")==0)||(strcmp(e.sexe,"m")==0))
        {

            printf("\n\n\t\tID : %d",e.id);
            printf("\n\n\t\tNom : %s",e.nom);
            printf("\n\n\t\tDepartement : %s",e.poste);
            printf("\n\n\t\tPHONE : %s",e.phone);
            impChar('-',65);
        }
    }
    printf("\n\n\n\t");
    impChar('*',65);
    printf("\n\n\t");
    system("pause");
}

void femaleemp(FILE * fp)
{
    entete();
    printf("\n\t\t\t\Liste des Employee Female");
    Employe e;
    int i,siz=sizeof(e);

    rewind(fp);

    while((fread(&e,siz,1,fp))==1)
    {
        if((strcmp(e.sexe,"F")==0)||(strcmp(e.sexe,"f")==0))
        {
            printf("\n\n\t\tID : %d",e.id);
            printf("\n\n\t\tNom : %s",e.nom);
            printf("\n\n\t\tDepartement : %s",e.poste);
            printf("\n\n\t\tPHONE : %s",e.phone);
            impChar('-',65);
        }
    }
    printf("\n\n\n\t");
    impChar('*',65);
    printf("\n\n\t");
    system("pause");
}
