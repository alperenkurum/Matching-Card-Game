#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include<windows.h>

#define DEBUG

int game[8][8] ,
	columnmemory[] =	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	rowmemory[] = 		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	memory[] =			{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	z, point = 0, playercount = 0, cmppoint = 0, cmpcount = 0, tour = 0;
int main(){
	int hardship;
	int memory[8], columnmemory[8], rowmemory[8], z;
	int i, j, k, column, row, column1, row1, row2, column2, x = 100, y = 0;
	char temp;
	bool again = true, againcmp = true;
	srand(time(NULL));
	printf("EASY mode >>> 1\nMEDIUM MODE >>> 2\nHARD Mode >>> 3\nSelect difficulity >>> ");
	
	scanf("%d", &hardship);
	if(hardship == 1){
		//easy Mode
		random(4);
		open_board(0, 4);
		sleep(1);
		system("cLs");
		while((cmppoint < 5 && point < 5) && (cmppoint != 4 || point != 4) ){
			player_guess(4,2);
			cmp_guess(4,2);
		}
		if(cmppoint > point){
			printf("!!!!winner is computer!!!\nYou are loser.\nGuess count: %d", cmpcount);
		}else if(cmppoint == point){
			printf("!!!Ahh you was close to win. Game is end in a draw.");
		}else{
			printf("!!!!You Win!!!\nYou are the best.\nGuess count: %d", playercount);
		}
	}else if(hardship == 2){
		//Medium Mode
		random(6);
		open_board(0, 6);
		sleep(1);
		system("cLs");
		while((cmppoint < 10 && point < 10) && (cmppoint != 9 || point != 9)){
			player_guess(6,6);
			cmp_guess(6,6);
		}
		
		if(cmppoint > point){
			printf("!!!!winner is computer!!!\nYou are loser.\nGuess count: %d", cmpcount);
		}else if(cmppoint == point){
			printf("!!!Ahh you was close to win. Game is end in a draw.");
		}else{
			printf("!!!!You Win!!!\nYou are the best.\nGuess count: %d", playercount);
		}
			
	}else if (hardship == 3){
		//Hard Mode
		random(8);
		open_board(0, 8);
		sleep(1);
		system("cLs");
		while((cmppoint < 17 && point < 17) && (cmppoint != 10 || point != 10)){
			player_guess(8,16);
			cmp_guess(8,16);
		}
		if(cmppoint > point){
			printf("!!!!winner is computer!!!\nYou are loser.\nGuess count: %d", cmpcount);
		}else if(cmppoint == point){
			printf("!!!Ahh you was close to win. Game is end in a draw.");
		}else{
			printf("!!!!You Win!!!\nYou are the best.\nGuess count: %d", playercount);
		}
		
	}else{
		printf("Please enter valid number!!");
		
	}
	return 0;	
}

int open_board(int tourcount, int mode){
	int i, j, k;
	printf("\n");
	for(i = 0; i < (mode*6)+12; i++){
		if(i == mode*6 + 11){
			printf("_\n");
		}else{
		printf("_");
		}
	}

	for(i = 1; i < mode+1; i++){
		if(i == 1){
			printf("|TOUR(%03d)||  1  |", tourcount);  
		}else if(i == mode){
			printf("  %d  |\n", i);
		}else{
			printf("  %d  |", i);
		}
	}
	
	for(k = 0; k < (mode*6)+12; k++){
		if(k == mode*6 + 11){
			printf("-\n");
		}else{
			printf("-");
			}
	}
		
	for(i = 0; i < mode; i++){
		printf("|____%d____||", i+1);
		for (j = 0; j < mode; j++){
			if(j == mode -1){
				printf(" %d |\n", game[i][j]);
			}else{
				printf(" %d |", game[i][j]);
				}
		}
		if(i != mode){
			for(k = 0; k < (mode*6)+12; k++){
				if(k == mode*6 + 11){
					printf("-\n");
				}else{
					printf("-");
				}
			}
		}
	}
	return 0;
}
int board(int tourcount, int mode, int row, int column, int row2, int column2){
	int i, j, k;
	printf("\n");
	for(i = 0; i < (mode*6)+12; i++){
		if(i == mode*6 + 11){
			printf("_\n");
		}else{
		printf("_");
		}
	}

	for(i = 1; i < mode+1; i++){
		if(i == 1){
			printf("|TOUR(%03d)||  1  |", tourcount);  
		}else if(i == mode){
			printf("  %d  |\n", i);
		}else{
			printf("  %d  |", i);
		}
	}
	
	for(k = 0; k < (mode*6)+12; k++){
		if(k == mode*6 + 11){
			printf("-\n");
		}else{
			printf("-");
			}
	}
		
	for(i = 0; i < mode; i++){
		printf("|____%d____||", i+1);
		for (j = 0; j < mode; j++){
			if(game[i][j] == 0){
				if(j != mode-1){
					printf(" --- |");
				}else{
					printf(" --- |\n");
				}
			}else if(i == row && j == column){
				if(j == mode -1){
					printf(" %d |\n", game[i][j]);
				}else{
					printf(" %d |", game[i][j]);
				}
			}else if(i == row2 && j == column2){
				if(j == mode -1){
					printf(" %d |\n", game[i][j]);
				}else{
					printf(" %d |", game[i][j]);
				}
			}else if(j == mode-1){
				printf(" *** |\n");					//DO THE STAR WRITING 
			}else{
				printf(" *** |", game[i][j]);
			}
		}
		if(i != mode){
			for(k = 0; k < (mode*6)+12; k++){
				if(k == mode*6 + 11){
					printf("-\n");
				}else{
					printf("-");
				}
			}
		}
	}
	return 0;
}
int random(int z){
	// 3 1 6 4 5 2
	#ifdef DEBUG
	srand(1);
	#endif
	int x = 100, row, column, column1, column2, row1, row2, i, j, k;
	char temp;
	for(i = 0; i < z; i++){
		for(j = 0;j < z; j++){
		game[i][j] = -1;
		}
	}
	while(x < 100+(z*z/2)){
		column1 = rand() % z; 
		row1 = rand() % z;
		column2 = rand() % z; 
		row2 = rand() % z;
		if(game[row1][column1] == -1 && game[row2][column2] == -1 && (row1 != row2 || column1 != column2)){
			game[row1][column1] = x;
			game[row2][column2] = x;			
			x++;	
		}	
	}
	return 0;	
}
int player_guess(int mode, int memo){
	int i, j, k, row[2], column[2], t =0, count = 0;
	bool check = false, check2 = false;
	while(t < 2){
		if((cmppoint < (mode*mode)/4+1 && point < (mode*mode)/4+1) && (cmppoint != (mode*mode)/4 || point != (mode*mode)/4)){
			printf("\n<|> Player's turn <|>\n\n");
			#ifdef DEBUG
			printf("\n-----MEMORY-----\n");
			for(k = 0; k < memo; k++){
				printf("%d  ", memory[k]);
			}
			#endif
			if(t == 0){
				board(playercount+cmpcount, mode, -1, -1, -1, -1);
			}else{
				board(playercount+cmpcount, mode, row[t-1], column[t-1], -1, -1);
			}
			printf("\nEnter the row: ");
			scanf("%d", &row[t]);
			printf("\nEnter the column: ");
			scanf("%d", &column[t]);
			row[t]--;
			column[t]--;
			sleep(0,5);
			system("cls");
			if((row[t] == row[t-1] && column[t] == column[t-1] && t != 0) || game[row[t]][column[t]] == 0 || (row[t] > mode-1 || column[t] > mode-1)){
				printf("\n!!Please enter valid spot!!\n");
				sleep(1);
				system("cls");
				t--;
				
			}else{
				printf("\n<|> Player's turn <|>\n\n");
				playercount++;
				if(t == 1){
					board(playercount+cmpcount, mode,row[t], column[t], row[t-1], column[t-1]);
				}else{
					board(playercount+cmpcount, mode,row[t], column[t], -1, -1);
				}
				printf("Player's point: %d\n", point);
				printf("Computer's point: %d\n", cmppoint);
				sleep(2);
				system("cls");
			/*	printf("\n-----MEMORY-----\n");
					for(k = 0; k < memo; k++){
						printf("%d", memory[k]);
					}*/
			}
			if(t == 1){
				if(game[row[t]][column[t]] == game[row[t-1]][column[t-1]] && (row[t] != row[t-1] || column[t] != column[t-1])){
					point++;
					game[row[t]][column[t]] = 0;
					game[row[t-1]][column[t-1]] = 0;
					t = 0;
					printf("\n<|> Player's turn <|>\n\n");
					board(playercount+cmpcount, mode, -1, -1, -1, -1);
					printf("Player's point: %d\n", point);
					printf("Computer's point: %d\n", cmppoint);
					sleep(2);
					system("cLs");
				}else{
					t++;
					for(i = 0; i < memo; i++){
						if(rowmemory[i] == row[0] && columnmemory[i] == column[0]){
							for(j = i; j < memo; j++){
								memory[j] = memory[j+1];
								rowmemory[j] = rowmemory[j+1];
								columnmemory[j] = columnmemory[j+1];
							} 
						}else if(rowmemory[i] == row[1] && columnmemory[i] == column[1]){
							for(j = i; j < memo; j++){
								memory[j] = memory[j+1];
								rowmemory[j] = rowmemory[j+1];
								columnmemory[j] = columnmemory[j+1];
							} 
						} 
					}
					for(i = 0; i < memo; i++){
						if(memory[i] == -1){
							count++;
						}
					}
					if(count == 0){
						for(i = 0; i < memo; i++){
							memory[i] = memory[i+2];
							rowmemory[i] = rowmemory[i+2];
							columnmemory[i] = columnmemory[i+2];
						}
						rowmemory[memo-2] = row[0];
						columnmemory[memo-2] = column[0];
						memory[memo-2] = game[row[0]][column[0]];
						
						rowmemory[memo-1] = row[1];
						columnmemory[memo-1] = column[1];
						memory[memo-1] = game[row[1]][column[1]];
					}else if(count == 1){
						for(i = 0; i < memo; i++){
							memory[i] = memory[i+1];
							rowmemory[i] = rowmemory[i+1];
							columnmemory[i] = columnmemory[i+1];
						}
						memory[mode-2] = row[0];
						columnmemory[mode-2] = column[0];
						memory[mode-2] = game[row[0]][column[0]];
						
						memory[mode-1] = row[1];
						columnmemory[mode-1] = column[1];
						memory[mode-1] = game[row[1]][column[1]];
					}else{
						i = 0;
						while(check == false){
							if(memory[i] == -1 && memory[i+1] == -1){
								rowmemory[i] = row[0];
								columnmemory[i] = column[0];
								memory[i] = game[row[0]][column[0]];
						
								rowmemory[i+1] = row[1];
								columnmemory[i+1] = column[1];
								memory[i+1] = game[row[1]][column[1]];
								
								check = true;
							}
							i++;
						}
					}	
				}
			}else{
				t++;
			}
			
		}else{
			return 0;
		}	
	}
	for(i = 0; i < 2; i++){
	row[i] = -1;
	column[i] = -1;
	}
	return 0;	            
}
int cmp_guess(int mode, int memo){
	int i, j, k, row, column, t = 0; 
	bool check = false, check2 = false, check3 = false;
	if((cmppoint < (mode*mode)/4+1 && point < (mode*mode)/4+1) && (cmppoint != (mode*mode)/4 || point != (mode*mode)/4)){
		for(i = 0; i < memo-1; i++){
			for(j = i+1; j < memo; j++){
				if(memory[i] == memory[j] && memory[i] != -1){
					cmpcount=+2;		
					cmppoint++;	
					printf("\n<|> Computer's turn <|>\n\n");
					#ifdef DEBUG
					printf("\n-----MEMORY-----\n");
						for(k = 0; k < memo; k++){
					printf("%d  ", memory[k]);
					}
					#endif
					board(playercount+cmpcount, mode, rowmemory[i], columnmemory[i], rowmemory[j], columnmemory[j]);
					printf("Player's point: %d\n", point);
					printf("Computer's point: %d\n", cmppoint);
					sleep(2);
					system("cLs");
					
					game[rowmemory[i]][columnmemory[i]] = 0;
					game[rowmemory[j]][columnmemory[j]] = 0;
					for(k = i; k < memo; k++){
						memory[k] = memory[k+1];
						rowmemory[k] = rowmemory[k+1];
						columnmemory[k] = columnmemory[k+1];
						if(k == memo-1){		
							memory[k] = -1;
							rowmemory[k] = -1;
							columnmemory[k] = -1;
						}
					}
					for(k = j-1; k < memo; k++){
						memory[k] = memory[k+1];
						rowmemory[k] = rowmemory[k+1];
						columnmemory[k] = columnmemory[k+1];
						if(k == memo-1){		
							memory[k] = -1;
							rowmemory[k] = -1;
							columnmemory[k] = -1;
						}
					}
					
				}			
			}
		}
		while(t < 2){
			if((cmppoint < (mode*mode)/4+1 && point < (mode*mode)/4+1) && (cmppoint != (mode*mode)/4 || point != (mode*mode)/4)){
				row = rand() % mode;
				column = rand() % mode;
				for(i = 0; i < memo; i++){
					if((row == rowmemory[i] && column == columnmemory[i]) || game[row][column] == 0){
						check = true;
					}
				}
				if(check == false){
					cmpcount++;
					t++;
					printf("\n<|> Computer's turn <|>\n\n");
					#ifdef DEBUG
					printf("\n-----MEMORY-----\n");
						for(k = 0; k < memo; k++){
					printf("%d  ", memory[k]);
					}
					#endif
					board(playercount+cmpcount, mode, row, column, -1, -1);
					printf("Player's point: %d\n", point);
					printf("Computer's point: %d\n", cmppoint);
					sleep(2);
					system("cLs");
					i = 0;	
					while(i < memo && check2 == false){
						if(game[row][column] == memory[i] && (row != rowmemory[i] || column != columnmemory[i])){
							cmpcount++;
							game[row][column] = 0;
							game[rowmemory[i]][columnmemory[i]] = 0;
							t = 0;
							cmppoint++;
							board(playercount+cmpcount, mode, row, column, rowmemory[i], columnmemory[i]);
							printf("\n<|> Computer's turn <|>\n\n");
							#ifdef DEBUG
								printf("\n-----MEMORY-----\n");
							for(k = 0; k < memo; k++){
								printf("%d  ", memory[k]);
								}
							#endif
							printf("\nPlayer's point: %d\n", point);
							printf("Computer's point: %d\n", cmppoint);
							sleep(2);
							system("cls");
							check2 = true;
							for(j = i; j < memo; j++){
								memory[j] = memory[j+1];
								rowmemory[j] = rowmemory[j+1];						//hafýza kaydýrma iþlemleri
								columnmemory[j] = columnmemory[j+1];
								if(j == memo-1){		
									memory[j] = -1;
								}
							}
						}
						i++;
					}
					if(check2 == false){
						for(i = 0; i < memo; i++){
							if(rowmemory[i] == row && columnmemory[i] == column){
								for(j = i; j < memo; j++){
									memory[j] = memory[j+1];
									rowmemory[j] = rowmemory[j+1];
									columnmemory[j] = columnmemory[j+1];

								} 
							}
						} 
						for(i = 0; i < memo; i++){
							if(memory[i] == -1 && !check3){
								memory[i] = game[row][column];
								rowmemory[i] = row;
								columnmemory[i] = column;
								check3 = true;
							}else if(i == memo-1 && check3 == false){
								for(j = 0; j < memo; j++){		//hafýzada tutma sayýsý buradaki sýnýr
									memory[j] = memory[j+1];
									rowmemory[j] = rowmemory[j+1];				//kaydýrma iþlemleri
									columnmemory[j] = columnmemory[j+1];
									if(j == memo-1){		//hafýzada tutma sayýsý - 1
										memory[j] = game[row][column];
										rowmemory[j] = row;
										columnmemory[j] = column;
									}
								}						
							}
						}
					}
				}
				check = false;
				check2 = false;
				check3 = false;
			}else{
				return 0;
			}
		}
	}
	return 0;
}
