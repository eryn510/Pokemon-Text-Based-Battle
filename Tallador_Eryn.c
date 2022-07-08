#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>


//function delay is declared first in order to be used in the whole scope of the code
//output is next operation delayed by the amount of milliseconds input
//1000 = 1 second
void delay(int milliseconds);

/*
This function is for computing the damage output for both players
*/
int computeDamage(const char *moveType, const char *type1, const char *type2, const char *P1Type1,
const char *P1Type2, const char *P2Type1,const char *P2Type2, int basePower,int player)
{
	//return damage
	int DamageReturn;
	
	//player checker
	if (player==1){
		//string comparison for STAB Damage (Player 1)
		if(strcmp(P1Type1,moveType) == 0 || strcmp(P1Type2,moveType) == 0 ){
			basePower = basePower * 1.5;
		}
		
		else{
			basePower = basePower * 1;
		}
	}
	
	else if (player==2){
		//string comparison for STAB Damage (Player 2)
		if(strcmp(P2Type1,moveType) == 0 || strcmp(P2Type2,moveType) == 0 ){
			basePower = basePower * 1.5;
		}
		
		else{
			basePower = basePower * 1;
		}
	}
	
	//effectiveness of each typing
	if(type1=="Fire" && type2=="None"){
		//if statements for every typing
		if(moveType=="Fire"){
			DamageReturn = basePower / 2;
		}
		else if(moveType=="Water"){
			DamageReturn = basePower * 2;
		}
		else if(moveType=="Grass"){
			DamageReturn = basePower / 2;
		}
		else if(moveType=="Electric"){
			DamageReturn = basePower;
		}
		else if(moveType=="Ground"){
			DamageReturn = basePower * 2;
		}
		else if(moveType=="Ice"){
			DamageReturn = basePower / 2;
		}
	}
	else if(type1=="Water" && type2=="None"){
		//if statements for every typing
		if(moveType=="Fire"){
			DamageReturn = basePower / 2;
		}
		else if(moveType=="Water"){
			DamageReturn = basePower / 2;
		}
		else if(moveType=="Grass"){
			DamageReturn = basePower * 2;
		}
		else if(moveType=="Electric"){
			DamageReturn = basePower * 2;
		}
		else if(moveType=="Ground"){
			DamageReturn = basePower / 2;
		}
		else if(moveType=="Ice"){
			DamageReturn = basePower * 2;
		}
	}
	else if(type1=="Grass" && type2=="Ground"){
		//if statements for every typing
		if(moveType=="Fire"){
			DamageReturn = basePower;
		}
		else if(moveType=="Water"){
			DamageReturn = basePower;
		}
		else if(moveType=="Grass"){
			DamageReturn = basePower;
		}
		else if(moveType=="Electric"){
			DamageReturn = basePower * 0;
		}
		else if(moveType=="Ground"){
			DamageReturn = basePower / 2;
		}
		else if(moveType=="Ice"){
			DamageReturn = basePower * 4;
		}
	}
	else if(type1=="Electric" && type2=="None"){
		//if statements for every typing
		if(moveType=="Fire"){
			DamageReturn = basePower;
		}
		else if(moveType=="Water"){
			DamageReturn = basePower;
		}
		else if(moveType=="Grass"){
			DamageReturn = basePower * 0;
		}
		else if(moveType=="Electric"){
			DamageReturn = basePower;
		}
		else if(moveType=="Ground"){
			DamageReturn = basePower * 2;
		}
		else if(moveType=="Ice"){
			DamageReturn = basePower;
		}
	}
	else if(type1=="Ground" && type2=="None"){
		//if statements for every typing
		if(moveType=="Fire"){
			DamageReturn = basePower / 2;
		}
		else if(moveType=="Water"){
			DamageReturn = basePower * 2;
		}
		else if(moveType=="Grass"){
			DamageReturn = basePower * 2;
		}
		else if(moveType=="Electric"){
			DamageReturn = basePower * 0;
		}
		else if(moveType=="Ground"){
			DamageReturn = basePower / 1;
		}
		else if(moveType=="Ice"){
			DamageReturn = basePower * 2;
		}
	}
	else if(type1=="Ice" && type2=="Water"){
		//if statements for every typing
		if(moveType=="Fire"){
			DamageReturn = basePower;
		}
		else if(moveType=="Water"){
			DamageReturn = basePower;
		}
		else if(moveType=="Grass"){
			DamageReturn = basePower;
		}
		else if(moveType=="Electric"){
			DamageReturn = basePower * 2;
		}
		else if(moveType=="Ground"){
			DamageReturn = basePower / 4;
		}
		else if(moveType=="Ice"){
			DamageReturn = basePower * 2;
		}
	}
	else if(type1=="Ground" && type2=="Electric"){
		//if statements for every typing
		if(moveType=="Fire"){
			DamageReturn = basePower / 2;
		}
		else if(moveType=="Water"){
			DamageReturn = basePower * 2;
		}
		else if(moveType=="Grass"){
			DamageReturn = basePower * 0;
		}
		else if(moveType=="Electric"){
			DamageReturn = basePower * 0;
		}
		else if(moveType=="Ground"){
			DamageReturn = basePower * 2;
		}
		else if(moveType=="Ice"){
			DamageReturn = basePower * 2;
		}
	}
	return DamageReturn;
}

