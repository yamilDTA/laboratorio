#include"turtlec.h"

void fractalTree( Turtle *turtle, float length , int depth ) {
  if( depth == 0 || length < 5)
    return ;
  turtleForward ( turtle , length ) ;

  turtleLeft ( turtle , 55) ;
  fractalTree ( turtle , length * 0.5 , depth - 1) ;

  turtleRight ( turtle , 55) ;  //esta pone la rama del medio como antes moviamos defrente 60 a la derecha 
  fractalTree ( turtle , length * 0.5 , depth - 1) ;
  
  turtleRight ( turtle , 55) ;
  fractalTree ( turtle , length * 0.5 , depth - 1) ;

  turtleLeft( turtle, 55);  
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
  fractalTree(t , 100 ,4 );
  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;

}
