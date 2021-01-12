#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

struct Elections{
	char nom[20];
	int  nbrVote ;
};
struct Electeurs{
	char cin[10];
};
void  premierVote(struct Electeurs Electeurs[],struct Elections test[],int a,int b ){
	  int min,max;
	  bool flag=false;
	  double voteCritique;
	  struct Elections presidentT1[a];
	  int vote,i,j,compt,comptT3,comptT2,equalsVote,x;
	  do{
	  	i=0;	  
       compt=0;
	  
	do{
				
			    printf("\nElecteurs Num Cin %s choisir un président : ", Electeurs[i].cin);
			    scanf("%d",&vote);
			    if(vote>0 && vote<=a){
			    	test[vote-1].nbrVote++;
			    	i++;
				}else{
					printf("(repeter votre vote) ");
				}
			    }while(i<b);
			    
			    voteCritique=b*0.15;
			    for(j=0;j<a;j++){
			    	if(test[j].nbrVote>=voteCritique){
			         presidentT1[compt]=test[j];
			         compt++;
			         
					}
				}
				printf("\n---------------Liste des  présidents nominés Tour 1 -------------------------");
				
				for(j=0;j<compt;j++){
			    	printf("\n|-- %d. %s le nombre de vote : %d -----------------",j+1,presidentT1[j].nom,presidentT1[j].nbrVote);
			    	
			    	 if(presidentT1[j].nbrVote==b){
			    		printf("\n\n\n");
			    		printf("\n---------------------le président officiel reussi --------------------");
			    		printf("\n\n\n");
			    		printf("\n|-- %d. Monsieur le president  %s le nombre de vote : %d   (felicitation) -----------------",j+1,presidentT1[j].nom,presidentT1[j].nbrVote);
			    		exit(0);
					}
					
				}
				equalsVote=presidentT1[0].nbrVote;
				for(x=1;x<a;x++){
					if(equalsVote!=test[x].nbrVote){
						flag=true;
						break;
					}
				
				}
				for(i=0;i<compt;i++){
					
					presidentT1[i].nbrVote=0;
				}
				//------reinitialiser un tableau
				for(i=0;i<a;i++){
				test[j].nbrVote=0;
			}
				}while(!flag);
				
				
				
				
				
				//----------Deuxième tour : 
				
				
				
				
				struct Elections presidentT2[compt];
				flag=false;
				do{
				
				i=0;comptT2=0;
				printf("\n Deuxième tour : ");
				do{
					printf("\nElecteurs Num Cin %s choisir un président : ", Electeurs[i].cin);
			    scanf("%d",&vote);
			    if(vote>0 && vote<=compt){
			    	presidentT1[vote-1].nbrVote++;
			    	i++;
				}else{
					printf("(repeter votre vote) ");
				}
			    }while(i<b);
			    min=presidentT1[0].nbrVote;
			    //-----------Min de Tour 2
			    for(i=1;i<compt;i++){
			    	if(presidentT1[i].nbrVote<min){
			    		 min=presidentT1[i].nbrVote;
					}
				}
				
					equalsVote=presidentT1[0].nbrVote;
				for(x=1;x<compt;x++){
					if(equalsVote!=presidentT1[x].nbrVote){
						flag=true;
						break;
					}
				
				}
				//------remplir deuxieme tab de Tour 2
				for(i=0;i<compt;i++){
					 if(presidentT1[i].nbrVote>min){
					
						presidentT2[comptT2]=presidentT1[i];
						comptT2++;
					}
				}
				printf("\n---------------Liste des  présidents nominés Tour 2 -------------------------");
				if(flag==false){
					comptT2=compt;
					for(i=0;i<compt;i++){
						presidentT2[i]=presidentT1[i];
					}
					}
				for(j=0;j<comptT2;j++){
			    	printf("\n|-- %d. %s le nombre de vote : %d -----------------",j+1,presidentT2[j].nom,presidentT2[j].nbrVote);
			    	
			    	 if(presidentT2[j].nbrVote==b){
			    		printf("\n\n\n");
			    		printf("\n---------------------le président officiel reussi --------------------");
			    		printf("\n\n\n");
			    		printf("\n|-- %d. Monsieur le president  %s le nombre de vote : %d   (felicitation) -----------------",j+1,presidentT2[j].nom,presidentT2[j].nbrVote);
			    		exit(0);
					}
					
				}
			
				for(i=0;i<comptT2;i++){
					
					presidentT2[i].nbrVote=0;
				}
				//------reinitialiser un tableau
				for(i=0;i<compt;i++){
				presidentT1[i].nbrVote=0;
			}
				}while(!flag);
				
				
				
				//----------Troisième tour : : 
				
				
				
				
				struct Elections presidentT3[comptT2];
				flag=false;
				do{
				
				i=0;comptT3=0;
				printf("\n Troisième tour : ");
				do{
					printf("\nElecteurs Num Cin %s choisir un président : ", Electeurs[i].cin);
			    scanf("%d",&vote);
			    if(vote>0 && vote<=comptT2){
			    	presidentT2[vote-1].nbrVote++;
			    	i++;
				}else{
					printf("(repeter votre vote) ");
				}
			    }while(i<b);
			    max=presidentT2[0].nbrVote;
			    //-----------Max de Tour 3
			    for(i=1;i<comptT2;i++){
			    	if(presidentT2[i].nbrVote>max){
			    		 max=presidentT2[i].nbrVote;
					}
				}
				
					equalsVote=presidentT2[0].nbrVote;
				for(x=1;x<comptT2;x++){
					if(equalsVote!=presidentT2[x].nbrVote){
						flag=true;
						break;
					}
				
				}
				//------remplir deuxieme tab de Tour 3
				for(i=0;i<comptT2;i++){
					 if(presidentT2[i].nbrVote==max){
					
						presidentT3[comptT3]=presidentT2[i];
						comptT3++;
					}
				}
				
				if(flag==false){
					comptT3=comptT2;
					for(i=0;i<comptT2;i++){
						presidentT3[i]=presidentT2[i];
					}
					}
					if(comptT3>1){
							printf("\n---------------Liste des  présidents nominés Tour 3 -------------------------");
							comptT3=comptT2;
					}
				for(j=0;j<comptT3;j++){
					if(comptT3==1){
						printf("\n\n\n");
			    		printf("\n---------------------le président officiel reussi --------------------");
			    		printf("\n\n\n");
			    		printf("\n|-- %d. Monsieur le president  %s le nombre de vote : %d   (felicitation) -----------------",j+1,presidentT3[j].nom,presidentT3[j].nbrVote);
			    		exit(0);
					}else{
				
			    	printf("\n|-- %d. %s le nombre de vote : %d -----------------",j+1,presidentT3[j].nom,presidentT3[j].nbrVote);
			    	}
			    	 if(presidentT2[j].nbrVote==b){
			    		printf("\n\n\n");
			    		printf("\n---------------------le président officiel reussi --------------------");
			    		printf("\n\n\n");
			    		printf("\n|-- %d. Monsieur le president  %s le nombre de vote : %d   (felicitation) -----------------",j+1,presidentT3[j].nom,presidentT3[j].nbrVote);
			    		exit(0);
					}
					
				}
			
				for(i=0;i<comptT3;i++){
					
					presidentT3[i].nbrVote=0;
				}
				//------reinitialiser un tableau
				for(i=0;i<comptT2;i++){
				presidentT2[i].nbrVote=0;
			}
				}while(!flag || comptT3>1);
				
}

