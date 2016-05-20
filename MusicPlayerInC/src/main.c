/* This tutorial will open a 640 x 480 screen,
** load an image and display it at specified coordinates.
** Pressing space will play a sound effect and pressing escape
** or closing the window will exit the program
*/

#include "main.h"

extern void init(char *);
extern void cleanup(void);
extern void getInput(void);
extern SDL_Surface *loadImage(char *);
extern Mix_Chunk *loadSound(char *);
extern void updateScreen(void);

int main(int argc, char *argv[])
{
	int go;
	
	/* Start up SDL */
	
	init("Parallel Realities Tutorial 3");
	
	/* Call the cleanup function when the program exits */
	
	atexit(cleanup);
	
	go = 1;
	
	dexterImage = loadImage("gfx/dexter.jpg");
	
	/* If we get back a NULL image, just exit */
	
	if (dexterImage == NULL)
	{
		exit(0);
	}
	
//	dexterBark = loadSound("sound/woof.wav");
	dexterBark = loadSound("sound/bb.mp3");
	
	/* If we get back a NULL sound, just exit */
	
	if (dexterBark == NULL)
	{
		exit(0);
	}
	
	/* Loop indefinitely for messages */
	
	while (go == 1)
	{
		getInput();
		
		updateScreen();
		
		/* Sleep briefly to stop sucking up all the CPU time */
		
		SDL_Delay(16);
	}
	
	/* Exit the program */
	
	exit(0);
}
