/********************************************************************


HUMAN PERCEPTION OF SOUND - Psychoacoustic Test Program

CODE LISTING

This is a program which plays a series of five notes with different pitch and timbre settings. The user can adjust the duration of the notes (tempo) and the timbre of the notes at will


********************************************************************/



/************************ Library Declarations **************************/


#include "midi_lib.h"				/* Include required Libraries 		*/
#include <stdio.h>				/* Include required Libraries 		*/


/*******************************************************************/



/************************ Function Declarations *************************/


void play_sequence(int);			/* Plays the sequence 			*/
int paint_menu();				/* Paints the User Menu 		*/
void change_timbres();			/* Changes timbre values		*/ 
void change_duration();			/* Changes pause duration step 	*/ 


/*******************************************************************/



/********************** Global Variable Declarations *********************/


int timbre_list[4]={40,68,125,85};		/* Table - stores the timbre values 	*/
int pause_counter=500;			/* Initial note duration value  		*/
int pause_step=50; 				/* Duration change step value		*/
char keyboard_input='p';			/* Stores the keyboard key pressed  	*/


/*******************************************************************/
/*************************** Main Function ****************************/

void main(){

int cntr=1;					/* This variable stores the user's choice*/		

while(cntr!=0){	/* Checks the user's choice and …	   */						

		cntr=paint_menu();		/* …calls the relevant function.   	   */		if(cntr==1) {			/*					   */
			play_sequence(50);	/*					   */
		}else if(cntr==2){		/*					   */
			change_timbres();	/*					   */
		}else if(cntr==3){		/*					   */
			change_duration();	/*					   */
		}				/********************************/

	}

}

/*****************************End of Function**************************/



/*******Paint Menu Function - Draws the user menu/Returns user's choice********/

int paint_menu(){

int choice=0;				         /* This variable stores the user's choice*/

	printf("\n\n\n\n\n*****HPS PROGRAM MENU*****");	/* This block 	*/
	printf("\n\n1.Play Sequence\n");				/* paints the	*/
	printf("2.Change Timbres\n");				/* MENU and	*/
	printf("3.Change Note Duration Step \n");			/* accepts a	*/
	printf("0.Exit");						/* value from	*/
	printf("\n\n\n**************************");		/* the user.	*/
	printf("\n\n\n\nChoice: ");					/*		*/
	scanf("%d", &choice);					/*************/
	
	return choice;							/* Sends value	*/
									/* to caller	*/
}

/*****************************End of Function**************************/
 
/*Playback Function - Accepts an integer as starting note value and plays sequence*/

void play_sequence(int start_note){

int i, note, timbre_count=0; 			

keyboard_input='p'; 					  /*Key press variable               */
printf("\n\n\nNote Duration = %d", pause_counter); /*Prints playback details and  */
printf("\n\nControls: i=Increase Speed, d=Decrease Speed, s=Stop");/*user key info*/
	
/* This loop plays the sequence with the selected values of timbres/duration step      */

while((keyboard_input!='s')){			            	/*Checks stop status      */
			
    for(i=start_note;i<=start_note+4;i++){ 	           	 	/*Counts sequence steps*/
			
        if(i==start_note) note=start_note;	           		/*Sets the starting note  */
        if(i==start_note+3) note+=1; else note+=2;      		/*Checks semitone step */
        program_change(1,timbre_list[timbre_count]); 		/*Sets the timbre            */
        if(timbre_count==3) timbre_count=0; else timbre_count++; /* Loops timbres   */
		midi_note(note,1,64);		          			/*Plays the note	   */
        pause(pause_counter);					/*Pause             	   */  
        midi_note(note,1,0);					/*Stops the note	   */											
    }	

/*This loop changes the pause duration according to the user input                             */
		
    if(qwerty_input()){						/*Checks if key is press */
	
        keyboard_input=input_char();				/*Accepts pressed key   */

/*This if statement Increases/Decreases the pause step according to the keys pressed*/

        if((keyboard_input=='i') && (pause_counter>pause_step+5)) printf("\n\n\nNote Duration Changed to: %d msec\n",     
        pause_counter-=pause_step);

        else if(keyboard_input=='d') printf("\n\n\nNote Duration Changed to: %dmsec\n", pause_counter+=pause_step);

        printf("\n\nControls: i=Increase Speed, d=Decrease Speed, s=Stop");

    }

}
	
}

/*****************************End of Function**************************/


/* Change Timbre Function - Changes the timbres of the 4 different sounds of the sequence */

void change_timbres(){

	int table_position;

	for(table_position=0; table_position<4; table_position++){				/* Fills the table with timbre values */

		printf("\n\nEnter new timbre value for note %d:", table_position+1);		/* Fills the table with timbre values */
		scanf("%d", &timbre_list[table_position]);					/* Fills the table with timbre values */
	
	}

}

/* Change Duration Function - Changes the step duration of the notes of the sequence */

void change_duration(){

	printf("\n\n\nEnter new note duration step (in msec):");					/* Sets the duration of the notes     */
	scanf("%d", &pause_step);								/* Sets the duration of the notes     */
	
}