void afficherElections(struct Elections test[],int n){
	int j;
		printf("|--------------------Liste des  présidents  ----------------------------");
		printf("\n|");
	   for(j=0;j<n;j++){
	   	    
	   		printf(" \n|--- %d. %s ----------------------------------------------------------",j+1,test[j].nom);
	   		printf("\n|");
		   }
		   printf("\n\n\n");
}
 void initialiserElections(int n ,struct Elections test[]){
    int i;
    
 	for(i=0;i<n;i++){
 		printf("\nentrez le nom de président N %d: ",i+1);
 		scanf("%s",test[i].nom);
	 }
 }
 void initialiserElecteurs(int n ,struct Electeurs Electeurs[]){
    int i;
    
 	for(i=0;i<n;i++){
 		printf("\nentrez le nom de président N %d: ",i+1);
 		scanf("%s",Electeurs[i].cin);
	 }
 }
main()
{
	bool inscP,inscE;
	int choix,a,b,i;
	struct Elections *test; 
	struct Electeurs *Electeurs;
	do{
	
   printf("-------Menu---------");
   printf("\n1.inscriptions élections présidentielles");
   printf("\n2.inscriptions des électeurs");
   printf("\n3.Vote");
   printf("\n4.Quiter");
   printf("\n\n Votre Choix : ");
   scanf("%d",&choix);
   
   switch(choix){
   	case 1 : 
	   do{
	   
	   printf("\nDonnez le nombres des présidents nominées aux élections présidentielles (minimum 5) : ");
   	    scanf("%d",&a);
   	    }while(a<5);
   	    test = malloc(a*sizeof(struct Elections)); 
   	    initialiserElections(a,test);
   	    	
	    inscP=true;
	   break;
   	case 2 : 
		   	do {
				printf("\nDonnez le nombres des électeurs (minimum 10) : ");
		   	    scanf("%d",&b);
		   	    }while(b<10);
		   	    Electeurs = (struct Electeurs *) malloc(b*sizeof(struct Electeurs)); 
		   	    initialiserElecteurs(b,Electeurs);
			   inscE=true;
	   break;
   	case 3 : if(!inscP){
		   printf(" Faire inscriptions des élections présidentielles\n");
	   }else if (!inscE){
	   	printf("\n Faire inscriptions des électeurs \n");
	   
	   }else{
	    afficherElections(test,a);
		premierVote(Electeurs,test,a,b);
			    
	   }
	        
			break;
   	case 4 : printf("choix4\n");break;
   	default: printf("choix incorrect !!");break;
   }
   
   }while(choix!=4);
}
