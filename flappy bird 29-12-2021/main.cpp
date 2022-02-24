#include<glut.h>
#include<iostream>
#include<math.h>

using namespace std;
 
	


/////////flappy bird///////////////////
bool isplaying  = false;
bool iscollided = false;

char text[100]="Game Over";
char text1[100]="Press 's' to Start to play.";
char text2[100]="Press 'r' to play again.";
char text3[100]="Let's go to play Fllapy bird.";

char sc[30]="Score=";

double text_x1 =43 ;  
double delta_text_x1 =0.02 ;  
double text_x3 =41 ;  
double delta_text_x3 =0.02 ;  

int score = 0;
char msg[30];
//////////bird coordinate//////////////
 
double bird_y1=70;
double bird_y2=75;
double bird_x1=20;
double bird_x2=25;

//////////////////
double delta_y = 0.02 ;
double delta_x =0.001 ;  
double level_speed =0.01;
double jump_step =6 ; 

	
////////// four up pipe coordinate////////
int distance_between_two_pip =30;

float pip_up1_x1 = 62 ;
float pip_up1_x2 = 68 ;
///////////////////////
float pip_up2_x1 = 62+distance_between_two_pip ;
float pip_up2_x2 = 68+distance_between_two_pip ;
///////////////////////
float pip_up3_x1 = 62+2*distance_between_two_pip ;
float pip_up3_x2 = 68+2*distance_between_two_pip ;
//////////////////////
float pip_up4_x1 = 62+3*distance_between_two_pip ;
float pip_up4_x2 = 68+3*distance_between_two_pip ;
///////////////////
int pipe_up1_y =50;
int pipe_up2_y =60;
int pipe_up3_y =70;
int pipe_up4_y =80;

/////////four down pipe coordinate//////////////////////

float pip_down1_x1 = 52 ;
float pip_down1_x2 = 58 ;

float pip_down2_x1 = 52+distance_between_two_pip ;
float pip_down2_x2 = 58+distance_between_two_pip ;

float pip_down3_x1 = 52+2*distance_between_two_pip ;
float pip_down3_x2 = 58+2*distance_between_two_pip ;

float pip_down4_x1 = 52+3*distance_between_two_pip ;
float pip_down4_x2 = 58+3*distance_between_two_pip ;

///////////////////
int pipe_down1_y =30;
int pipe_down2_y =40;
int pipe_down3_y =50;
int pipe_down4_y =60;

/////////////////////////////




	  
//////////////functions/////////////////



void init(int argc, char** argv){
	
	glutInit(&argc ,argv);
	glutInitWindowPosition(100,10);
	glutInitWindowSize(1000,600);
	glutCreateWindow("Flappy Bird Game");
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.52940,0.80780,0.9800,0);

	gluOrtho2D(0,100,0,100);
    glPointSize(7);
}

void axisLine(){
	
    glColor3f(0,0,0);
    glLineWidth(30);
    
    glBegin(GL_LINES);
    
    glVertex2f(0.0,10.0);
    glVertex2f(100.0,10.0);
    
    glVertex2f(0.0,90.0);
    glVertex2f(100.0,90.0);
    
	glEnd();	
	
}	  
 
