#include"turtlec.h"

void fractalTree( Turtle *turtle, float length , int depth ) {
  if( depth == 0 || length < 5)
    return ;
  turtleForward ( turtle , length ) ;

  turtleLeft ( turtle , 30) ;
  fractalTree ( turtle , length * 0.7 , depth - 1) ;

  turtleRight ( turtle , 30) ;
  fractalTree ( turtle , length * 0.7 , depth - 1) ;
  
  turtleRight ( turtle , 30) ;
  fractalTree ( turtle,  length*0.7, depth - 1);
  
  turtleLeft( turtle, 30);  
  turtleBackward ( turtle , length ) ;
  
}


int main(void){
  TurtleApp *app=turtleAppCreate(1200,600,"test line");
  if(app==NULL)
    return 1;
  Turtle *t = turtleAppGetTurtle(app);
  turtlePenUp(t);
  turtleGoTo(t,600.0f,550.0f);
  turtlePenDown(t);
  turtleSetColor(t,255,100,0);
  turtleSetSpeed(t,5.0f);
  turtleLeft(t,90.0f);
  fractalTree(t , 80 ,7 );
  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;

}
