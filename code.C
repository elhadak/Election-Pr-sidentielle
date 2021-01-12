#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
//-----------------------Structure De Donnee
struct Presidents{
	char nom[20];
	int  nbrVote ;
};

typedef struct Presidents Presidents;

struct Electeurs{
	char cin[10];
};

typedef struct Electeurs Electeurs;

//--------------------------Fonction de vote------------------


void  premierVote(Electeurs Electeurs[],Presidents test[],int nomPres,int nomVot ){
		int min,max;
		bool flag=false;
		double voteCritique;
		Presidents presidentT1[nomPres];
		int vote,i,j,compt,comptT3,comptT2,equalsVote,x;
	  		do{
			  	i=0;	  
		        compt=0;
		        printf("\n");
			    printf("\nPremier tour :");
			    printf("\n\n");
	                do{
				
					    printf("Electeurs Num Cin %s choisir le nombre de president : ", Electeurs[i].cin);
					    scanf("%d",&vote);
						    if(vote>0 && vote<=nomPres){
						    	test[vote-1].nbrVote++;
						    	i++;
							}else{
						        printf("(repeter votre vote) ");
						         }
				      }while(i<nomVot);
			    
			    voteCritique=nomVot*0.15;
			    for(j=0;j<nomPres;j++){
			    	if(test[j].nbrVote>=voteCritique){
			            presidentT1[compt]=test[j];
			            compt++;
					}
				}
				printf("\n---------------Liste des  presidents nomines Tour 1 -------------------------");
				
				for(j=0;j<compt;j++){
			    	printf("\n|-- %d. %s le nombre de vote : %d -----------------",j+1,presidentT1[j].nom,presidentT1[j].nbrVote);
			    	
			    	if(presidentT1[j].nbrVote==nomVot){
			    		printf("\n\n\n");
			    		printf("\n---------------------le president officiel reussi --------------------");
			    		printf("\n\n\n");
			    		printf("\n|-- %d. Monsieur le president  %s le nombre de vote : %d   (felicitation) -----------------",j+1,presidentT1[j].nom,presidentT1[j].nbrVote);
			    		exit(0);
					}	
				}
				equalsVote=presidentT1[0].nbrVote;
				for(x=1;x<nomPres;x++){
					if(equalsVote!=test[x].nbrVote){
						flag=true;
						break;
					}	
				}
				for(i=0;i<compt;i++){
					
					presidentT1[i].nbrVote=0;
				}
				//------reinitialiser un tableau
				for(i=0;i<nomPres;i++){
				    test[j].nbrVote=0;
			    }
				}while(!flag);
				
				
				
				
				
				//----------Deuxième tour : --------------------------------------
				
				Presidents presidentT2[compt];
				flag=false;
				do{
				
					i=0;comptT2=0;
					printf("\n\n ");
					printf("\n Deuxieme tour : ");
					printf("\n\n ");
					do{
						printf("Electeurs Num Cin %s choisir le nombre de president : ", Electeurs[i].cin);
					    scanf("%d",&vote);
					    if(vote>0 && vote<=compt){
					    	presidentT1[vote-1].nbrVote++;
					    	i++;
						}else{
						printf("(repeter votre vote) ");
					         }
			       }while(i<nomVot);
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
				    printf("\n---------------Liste des  presidents nomines Tour 2 -------------------------");
					if(flag==false){
						comptT2=compt;
						for(i=0;i<compt;i++){
							presidentT2[i]=presidentT1[i];
						}
						}
					for(j=0;j<comptT2;j++){
				    	printf("\n|-- %d. %s le nombre de vote : %d -----------------",j+1,presidentT2[j].nom,presidentT2[j].nbrVote);
				    	
				    	if(presidentT2[j].nbrVote==nomVot){
				    		printf("\n\n\n");
				    		printf("\n---------------------le president officiel reussi --------------------");
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
				
				
				
				
				Presidents presidentT3[comptT2];
				flag=false;
				do{
				
					i=0;comptT3=0;
					printf("\n");
					printf("\n Troisieme tour : ");
					printf("\n\n");
					do{
						printf("Electeurs Num Cin %s choisir le nombre de president : ", Electeurs[i].cin);
					    scanf("%d",&vote);
					    if(vote>0 && vote<=comptT2){
					    	presidentT2[vote-1].nbrVote++;
					    	i++;
						}else{
							printf("(repeter votre vote) ");
						}
				    }while(i<nomVot);
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
						printf("\n---------------Liste des  presidents nomines Tour 3 -------------------------");
						comptT3=comptT2;
					    }
					for(j=0;j<comptT3;j++){
						if(comptT3==1){
							printf("\n\n\n");
				    		printf("\n---------------------le president officiel reussi --------------------");
				    		printf("\n\n\n");
				    		printf("\n|-- %d. Monsieur le president  %s le nombre de vote : %d   (felicitation) -----------------",j+1,presidentT3[j].nom,presidentT3[j].nbrVote);
				    		exit(0);
						}else{
					
				    	printf("\n|-- %d. %s le nombre de vote : %d -----------------",j+1,presidentT2[j].nom,presidentT2[j].nbrVote);
				    	}
				    	if(presidentT2[j].nbrVote==nomVot){
				    		printf("\n\n\n");
				    		printf("\n---------------------le president officiel reussi --------------------");
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

void afficherElections(Presidents test[],int n){
	    int j;
		printf("|--------------------Liste des  presidents  ----------------------------");
		printf("\n|");
	    for(j=0;j<n;j++){
	   		printf(" \n|--- %d. %s ----------------------------------------------------------",j+1,test[j].nom);
	   		printf("\n|");
		   }
		printf("\n\n\n");
}
 void initialiserElections(int n ,Presidents test[]){
    int i;
 	for(i=0;i<n;i++){
 		printf("\nentrez le nom de president Numero %d: ",i+1);
 		scanf("%s",test[i].nom);
	 }
 }
 void initialiserElecteurs(int n ,Electeurs Electeurs[]){
    int i;
 	for(i=0;i<n;i++){
 		printf("\nentrez le nom de president Numero %d: ",i+1);
 		scanf("%s",Electeurs[i].cin);
	 }
 }
main()
{
		bool inscP,inscE;
		int choix,nomPres,nomVot,i;
		Presidents *test; 
		Electeurs *Electeurs;
		do{
		
	   
	   printf("\n------------Menu-----------------");
	   printf("\n1.inscriptions elections presidentielles");
	   printf("\n2.inscriptions des electeurs");
	   printf("\n3.Vote");
	   printf("\n4.Quiter");
	   printf("\n----------------------------------------------");
	   printf("\n\n Votre Choix : ");
	   scanf("%d",&choix);
	   printf("\n");
	   
	   switch(choix){
	   	case 1 : 
		   do{
		   
		   printf("\nDonnez le nombres des presidents nominees aux elections presidentielles (minimum 5) : ");
	   	    scanf("%d",&nomPres);
	   	    }while(nomPres<5);
	   	    test = malloc(nomPres*sizeof(Presidents)); 
	   	    initialiserElections(nomPres,test);
	   	    	
		    inscP=true;
		   break;
	   	case 2 : 
			   	do {
					printf("\nDonnez le nombres des electeurs (minimum 10) : ");
			   	    scanf("%d",&nomVot);
			   	    }while(nomVot<10);
			   	    Electeurs = malloc(nomVot*sizeof(Electeurs)); 
			   	    initialiserElecteurs(nomVot,Electeurs);
				   inscE=true;
		   break;
	   	case 3 : if(!inscP){
			   printf("\n Attention : Faire inscriptions des elections presidentielles!!!");
		   }else if (!inscE){
		   	printf("\n Attention: Faire inscriptions des electeurs \n");
		   
		   }else{
		    afficherElections(test,nomPres);
			premierVote(Electeurs,test,nomPres,nomVot);
				    
		   }
		        
				break;
	   	case 4 : exit(EXIT_SUCCESS);break;
	   	default: printf("\nchoix incorrect !!");break;
	   }
	   
	   }while(choix!=4);
}
