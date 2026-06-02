# include <math.h>
# include "turtlec.h"

void levy( Turtle *turtle , float length , int depth ) {
	if( depth == 0) {
		turtleForward ( turtle , length ) ;
		return ;
	}
	turtleLeft ( turtle , 45) ;
	levy ( turtle , length / sqrt (2) , depth - 1) ;
	turtleRight ( turtle , 90) ;
	levy ( turtle , length / sqrt (2) , depth - 1) ;
	turtleLeft ( turtle , 45) ;
}

int main(void){
  TurtleApp *app=turtleAppCreate(1200,600,"test line");
  if(app==NULL)
    return 1;
  Turtle *t = turtleAppGetTurtle(app);
  turtlePenUp(t);
  turtleGoTo(t,500.0f,350.0f);
  turtlePenDown(t);
  turtleSetColor(t,255,100,0);
  turtleSetSpeed(t,8.0f);
  levy(t , 200 ,6 );
  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;

}

