#include <stdio.h>

int running = 1;
int seatsSold = 0;


struct seat{
  char name[100];
  int type;
  int seatCost;
  int seat;
  

};

struct seat seats[10];

void seatMap()
{
  printf("\nSEAT AVAILBILITY\n");
  printf("([*] Sold\n");
  printf("([ ] Empty\n\n");
  for (int loopIndex = 0; loopIndex < (sizeof(seats) / sizeof(seats[0])); loopIndex++)
  {
    if((loopIndex) %2 == 0)
    {
      if(seats[loopIndex].seatCost > 0)
      {
        printf("[*]\t");
      }
      else
      {
        printf("[ ]\t");
      }
    }
    if((loopIndex) %2 == 1)
    {
     if(seats[loopIndex].seatCost > 0)
      {
        printf("[*]\n");
      }
      else
      {
        printf("[ ]\n");
      } 
    }
  }
}

int seatCoster(int type)
{
  int cost;
	if(type == 1)
  {
    cost =  100 *1.2;
  }
		
	if(type == 2)
  {
    cost =  100 *1;
  }
	
  if(type == 3)
  {
    cost =  100 *1.1;
  }
		
	return cost;

}

int mainMenu()
{
  int choice = 0;
  printf("-------------------------------------");
  printf("\nMAIN MENU\n");
  printf("\n\t1. Book a seat\n");
  printf("\t2. Display all available seats\n");
  printf("\t3. Display all passengers\n");
  printf("\t4. Exit program\n");
  printf("choice: ");
  scanf("%d", &choice);


  return choice;
}

void bookASeat()
{
  printf("\033[0;0H\033[2J");
  int choice = 0;
  printf("-------------------------------------");
  printf("\nBOOK A SEAT\n");
  
  printf("\nWhat Seat would You like");
  seatMap();
  printf("choice: ");
  int validSeatNumber =0;
  while(validSeatNumber == 0)
    {
      choice = 0;
      scanf("%d", &choice);
      if(seats[choice -1].seatCost >0)
      {
        printf("\nPlease pick and empty seat\n\n");
        printf("choice: ");
      }

      else
      {
        seats[choice -1].seat = choice;
        validSeatNumber =1;
      }
    }
  
  seats[seatsSold].seat = seatsSold;
  
  if(seatsSold == 10)
  {
    printf("\nOut of Seats");
    return;
  }
  printf("\nWhat is customer name: ");
  scanf("%s", &seats[choice-1].name);
  
  printf("\nWhat type is the customer");
  printf("\n\t1. Busines class\n");
  printf("\t2. Local\n");
  printf("\t3. pleasure\nchoice:");
  scanf("%d", &seats[choice-1].type);
  
  seats[choice-1].seatCost = seatCoster(seats[choice-1].type);
  printf("\nThe Seat will cost: £ %d\n", seats[choice-1].seatCost);

  
  
  seatsSold = seatsSold +1;
}

void displayAllAvailableSeats()
{
  printf("\033[0;0H\033[2J");
  printf("-------------------------------------");
  printf("\nSEAT AVAILBILITY\n");
  seatMap();
    
  
}

void displayAllPassangers()
{
  printf("\033[0;0H\033[2J");
  printf("-------------------------------------");
  printf("\nALL PASSENGERS\n");
  for (int loopIndex = 0; loopIndex < (sizeof(seats) / sizeof(seats[0])); loopIndex++) 
    {
      
      if(seats[loopIndex].seatCost > 0)
      {
        printf("\n Passneger %d",loopIndex+1);
        printf("\n Name : %s",seats[loopIndex].name);
        printf("\n Class : %d",seats[loopIndex].type);
        printf("\n Cost : £%d",seats[loopIndex].seatCost);
        printf("\n Seat number : %d\n",loopIndex+1);
      }
      
    }
}


void main(void) 
{
  printf("\033[0;0H\033[2J");
  int choice = 0;
  while(running == 1)
    {
      choice = mainMenu();
      
      if(choice == 1)
      {
        bookASeat();
      }

       else if(choice == 2)
      {
        displayAllAvailableSeats();
      }

       else if(choice == 3)
      {
        displayAllPassangers();
      }

       else if(choice == 4)
      {
        running = 0;
      }
    }
}
