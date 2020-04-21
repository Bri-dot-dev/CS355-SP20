#include <curses.h>
#include <stdio.h>

int main(){
    initscr();                  // inititalize the curses library
    clear();                    // clear the screen
    curs_set(0);                // hide the cursor
    noecho();                   // do not echo user input to the screen
    keypad(stdscr, TRUE);       // enables workign with the arrow keys
    move(0,0);         
    addstr("Press any key....");
    while(1) {
        int ch = getch();
        switch (ch) {
            case KEY_UP:        // user pressed up arrow key 
                move(0,0);
                addstr("You pressed the UP arrow           ");
                break;
            case KEY_DOWN:      // user pressed down arrow key 
                move(0,0);
                addstr("You pressed the DOWN arrow         ");
                break;
            case KEY_LEFT:      // user pressed left arrow key 
                move(0,0);
                addstr("You pressed the LEFT arrow         ");
                break;
            case KEY_RIGHT:     // user pressed right arrow key 
                move(0,0);
                addstr("You pressed the RIGHT arrow        ");
                break;
            case 'x':           // pressing x or X will exit the program
            case 'X': 
                endwin();       // close curses
                return 0;
            default:
                move(0,0);
                char buf[100];
                sprintf(buf,"You pressed a \"%c\" key, ASCI code %d       ", (char)ch, ch);
                addstr(buf);
                break;
            
        }                
    }
}