#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int ac, char *av[]) {
    int speed=1;                    // speed of the animation
    if(ac==2)
        speed=atoi(av[1]);          // convert a char* to an int

    initscr();                      // inititalize the curses library
    printf("The screen is %d rows by %d columns", LINES, COLS);
    getchar();                      // pause the program and wait for a keyboard input
    clear();                        // clear the screen
    for(int i=0; i<LINES; i++) {
        move(i, 3*i);               // move the cursor to a position on the diagonal
        addstr("Hello, world!");    // draw a string in the current position
        refresh();                  // update the screen
        usleep(1000000/speed);      // pause the execution
        move(i, 3*i);               // move back
        addstr("             ");    // erase line
    }

    endwin();                       // turn off curses
}