void draw_all_up_pipes(){

/////////pipe up/////////////////
//
//cout<<"pip_up1_x1 : "<<int(pip_up1_x1)<<endl;
//cout<<"pip_up1_x2 : "<<int(pip_up1_x2)<<endl;
//cout<<"pip_up2_x1 : "<<int(pip_up2_x1)<<endl;
//cout<<"pip_up2_x2 : "<<int(pip_up2_x2)<<endl;
//cout<<"pip_up3_x1 : "<<int(pip_up3_x1)<<endl;
//cout<<"pip_up3_x2 : "<<int(pip_up3_x2)<<endl;
//cout<<"pip_up4_x1 : "<<int(pip_up4_x1)<<endl;
//cout<<"pip_up4_x2 : "<<int(pip_up4_x2)<<endl;




/////////////////// pipe_one ///////////////////////	


if(pip_up1_x1 <=0 && pip_up1_x2<=0){
	 pip_up1_x1 = 110 ;
     pip_up1_x2 = 115 ;

}

glColor3f(0.5,0.4,0.1);
glBegin(GL_QUADS);

/////////////// |_| base of pipe/////
glVertex2f(pip_up1_x1-2,90);			
glVertex2f(pip_up1_x2+2,90);
glVertex2f(pip_up1_x2+2,85);
glVertex2f(pip_up1_x1-2,85);

//////////////// pipe ///////////

glVertex2f(pip_up1_x1,90);			
glVertex2f(pip_up1_x2,90);
glVertex2f(pip_up1_x2,pipe_up1_y);
glVertex2f(pip_up1_x1,pipe_up1_y);

glEnd();



/////////////pipe_two////////////////

if(pip_up2_x1 <=0 && pip_up2_x2<=0){
	 pip_up2_x1 = 110 ;
     pip_up2_x2 = 115 ;

}

glColor3f(0.5,0.4,0.1);
glBegin(GL_QUADS);

/////////////// |_| base of pipe/////
glVertex2f(pip_up2_x1-2,90);			
glVertex2f(pip_up2_x2+2,90);
glVertex2f(pip_up2_x2+2,85);
glVertex2f(pip_up2_x1-2,85);

//////////////// pipe ///////////

glVertex2f(pip_up2_x1,90);			
glVertex2f(pip_up2_x2,90);
glVertex2f(pip_up2_x2,pipe_up2_y);
glVertex2f(pip_up2_x1,pipe_up2_y);

glEnd();

/////////////pipe_three////////////////

if(pip_up3_x1 <=0 && pip_up3_x2<=0){
	 pip_up3_x1 = 110 ;
     pip_up3_x2 = 115 ;


}
glColor3f(0.5,0.4,0.1);
glBegin(GL_QUADS);

/////////////// |_| base of pipe/////
glVertex2f(pip_up3_x1-2,90);			
glVertex2f(pip_up3_x2+2,90);
glVertex2f(pip_up3_x2+2,85);
glVertex2f(pip_up3_x1-2,85);

//////////////// pipe ///////////

glVertex2f(pip_up3_x1,90);			
glVertex2f(pip_up3_x2,90);
glVertex2f(pip_up3_x2,pipe_up3_y);
glVertex2f(pip_up3_x1,pipe_up3_y);

glEnd();

/////////////pipe_four////////////////

if(pip_up4_x1 <=0 && pip_up4_x2<=0){
	
	 pip_up4_x1 = 110 ;
     pip_up4_x2 = 115 ;

}
glColor3f(0.5,0.4,0.1);
glBegin(GL_QUADS);

/////////////// |_| base of pipe/////
glVertex2f(pip_up4_x1-2,90);			
glVertex2f(pip_up4_x2+2,90);
glVertex2f(pip_up4_x2+2,85);
glVertex2f(pip_up4_x1-2,85);

//////////////// pipe ///////////

glVertex2f(pip_up4_x1,90);			
glVertex2f(pip_up4_x2,90);
glVertex2f(pip_up4_x2,pipe_up4_y);
glVertex2f(pip_up4_x1,pipe_up4_y);

glEnd();
   
}

void draw_all_down_pipes(){
	
	
/////////////////// pipe_one ///////////////////////	


//cout<<"pipe_down1_y : "<<int(pipe_down1_y)<<endl;
//cout<<"pipe_down2_y : "<<int(pipe_down2_y)<<endl;
//cout<<"pipe_down3_y : "<<int(pipe_down3_y)<<endl;
//cout<<"pipe_down4_y : "<<int(pipe_down4_y)<<endl;

if(pip_down1_x1 <=0 && pip_down1_x2<=0){
	 pip_down1_x1 = 110 ;
     pip_down1_x2 = 115 ;

}

glColor3f(0.5,0.4,0.1);
glBegin(GL_QUADS);

/////////////// |_| base of pipe///
glVertex2f(pip_down1_x1-2,10);			
glVertex2f(pip_down1_x2+2,10);
glVertex2f(pip_down1_x2+2,15);
glVertex2f(pip_down1_x1-2,15);

//////////////// pipe ///////////

glVertex2f(pip_down1_x1,10);			
glVertex2f(pip_down1_x2,10);
glVertex2f(pip_down1_x2,pipe_down1_y);
glVertex2f(pip_down1_x1,pipe_down1_y);

glEnd();



/////////////pipe_two////////////////

if(pip_down2_x1 <=0 && pip_down2_x2<=0){
	 pip_down2_x1 = 110 ;
     pip_down2_x2 = 115 ;

}

glColor3f(0.5,0.4,0.1);
glBegin(GL_QUADS);

/////////////// |_| base of pipe/////
glVertex2f(pip_down2_x1-2,10);			
glVertex2f(pip_down2_x2+2,10);
glVertex2f(pip_down2_x2+2,15);
glVertex2f(pip_down2_x1-2,15);

//////////////// pipe ///////////

glVertex2f(pip_down2_x1,10);			
glVertex2f(pip_down2_x2,10);
glVertex2f(pip_down2_x2,pipe_down2_y);
glVertex2f(pip_down2_x1,pipe_down2_y);

glEnd();

/////////////pipe_three////////////////

if(pip_down3_x1 <=0 && pip_down3_x2<=0){
	 pip_down3_x1 = 110 ;
     pip_down3_x2 = 115 ;


}
glColor3f(0.5,0.4,0.1);
glBegin(GL_QUADS);

/////////////// |_| base of pipe/////
glVertex2f(pip_down3_x1-2,10);			
glVertex2f(pip_down3_x2+2,10);
glVertex2f(pip_down3_x2+2,15);
glVertex2f(pip_down3_x1-2,15);

//////////////// pipe ///////////

glVertex2f(pip_down3_x1,10);			
glVertex2f(pip_down3_x2,10);
glVertex2f(pip_down3_x2,pipe_down3_y);
glVertex2f(pip_down3_x1,pipe_down3_y);

glEnd();



/////////////pipe_four////////////////

if(pip_down4_x1 <=0 && pip_down4_x2<=0){
	 pip_down4_x1 = 110 ;
     pip_down4_x2 = 115 ;


}
glColor3f(0.5,0.4,0.1);
glBegin(GL_QUADS);

/////////////// |_| base of pipe/////
glVertex2f(pip_down4_x1-2,10);			
glVertex2f(pip_down4_x2+2,10);
glVertex2f(pip_down4_x2+2,15);
glVertex2f(pip_down4_x1-2,15);

//////////////// pipe ///////////

glVertex2f(pip_down4_x1,10);			
glVertex2f(pip_down4_x2,10);
glVertex2f(pip_down4_x2,pipe_down4_y);
glVertex2f(pip_down4_x1,pipe_down4_y);

glEnd();
   

	
}