/*
This function is for the Battle Sequence
*/
void gamemenu(const char *P1Pokemon,const char *P2Pokemon,int P1health,int P2health,int P1maxHP,
int P2maxHP,const char *P1Move1,const char *P1Move2,const char *P2Move1,const char *P2Move2,int P1Move1BP,
int P1Move2BP,int P2Move1BP,int P2Move2BP, const char *P1Type1, const char *P1Type2, const char *P2Type1,
const char *P2Type2, const char *P1Move1Type, const char *P1Move2Type, const char *P2Move1Type,
const char *P2Move2Type, int P1Move1PP, int P1Move2PP, int P2Move1PP, int P2Move2PP)
{	
	//player move choice
	int nChoice1;
	int nChoice2;
	
	int player=1;

	//Protect PP
	int P1PP1=5;
	int P2PP1=5;
	
	//Charge Up PP
	int P1PP2=5;
	int P2PP2=5;
	
	//Protect Switch
	int ProtectP1=0;
	int ProtectP2=0;
	
	///Charge Switch
	int ChargeUpP1=0;
	int ChargeUpP2=0;
	
	//Previous Protect Checker
	int P1ProtectCheck=0;
	int P2ProtectCheck=0;
	
	//health checker loop
	while (P1health > 0 && P2health > 0){
		
		
		//pointer for damage calculator
		const char *type1;
		const char *type2;
		const char *moveType;
		
		int basePower;
		
		
        player = (player % 2) ? 1 : 2;
		
		//player1move
		if (player==1){
				//Interface
				printf("%s: %d/%d\n",P1Pokemon,P1health,P1maxHP);
					
				printf("%s: %d/%d\n",P2Pokemon,P2health,P2maxHP);
				
				//Player 1 Moveset
				printf("Player 1 Moves:\n");
				printf("\t [1]%s (%d BP, %d PP)",P1Move1,P1Move1BP,P1Move1PP);
				printf("\n\t [2]%s (%d BP, %d PP)",P1Move2,P1Move2BP,P1Move2PP);
				printf("\n\t [3]Protect (%d PP)",P1PP1);
				printf("\n\t [4]Charge Up (%d PP)",P1PP2);
			
			delay(2000);
			
			//No PP left for all moves
			if (P1Move1PP == 0 && P1Move2PP == 0 && P1PP1 == 0 && P1PP2 == 0){
				printf("\n\nYou have no moves left!");
				printf("\nYour Pokemon used Struggle!\n");
				P1health = P1health - 5;
				P2health = P2health - 10;
			} 	
			//PP is available for all/some moves
			else{
				//Player 1 Move Choice
				do{
					printf("\n\nWhat move will you choose:");
					scanf("%d",&nChoice1);
					printf("\n");
				}while (nChoice1 > 4 || nChoice1 < 1 ); //To ensure the user input is within the range of 1-4

				//Switch for Player 1 Selection
				switch(nChoice1){
				//Move 1 Effects
				case 1:
					//Move 1 PP Checker
					if(P1Move1PP == 0){
						printf("\nYou have no Power Points left fo this move!");
						printf("\nPlease select another move!\n");
						player--;
						getch();
					}
					else{
						printf("%s used %s!\n",P1Pokemon,P1Move1);
						delay(3000);
						//Player 2 Protect Checker
						if(ProtectP2 == 1){
							printf("\nDamage is negated by Enemy's [Protect]!\n");
							ProtectP2--;
						}
						//No Enemy Protect
						else{
							type1 = P2Type1;
							type2 = P2Type2;
							moveType = P1Move1Type;
							basePower = P1Move1BP;
							P2health = P2health - computeDamage(moveType,type1,type2,P1Type1,P1Type2,P2Type1,P2Type2,basePower,player);
							printf("%s dealt %d Damage!\n",P1Pokemon,computeDamage(moveType,type1,type2,P1Type1,P1Type2,P2Type1,P2Type2,basePower,player));
							//Charge Up Checker
							if (ChargeUpP1==1){
								P1Move1BP = P1Move1BP / 2;
								P1Move2BP = P1Move2BP / 2;
								ChargeUpP1--;
							}
							//Last Turn Protect Checker
							if (P1ProtectCheck==1){
								P1ProtectCheck--;
							}
						}
						P1Move1PP--;
					}
					break;
				//Move 2 Effects
				case 2:
					//Move 2 PP Checker
					if(P1Move2PP == 0){
						printf("\nYou have no Power Points left fo this move!");
						printf("\nPlease select another move!\n");
						player--;
						getch();
					}
					else{
						printf("%s used %s!\n",P1Pokemon,P1Move2);
						delay(3000);
						//Player 2 Protect Checker
						if(ProtectP2 == 1){
							printf("\nDamage is negated by Enemy's [Protect]!\n");
							ProtectP2--;
						}
						//No Enemy Protect
						else{
							type1 = P2Type1;
							type2 = P2Type2;
							moveType = P1Move2Type;
							basePower = P1Move2BP;
							P2health = P2health -computeDamage(moveType,type1,type2,P1Type1,P1Type2,P2Type1,P2Type2,basePower,player);
							printf("%s dealt %d Damage!\n",P1Pokemon,computeDamage(moveType,type1,type2,P1Type1,P1Type2,P2Type1,P2Type2,basePower,player));
							//Charge Up Checker
							if (ChargeUpP1==1){
								P1Move1BP = P1Move1BP / 2;
								P1Move2BP = P1Move2BP / 2;
								ChargeUpP1--;
							}
							//Last Turn Protect Checker
							if (P1ProtectCheck==1){
								P1ProtectCheck--;
							}
						}
						P1Move2PP--;
					}
					break;
				//Move 3 Effects
				case 3:
					//Move 3 PP Checker
					if(P1PP1 == 0){
						printf("\nYou have no Power Points left fo this move!");
						printf("\nPlease select another move!\n");
						player--;
						getch();
					}
					else{
						printf("%s used Protect!\n",P1Pokemon);
						//Last Turn Protect Checker
						if (P1ProtectCheck==0){
						ProtectP1++;
						P1PP1--;
						P1ProtectCheck++;
						}
						//Used Protection last turn
						else{
							delay(3000);
							printf("\nYou already used [Protect] last turn!");
							printf("\nChoose another move.\n");
							player--;
							//asks the player for another input
							getch();
						}
					}
					break;
				//Move 4 Effects
				case 4:
					//Move 4 PP Checker
					if(P1PP2 == 0){
						printf("\nYou have no Power Points left fo this move!");
						printf("\nPlease select another move!\n");
						player--;
						getch();
					}
					else{
						printf("%s used Charge Up!\n",P1Pokemon);
						//Last Turn Charge Up Checker
						if (ChargeUpP1==0){
							P1Move1BP = P1Move1BP * 2;
							P1Move2BP = P1Move2BP * 2;
							ChargeUpP1++;
						}
						//Used Charge Up last turn 
						else{
							delay(3000);
							printf("\nYou can't [Charge Up] any further!\n");
						}
						//Last Turn Protect Checker
						if (P1ProtectCheck==1){
							P1ProtectCheck--;
						}
						P1PP2--;
					}
					break;
				default:
					printf("\nInvalid move!\n");
					player--;
					getch();
				}
			}
			player++;
		}
		
		delay(2000);
		printf("*******************************************************************");
		printf("\n\n");
		printf("*******************************************************************\n");
		delay(2000);
		//player2move
		
		if (player==2 && P2health > 0){
				//Interface
				printf("%s: %d/%d\n",P1Pokemon,P1health,P1maxHP);
					
				printf("%s: %d/%d\n",P2Pokemon,P2health,P2maxHP);
				
				//Player 2 Moveset
				printf("Player 2 Moves:\n");
				printf("\t [1]%s (%d BP, %d PP)",P2Move1,P2Move1BP,P2Move1PP);
				printf("\n\t [2]%s (%d BP, %d PP)",P2Move2,P2Move2BP,P2Move2PP);
				printf("\n\t [3]Protect (%d PP)",P2PP1);
				printf("\n\t [4]Charge Up (%d PP)",P2PP2);
			
			delay(2000);
			
			if (P2Move1PP == 0 && P2Move2PP == 0 && P2PP1 == 0 && P2PP2 == 0){
				printf("\n\nYou have no moves left!");
				printf("\nYour Pokemon used Struggle!\n");
				P2health = P2health - 5;
				P1health = P1health - 10;
			} 
				
			else{
				do{
					//Player 2 Move Choice
					printf("\n\nWhat move will you choose:");
					scanf("%d",&nChoice2);
					printf("\n");
				}while (nChoice2 > 4 || nChoice2 < 1); //To ensure the user input is within the range of 1-4
				
				//Switch for Player 2 Selection
				switch(nChoice2){
				//Move 1 Effects
				case 1:
					//Move 1 PP Checker
					if(P2Move1PP == 0){
						printf("\nYou have no Power Points left fo this move!");
						printf("\nPlease select another move!\n");
						player--;
						getch();
					}
					else{
						printf("%s used %s!\n",P2Pokemon,P2Move1);
						delay(3000);
						//Player 1 Protect Checker
						if(ProtectP1 == 1){
							printf("\nDamage is negated by Enemy's [Protect]!\n");
							ProtectP1--;
						}
						//No Enemy Protect
						else{
							type1 = P1Type1;
							type2 = P1Type2;
							moveType = P2Move1Type;
							basePower = P2Move1BP;
							P1health = P1health - computeDamage(moveType,type1,type2,P1Type1,P1Type2,P2Type1,P2Type2,basePower,player);
							printf("%s dealt %d Damage!\n",P2Pokemon,computeDamage(moveType,type1,type2,P1Type1,P1Type2,P2Type1,P2Type2,basePower,player));
							//Charge Up Checker
							if (ChargeUpP2==1){
								P2Move1BP = P2Move1BP / 2;
								P2Move2BP = P2Move2BP / 2;
								ChargeUpP2--;
							}
							//Last turn Protect Checker
							if (P2ProtectCheck==1){
							P2ProtectCheck--;
							}
						}
						P2Move1PP--;
					}
					break;
				//Move 2 Effects
				case 2:
					//Move 2 PP Checker
					if(P2Move2PP == 0){
						printf("\nYou have no Power Points left fo this move!");
						printf("\nPlease select another move!\n");
						player--;
						getch();
					}
					else{
						printf("%s used %s!\n",P2Pokemon,P2Move2);
						delay(3000);
						//Player 1 Protect Checker
						if(ProtectP1 == 1){
							printf("\nDamage is negated by Enemy's [Protect]!\n");
							ProtectP1--;
						}
						//No Enemy Protect
						else{
							type1 = P1Type1;
							type2 = P1Type2;
							moveType = P2Move2Type;
							basePower = P2Move2BP;
							P1health = P1health - computeDamage(moveType,type1,type2,P1Type1,P1Type2,P2Type1,P2Type2,basePower,player);
							printf("%s dealt %d Damage!\n",P2Pokemon,computeDamage(moveType,type1,type2,P1Type1,P1Type2,P2Type1,P2Type2,basePower,player));
							//Charge Up Checker
							if (ChargeUpP2==1){
								P2Move1BP = P2Move1BP / 2;
								P2Move2BP = P2Move2BP / 2;
								ChargeUpP2--;
							}
							//Last turn Protect Checker
							if (P2ProtectCheck==1){
							P2ProtectCheck--;
							}
						}
						P2Move2PP--;
					}
					break;
				//Move 3 Effects
				case 3:
					//Move 3 PP Checker
					if(P2PP1 == 0){
						printf("\nYou have no Power Points left fo this move!");
						printf("\nPlease select another move!\n");
						player--;
						getch();
					}
					else{
						printf("%s used Protect!\n",P2Pokemon);
						//Last Turn Protect Checker
						if(P2ProtectCheck==0){
						ProtectP2++;
						P2PP1--;
						P2ProtectCheck++;
						}
						//Used Protect last turn
						else{
							delay(3000);
							printf("\nYou already used [Protect] last turn!");
							printf("\nChoose another move.\n");
							player--;
							//asks the player for another input
							getch();
						}
					}
					break;
				//Move 4 Effects
				case 4:
					//Move 4 PP Checker
					if(P2PP2 == 0){
						printf("\nYou have no Power Points left fo this move!");
						printf("\nPlease select another move!\n");
						player--;
						getch();
					}
					else{
						printf("%s used Charge Up!\n",P2Pokemon);
						//Charge Up Checker
						if (ChargeUpP2==0){
							P2Move1BP = P2Move1BP * 2;
							P2Move2BP = P2Move2BP * 2;
							ChargeUpP2++;
						}
						//Used Charge Up last turn
						else{
							delay(3000);
							printf("\nYou can't [Charge Up] any further!\n");
						}
						//Last Turn Protect Checker
						if (P2ProtectCheck==1){
						P2ProtectCheck--;
						}
						P2PP2--;
					}
					break;
				default:
					printf("\nInvalid move!\n");
					player--;
					getch();
				}
			}
			player++;
		}
		
		delay(2000);
		printf("*******************************************************************");
		printf("\n\n");
		printf("*******************************************************************\n");
		delay(2000);
		
		system("cls");
	}
	
	//Winner Checker
	if (P1health > P2health){
		printf("Player 1 Wins!");
	}
	else{
		printf("Player 2 Wins!");
	}
}

