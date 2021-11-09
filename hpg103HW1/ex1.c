#include <stdio.h>

main()
{
int binaryNumb = 1;

int i;

int input;

int count;

char binary[] = "0000000000000000"; //this array represents all 16 total bits in their initial
// state


int cond = 1;

        while(cond != 0)
        {
                scanf("%d", &input); //read in the input of binary numbers.
				
                if(input == 0)
                cond = 0;
			
			
                for(i=15; i>-1; i--) //since there is 16 total bits.
                {
                        binary[i] = (input & 1) + '0'; 
					
                        input >>= 1;
						
						
                }
                for(i=0; i<16; i++)
                {
						if (i % 4 == 0 && i != 0) {
							printf(" ");
						}
                        printf("%c", binary[i]);
						
						
                }
				
				
				
				
                puts(""); //writes the string of binary numbers to the output, not including
				//the null character.
				
        }

}

