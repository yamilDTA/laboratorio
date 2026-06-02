#include"turtlec.h"

void fractalTree( Turtle *turtle, float length , int depth ) {
  if( depth == 0 || length < 1)
    return ;
  
  if( depth > 5){
	  turtleSetColor ( turtle , 120 , 70 , 20) ; //marron
  }else if (depth >2){
	  turtleSetColor ( turtle , 100 ,255, 100);  //verde mas claro
  }else{
	  turtleSetColor ( turtle , 255 , 100 , 0) ;  //naranja
  }
  
  turtleForward ( turtle , length ) ;

  turtleLeft ( turtle , 45) ;
  fractalTree ( turtle , length * 0.6 , depth - 1) ;

  turtleRight ( turtle , 90) ;
  fractalTree ( turtle , length * 0.6 , depth - 1) ;
  
  turtleLeft( turtle, 45);

turtlePenUp(turtle);
turtleBackward ( turtle , length ) ;
turtlePenDown (turtle);
	
}


int main(void){
  TurtleApp *app=turtleAppCreate(1000,600,"test line");
  if(app==NULL)
    return 1;
  Turtle *t = turtleAppGetTurtle(app);
  turtlePenUp(t);
  turtleGoTo(t,500.0f,550.0f);
  turtlePenDown(t);
  turtleSetColor(t,128,64,0);
  turtleSetSpeed(t,8.0f);
  turtleLeft(t,90.0f);
  fractalTree(t , 200 ,8 );
  turtleAppRun(app);
  turtleAppDestroy(app);
  return 0;

}