void pipe_movement(){
 	
 	///////////move up pipes /////////
 	
   pip_up1_x1-=level_speed;
   pip_up1_x2-=level_speed;
   pip_up2_x1-=level_speed;
   pip_up2_x2-=level_speed;
   pip_up3_x1-=level_speed;
   pip_up3_x2-=level_speed;
   pip_up4_x1-=level_speed;
   pip_up4_x2-=level_speed;
   
   ////////////move down pipes////////////////

   pip_down1_x1-=level_speed;
   pip_down1_x2-=level_speed;
   pip_down2_x1-=level_speed;
   pip_down2_x2-=level_speed;
   pip_down3_x1-=level_speed;
   pip_down3_x2-=level_speed;
   pip_down4_x1-=level_speed;
   pip_down4_x2-=level_speed;
   
   /////////text movement////
   	text_x1 -= delta_text_x1 ;  
   	text_x3 += delta_text_x3  ;  
 }  

void draw_bird(){

		
		
		glBegin(GL_QUADS);
		
        glColor3f(1.0,0.8,0.0);
	
		glVertex2f(bird_x1,bird_y1);
		glVertex2f(bird_x2,bird_y1);
		glVertex2f(bird_x2,bird_y2);
		glVertex2f(bird_x1,bird_y2);
		
		glEnd();


//    
//    glEnd();
		
//		glBegin(GL_TRIANGLES);{
//		   
//            glColor3f(0.5,0.4,0.1);
//
//			glVertex2f(bird_x2,bird_y1);
//			glVertex2f(bird_x2+1,bird_y1+1.5);
//			glVertex2f(bird_x2,bird_y2-2);
//
//			
//		}
//		glEnd();
//		
//		glColor3f(1,1,1);
//
//		glBegin(GL_LINE_STRIP);
// 		glVertex2f(bird_x2+1,bird_y1+1.5);
// 		glVertex2f(bird_x2,bird_y1+1.5);
//    	glEnd();
//    	
//    	glColor3f(1,0,0);
//
//		glBegin(GL_POINTS);
// 		glVertex2f(bird_x2-1,bird_y2-2);
 	
  //  	glEnd();

}

void bird_movement(){
	
	if(bird_x1>=70.0)
	  {
	  	delta_x =0.0001;
	  	
	  	level_speed +=0.0000001;
	  }
	  	if(score)
	  {
	  	delta_x =0.0001;
	  	
	  	level_speed +=0.0000001;
	  }
	   
	  bird_y1-= delta_y;
	  bird_y2-= delta_y;

      bird_x1+= delta_x;
	  bird_x2+= delta_x;
//	  cout<<"bird_x1 : "<<int(bird_x1) <<endl ;
//	  cout<<"bird_x2 : "<<int(bird_x2) <<endl ;

	  	
	
}

void conditions_to_contenue(){
	
	if(bird_y1 <= 10 || bird_y2 >=90) iscollided =true;
}

void draw_text(const char *text,int length,int x,int y){
   
    glRasterPos2i(x,y);
    for(int i=0;text[i]!='\0';i++)
 {
      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,(int)text[i]);
 }


}

