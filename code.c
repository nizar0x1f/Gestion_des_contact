#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LGNOM 20
#define LGPRENOM 15
#define LGTEL 11
struct pERSONE
{
	char f_name[LGNOM];
	char l_name[LGPRENOM];
	char tel[LGTEL];
};
typedef struct pERSONE client;
void saisir()   // pour entrer les contact
{
	
	FILE *fp;
	client contact__;
	fp = fopen("contact1.txt","w+");
	while(1){
		printf("saisir votre nom:\n");
		gets(contact__.f_name);
		if(strlen(contact__.f_name)==0) break;
		printf("saisir votre prenom:\n");
		gets(contact__.l_name);	
		printf("saisir votre numero de tel:\n");
		gets(contact__.tel);
		fwrite(&contact__,sizeof(client),1,fp);
		}
	fclose(fp);
}
char rechercher()  // pour chercher dans le repertoire	
{
	FILE *fp;
	client contact__;
	char f_name[LGNOM];
	int i=0;
	fp = fopen("contact1.txt","r");
	printf("entrer le nom du contact: ");
	gets(f_name);
	do{
		fread(&contact__,sizeof(client),1,fp);
		if(strcmp(contact__.f_name,f_name)==0){
		printf("[nom]:%s [prenom]:%s [telephone]:%s",contact__.f_name,contact__.l_name,contact__.tel);
	    i=1; 
		break;}
	}
	while(!feof(fp));	
	if(i==0){
		puts("ce contact n'existe pas dans votre repertoire");
	}
	fclose(fp);
}
void modifier()    // pour modifier un contact existant
{
	FILE *fp;
	char nom2[LGNOM];
	int i=0; // 0 indique non trouve
	client contact__;
	
	fp=fopen("contact1.txt","a+");
	printf("Saisir le nom du contact que vous voulez modifier : ");
	gets(nom2);
	while(!feof(fp))
	{
	    fread(&contact__,sizeof(client),1,fp);
		if(strcmp(nom2,contact__.f_name)==0)
		  	{     
		  		while(1)
					{
						printf("Entrer le f_name : \n"); 
	    				gets(contact__.f_name);
	    				if(strlen(contact__.f_name)==0) break;
	    				printf("Entrer le l_name : \n");
	    				gets(contact__.l_name);
	    				printf("Entrer le numero de telephone : \n");
	    				gets(contact__.tel);
	    				fwrite(&contact__,sizeof(client),1,fp);
					}
				printf("le contact est modifer avec succes \n");
		  		i=1;
		  		break;
		  
    		}
	}
	if(i==0)
		  {
		  	printf("contact introuvable \n");
		  }
	fclose(fp);
}
void afficher()  // pour aficher les donné d'un contact
{
	FILE *fp;
	client contact__;
	int i;
	fp = fopen("contact1.txt","r");
    do{
    	fread(&contact__,sizeof(client),1,fp);
    	printf("[Nom]:%s [Prenom]:%s [Telephone]:%s\n",contact__.f_name,contact__.l_name,contact__.tel);
	}
	while(!feof(fp));
}
void exporter()  // pour exporter les contact en format csv
{
    FILE *fp1;
    FILE *fp2;
    client contact__;
	long size;
	long nbcontact;
	int i;
	fp1=fopen("contact1.txt","r");
	fp2=fopen("contact_export.csv","w");
	fseek(fp1,0,SEEK_END);
    size=ftell(fp1);
    nbcontact=size/sizeof(client);
    if(size>=0)
    	{
    		for(i=0;i<nbcontact;i++)
    			{
    				fseek(fp1,i*sizeof(client),SEEK_SET),    	
    	 			fscanf(fp1,"%s %s %s \n",&contact__.f_name,&contact__.l_name,&contact__.tel);
    				fprintf(fp2,"%s %s %s \n",contact__.f_name,contact__.l_name,contact__.tel);
				}
			printf("l'export est effectue avec succes \n");
		}
	else
	{
		printf("Il n'existe aucun contact__ pour l'exporter \n");
	}
	 fclose(fp1);
	 fclose(fp2);
}
void importer() // pour importer  les contact appartir d'un fichier csv
{
	FILE *fp1;
    FILE *fp2;
    client contact__;
	long size;
	long nbcontact;
	int i;	
	fp1=fopen("contact__.txt","w");
	fp2=fopen("contact2.csv","r");
	fseek(fp2,0,SEEK_END);
    size=ftell(fp2);
    nbcontact=size/sizeof(client);
    if(size>=0)
    	{
    		for(i=0;i<nbcontact;i++)
    			{
    				fseek(fp2,i*sizeof(client),SEEK_SET),    	
    	 			fscanf(fp2,"%s %s %s \n",&contact__.f_name,&contact__.l_name,&contact__.tel);
    				fprintf(fp1,"%s %s %s \n",contact__.f_name,contact__.l_name,contact__.tel);
				}
			printf("l'import est effectue avec succes \n");
		}
	else
	{
		printf("Il n'existe aucun contact__ pour l'importer \n");
	}
	 fclose(fp1);
	 fclose(fp2);
}
main(){
	int choix;
	do{
	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	printf("$$  Ajouter un contact__  ................. 1\n");
	printf("$$  Rechercher un contact__  .............. 2\n");
	printf("$$  Modifier un contact__  ................ 3\n");
	printf("$$  Afficher * les contacts  .............. 4\n");
	printf("$$  Exporter les contacts (vers .csv) ..... 5\n");
	printf("$$  Importer les contacts (de .csv)  ...... 6\n");
	printf("$$  Pour quitter le programme .......... ....\n");
	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	printf("$$ Donnez votre choix :");
	scanf("%d",&choix);
	getchar();
	}
	while(choix<0 || choix>6);
	switch (choix)
	{ 
		case 0 : return 0;
		         break;
		case 1 : saisir();
		         break;
		case 2 : rechercher();
				 break;
		case 3 : modifier();
				 break;
		case 4 : afficher();
				 break;
		case 5 : exporter();
		         break;
		case 6 : importer();
		         break;
	}
	return 0;
}
