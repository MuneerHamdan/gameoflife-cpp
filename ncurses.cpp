#include <ncurses.h>

#define MINY 0
#define MAXY getmaxy(win)
#define MINX 0
#define MAXX getmaxx(win)


void loop(){
  WINDOW* win;
  char c;
  unsigned int y, x;

  win = initscr();
  c = '\0';
  y = getmaxy(win) / 2;
  x = getmaxx(win) / 2;

  do{
//    getyx(win, y, x);
    clear();
    if(c == 'h' && x > MINX)
      x--;
    else if(c == 'j' && y+1 < MAXY)
      y++;
    else if(c == 'k' && y > MINY)
      y--;
    else if(c == 'l' && x+1 < MAXX)
      x++;

    else if(c == 'f')
      mvaddch(y, x, '+');

    mvprintw(0, 0, "%u %u", getmaxy(win), getmaxx(win));
    mvprintw(1, 0, "%u %u", y, x);
    wmove(win, y, x);

    refresh();
  }while((c = getch()) != 'q');
}

int main(void){

  cbreak();
  noecho();

  loop();

  endwin();
  return 0;
}
