#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
int playernumber;
int score[5];
char *menu[] = {"Kebab", "Burger", "Pasta", "Lahmacun", "Salad"};
short threshold = 85;
int point;

void controllingThreshold(int score[], char *menu[]);
void initializeScore(void);
int arr_length(void);


int main(void) {
    initializeScore();
    printf("Please Enter the Player Number: ");
    scanf("%d", &playernumber);

    

    for (int player = 1; player <= playernumber; player++) {

         printf("Player %d is playing. \n", player);
         printf("What is your preference?\n");
         printf("0:Kebab  1:Burger  2:Pasta 3:Lahmacun 4:Salad\n");
          point = 50;
          int check = 0;
          int checing[5];
          for (int i = 0; i < 5; i++)
          {
            checing[i] = 0;
          }
          
          while (check < 5)
          {
            int choosing;
            printf("Enter the menu choice for Player %d: ", player);
            scanf("%d", &choosing);
            if(checing[choosing]==1){
                printf("You cannot select the food more than once \n");
        
            }else if (choosing >= 5)
            {
                printf("You need to select between 0 and 4 \n");
            }
            else {
            checing[choosing] = 1;
            score[choosing] += point;
            point -= 10;
            check++;
            }



            
          }
          
        



        
    }
      
  int preth= 0;
    for(int i = 0; i < 5; i++) {
        if(score[i] >= threshold) {
            preth++;
        }
    }

    if(preth == 0){
        printf("You are eating at home/dorm today!");
        exit(0);
    }else if(preth == 1){
        for (int i = 0; i < 5; i++)
        {
            if(score[i]>= threshold){
                printf("%s WON   ", menu[i]);
                exit(0);
            }
        }
        
    }
    char *shortlist[preth];
    int score2[preth];
     for (int i = 0; i < preth; i++) {
        score2[i] = 0;
    }
   int index = 0;
    for(int i = 0; i < 5; i++) {
        if(score[i] > threshold) {
           shortlist[index] = malloc(strlen(menu[i]) + 1);
            strcpy(shortlist[index], menu[i]);
            index++;
        }
    }
    printf("--------------------------\n");
printf("Round 2 \n");

     
    for (int player = 1;  player<=playernumber; player++)
    {
        printf("Shortlist of Food\n");
     for (int i = 0; i <preth; i++)
     {
        printf(" %d: %s", i, shortlist[i]);
        
     }
     printf("\n");
        printf("Player %d is playing. \n", player);
         printf("What is your preference?\n");

         point=25;
          int check = 0;
          int checing[preth];
           for (int i = 0; i < preth; i++)
          {
            checing[i] = 0;
          }

        
          
          while (check <sizeof(checing) / sizeof(checing[0]) )
          {
            int choosing;
            printf("Enter the menu choice for Player %d: ", player);
            scanf("%d", &choosing);
            if(checing[choosing]==1){
                printf("You cannot select the food more than once \n");
        
            }else if (choosing >= preth)
            {
            printf("You need to select between 0 and %d \n", preth-1);
            }
            else {
            checing[choosing] = 1;
            score2[choosing] += point;
            point -= 10;
            point+=1;
            check++;
            }
          }
    }
     int maximum = 0;
     int index2 = 0;
     for (int i = 0; i < preth; i++)
     {
        if(score2[i] > maximum){
            maximum = score2[i];
            index2 = i;
        }
     }

     

printf("%s WON   ", shortlist[index2]);


    return 0;
}






void initializeScore(void) {
    for (int i = 0; i < 5; i++) {
        score[i] = 0;
    }
}