int main(){
	//pokemon list
	const char *pokemon[7]={"Entei","Milotic","Torterra","Pikachu","Groudon","Lapras","Stunfisk"};
	
	//move list
	const char *pMoves[9]={"Fire Blast","Earthquake","Scald","Ice Beam","Dig","Leaf Storm","Thunderbolt",
	"Fissure","Water Gun"};
	
	//types
	const char *types[7]={"Fire","Water","Grass","Electric","Ground","Ice","None"};
	
	//pokemon pointers
	const char *P1Pokemon;
	const char *P2Pokemon;
	
	//pokemon type pointers
	const char *P1Type1;
	const char *P1Type2;
	const char *P2Type1;
	const char *P2Type2;
	
	//pokemon health
	int P1health;
	int P1maxHP;
	int P2health;
	int P2maxHP;
	
	//move pointers
	const char *P1Move1;
	const char *P1Move2;
	const char *P2Move1;
	const char *P2Move2;
	
	//move type
	const char *P1Move1Type;
	const char *P1Move2Type;
	const char *P2Move1Type;
	const char *P2Move2Type;
	
	//moveBasePower
	int P1Move1BP;
	int P1Move2BP;
	int P2Move1BP;
	int P2Move2BP;
	
	//movePowerPoints
	int P1Move1PP;
	int P1Move2PP;
	int P2Move1PP;
	int P2Move2PP;
	
	//pokemon choice
	int Choice;
	
	//Selection of Pokemon
	printf("Pokemon Choices:\n");
	printf("\t[1]Entei\n");
	printf("\t[2]Milotic\n");
	printf("\t[3]Torterra\n");
	printf("\t[4]Pikachu\n");
	printf("\t[5]Groudon\n");
	printf("\t[6]Lapras\n");
	printf("\t[7]Stunfisk\n\n");
	//Player 1 selection
	do{
	printf("Player 1, Please select a Pokemon:");
	scanf("%d",&Choice);
	}while (Choice < 1 || Choice > 7);
	
	/* 
	This function assigns stats 
	to your selected pokemon
	*/
	//Selected Pokemon (Player 1)
	switch(Choice){
		//Entei Stats
		case 1: 
			P1Pokemon=pokemon[0];
			P1Type1=types[0];
			P1Type2=types[6];
			P1health=150;
			P1maxHP=150;
			P1Move1=pMoves[0];
			P1Move2=pMoves[1];
			P1Move1Type=types[0];
			P1Move2Type=types[4];
			P1Move1BP=30;
			P1Move2BP=30;
			P1Move1PP=5;
			P1Move2PP=5;
			break;
		//Milotic Stats
		case 2: 
			P1Pokemon=pokemon[1];
			P1Type1=types[1];
			P1Type2=types[6];
			P1health=200;
			P1maxHP=200;
			P1Move1=pMoves[2];
			P1Move2=pMoves[3];
			P1Move1Type=types[1];
			P1Move2Type=types[5];
			P1Move1BP=20;
			P1Move2BP=20;
			P1Move1PP=7;
			P1Move2PP=7;
			break;
		//Torterra Stats
		case 3: 
			P1Pokemon=pokemon[2];
			P1Type1=types[2];
			P1Type2=types[4];
			P1health=220;
			P1maxHP=220;
			P1Move1=pMoves[4];
			P1Move2=pMoves[5];
			P1Move1Type=types[4];
			P1Move2Type=types[2];
			P1Move1BP=20;
			P1Move2BP=40;
			P1Move1PP=7;
			P1Move2PP=5;
			break;
		//Pikachu Stats
		case 4: 
			P1Pokemon=pokemon[3];
			P1Type1=types[3];
			P1Type2=types[6];
			P1health=120;
			P1maxHP=120;
			P1Move1=pMoves[6];
			P1Move2=pMoves[4];
			P1Move1Type=types[3];
			P1Move2Type=types[4];
			P1Move1BP=10;
			P1Move2BP=20;
			P1Move1PP=10;
			P1Move2PP=7;
			break;
		//Groudon Stats
		case 5: 
			P1Pokemon=pokemon[4];
			P1Type1=types[4];
			P1Type2=types[6];
			P1health=150;
			P1maxHP=150;
			P1Move1=pMoves[7];
			P1Move2=pMoves[0];
			P1Move1Type=types[4];
			P1Move2Type=types[0];
			P1Move1BP=40;
			P1Move2BP=30;
			P1Move1PP=5;
			P1Move2PP=5;
			break;
		//Lapras Stats
		case 6: 
			P1Pokemon=pokemon[5];
			P1Type1=types[5];
			P1Type2=types[1];
			P1health=190;
			P1maxHP=190;
			P1Move1=pMoves[3];
			P1Move2=pMoves[2];
			P1Move1Type=types[5];
			P1Move2Type=types[1];
			P1Move1BP=20;
			P1Move2BP=20;
			P1Move1PP=7;
			P1Move2PP=7;
			break;
		//Stunfisk Stats
		case 7: 
			P1Pokemon=pokemon[6];
			P1Type1=types[4];
			P1Type2=types[3];
			P1health=130;
			P1maxHP=130;
			P1Move1=pMoves[8];
			P1Move2=pMoves[1];
			P1Move1Type=types[1];
			P1Move2Type=types[4];
			P1Move1BP=10;
			P1Move2BP=30;
			P1Move1PP=10;
			P1Move2PP=5;
			break;
	}
	//choice flusher
	fflush(stdin);
	
	printf("\nPlayer 1 chose %s\n",P1Pokemon);
	delay(2000);
	
	//Player 2 selection
	do{
	printf("\nPlayer 2, Please select a Pokemon:");
	scanf("%d",&Choice);
	}while (Choice < 1 || Choice > 7);
	
	//Selected Pokemon (Player 2)
	switch(Choice){
		//Entei Stats
		case 1: 
			P2Pokemon=pokemon[0];
			P2Type1=types[0];
			P2Type2=types[6];
			P2health=150;
			P2maxHP=150;
			P2Move1=pMoves[0];
			P2Move2=pMoves[1];
			P2Move1Type=types[0];
			P2Move2Type=types[4];
			P2Move1BP=30;
			P2Move2BP=30;
			P2Move1PP=5;
			P2Move2PP=5;
			break;
		//Milotic Stats
		case 2: 
			P2Pokemon=pokemon[1];
			P2Type1=types[1];
			P2Type2=types[6];
			P2health=200;
			P2maxHP=200;
			P2Move1=pMoves[2];
			P2Move2=pMoves[3];
			P2Move1Type=types[1];
			P2Move2Type=types[5];
			P2Move1BP=20;
			P2Move2BP=20;
			P2Move1PP=7;
			P2Move2PP=7;
			break;
		case 3:
		//Torterra Stats 
			P2Pokemon=pokemon[2];
			P2Type1=types[2];
			P2Type2=types[4];
			P2health=220;
			P2maxHP=220;
			P2Move1=pMoves[4];
			P2Move2=pMoves[5];
			P2Move1Type=types[4];
			P2Move2Type=types[2];
			P2Move1BP=20;
			P2Move2BP=40;
			P2Move1PP=7;
			P2Move2PP=5;
			break;
		case 4:
		//Pikachu Stats 
			P2Pokemon=pokemon[3];
			P2Type1=types[3];
			P2Type2=types[6];
			P2health=120;
			P2maxHP=120;
			P2Move1=pMoves[6];
			P2Move2=pMoves[4];
			P2Move1Type=types[3];
			P2Move2Type=types[4];
			P2Move1BP=10;
			P2Move2BP=20;
			P2Move1PP=10;
			P2Move2PP=7;
			break;
		case 5: 
		//Groudon Stats 
			P2Pokemon=pokemon[4];
			P2Type1=types[4];
			P2Type2=types[6];
			P2health=150;
			P2maxHP=150;
			P2Move1=pMoves[7];
			P2Move2=pMoves[0];
			P2Move1Type=types[4];
			P2Move2Type=types[0];
			P2Move1BP=40;
			P2Move2BP=30;
			P2Move1PP=5;
			P2Move2PP=5;
			break;
		case 6: 
		//Lapras Stats
			P2Pokemon=pokemon[5];
			P2Type1=types[5];
			P2Type2=types[1];
			P2health=190;
			P2maxHP=190;
			P2Move1=pMoves[3];
			P2Move2=pMoves[2];
			P2Move1Type=types[5];
			P2Move2Type=types[1];
			P2Move1BP=20;
			P2Move2BP=20;
			P2Move1PP=7;
			P2Move2PP=7;
			break;
		case 7:
		//Stunfisk Stats 
			P2Pokemon=pokemon[6];
			P2Type1=types[4];
			P2Type2=types[3];
			P2health=130;
			P2maxHP=130;
			P2Move1=pMoves[8];
			P2Move2=pMoves[1];
			P2Move1Type=types[1];
			P2Move2Type=types[4];
			P2Move1BP=10;
			P2Move2BP=30;
			P2Move1PP=10;
			P2Move2PP=5;
			break;
	}
	//choice flusher
	fflush(stdin);
	
	printf("\nPlayer 2 chose %s\n",P2Pokemon);
	delay(2000);
	
	printf("\n\nPress any key to continue:");
	getch();
	system("cls");
	
	
	//Battle Sequence
	gamemenu(P1Pokemon,P2Pokemon,P1health,P2health,P1maxHP,P2maxHP,P1Move1,P1Move2,P2Move1,P2Move2,
	P1Move1BP,P1Move2BP,P2Move1BP,P2Move2BP,P1Type1,P1Type2,P2Type1,P2Type2,P1Move1Type,P1Move2Type,
	P2Move1Type,P2Move2Type,P1Move1PP,P1Move2PP,P2Move1PP,P2Move2PP);
	
	return 0;
}

//function for the operation of millisecond delay
void delay(int milliseconds)
{
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}