void bird_dead(){

itoa(score/1800,msg,10);//converting score into string
    

if(iscollided){
	 
	isplaying =false; 
		
    ///////game over //////////		
    glColor3f(1,0,0);
    draw_text(text,100,43,50);
    
    ///////score/////////////
	glColor3f(0,.7,0);
	draw_text(sc,100,44,55);
    draw_text(msg,100,50,55);
    ////////press r to restart //////
    glColor3f(1,0,0);
    draw_text(text2,100,40,45);
}
else{
	
	////score /////////
	glColor3f(1,1,0);
	draw_text(sc,100,5,80);
    draw_text(msg,100,12,80);
    
    ////////press s to start //////
    glColor3f(0,.7,0);
    draw_text(text1,100,text_x1,50);
    ////////////
     glColor3f(0.9,0,0);
    draw_text(text3,100,text_x3,60);
}
}

void colligion(){
	
	///////////////collided up pip/////////
	
	if(bird_x1 <= pip_up1_x2 && bird_x2 >= pip_up1_x1 && bird_y2 >= pipe_up1_y )
    iscollided=true;
	else if(bird_x1 <= pip_up2_x2 && bird_x2 >= pip_up2_x1 && bird_y2 >= pipe_up2_y )
	iscollided=true;
	else if(bird_x1 <= pip_up3_x2 && bird_x2 >= pip_up3_x1 && bird_y2 >= pipe_up3_y )
	iscollided=true;
	else if(bird_x1 <= pip_up4_x2 && bird_x2 >= pip_up4_x1 && bird_y2 >= pipe_up4_y )
	iscollided=true;

///////////////////////collided down pip////////////

    else if(bird_x1 <= pip_down1_x2 && bird_x2 >= pip_down1_x1 && bird_y1 <= pipe_down1_y )
	iscollided=true;
	else if(bird_x1 <= pip_down2_x2 && bird_x2 >= pip_down2_x1 && bird_y1 <= pipe_down2_y )
	iscollided=true;
	else if(bird_x1 <= pip_down3_x2 && bird_x2 >= pip_down3_x1 && bird_y1 <= pipe_down3_y )
	iscollided=true;
	else if(bird_x1 <= pip_down4_x2 && bird_x2 >= pip_down4_x1 && bird_y1 <= pipe_down4_y )
	iscollided=true;
	
	else{
		iscollided=false;
	}
	
}

void display(){
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	glClearColor(0.52940,0.80780,0.9800,0);

	//////////functions////////////
    colligion();
    draw_bird();
    draw_all_up_pipes();
    draw_all_down_pipes();
	axisLine();
    bird_movement();
    pipe_movement();
    conditions_to_contenue();
    bird_dead();

    glFlush();

	////////////////////////

if(isplaying ){
	
	score++;

	glutPostRedisplay();
	
	}
}

void special_UP_Key(unsigned char key,int x,int y){
	
	if(isplaying){
	
	if (key==VK_SPACE) {
    	
	 bird_y1 +=jump_step  ;	
	 bird_y2 +=jump_step  ;
	}
}
	
	if(key =='s') {
		isplaying =!isplaying;

	}
	if(key == 'r'){
		isplaying  =true;
        iscollided =true;
        score =0;
pip_up1_x1 = 62 ;
pip_up1_x2 = 68 ;

pip_up2_x1 = 62+distance_between_two_pip ;
pip_up2_x2 = 68+distance_between_two_pip ;

pip_up3_x1 = 62+2*distance_between_two_pip ;
pip_up3_x2 = 68+2*distance_between_two_pip ;

pip_up4_x1 = 62+3*distance_between_two_pip ;
pip_up4_x2 = 68+3*distance_between_two_pip ;
///////////////////
pipe_up1_y =50;
pipe_up2_y =60;
pipe_up3_y =70;
pipe_up4_y =80;
/////////four down pipe coordinate//////////////////////

pip_down1_x1 = 52 ;
pip_down1_x2 = 58 ;

pip_down2_x1 = 52+distance_between_two_pip ;
pip_down2_x2 = 58+distance_between_two_pip ;

pip_down3_x1 = 52+2*distance_between_two_pip ;
pip_down3_x2 = 58+2*distance_between_two_pip ;

pip_down4_x1 = 52+3*distance_between_two_pip ;
pip_down4_x2 = 58+3*distance_between_two_pip ;

///////////////////
pipe_down1_y =30;
pipe_down2_y =40;
pipe_down3_y =50;
pipe_down4_y =60;

/////////////////////////////

level_speed =0.01;;


delta_y = 0.02 ;
delta_x =0.001 ;


//////////bird coordinate//////////////
 
  bird_y1=70;
  bird_y2=75;
  bird_x1=20;
  bird_x2=25;
  	  
        
	}
	glutPostRedisplay();
}


int main(int argc, char** argv) {
    
    
   
	init(argc,argv);
//	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutKeyboardFunc(special_UP_Key);

    glutDisplayFunc(display);


	glutMainLoop();
	
	return 0;
}

