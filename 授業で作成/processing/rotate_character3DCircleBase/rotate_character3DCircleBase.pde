int angle=0,n=0;
void setup(){
  size(400, 300, P3D);
  smooth();
  frameRate(30);
  textFont(createFont("Tempus Sans ITC", 24));
}
void draw(){
   background(255);
   pushMatrix();
     translate(200, 150, -50);
     rotateX(map(mouseY, 0, height, PI, -PI));
     rotateY(map(mouseX, 0, width, -PI, PI));
     drawz();
     fill(0, 0, 0, 255);
     String s ="Visual Computing";
     float r = 2 * textWidth(s) / PI, theta = PI / s.length();
     angle++;
     for(int i = 0; i < s.length(); i++){
       pushMatrix();
         translate(-r * cos(theta * i+angle), -r * sin(theta * i+angle), 0);
         rotateZ(theta * i - PI / 2);
         text(s.charAt(i), 0, 0, 0);
       popMatrix();
     }
   popMatrix();
}

void drawz(){
  if(n==0){
    drawAxis('X',color(255,0,0));
    drawAxis('Y',color(0,255,0));
    drawAxis('Z',color(0,0,255));
  }else{
    drawGrid('X',color(255,0,0,120));
    drawGrid('Y',color(0,255,0,120));
    drawGrid('Z',color(0,0,255,120));
  }
}
void keyPressed(){
  if(key =='A'||key =='a'){
     n=0;
  }else if(key =='G'||key=='g'){
     n=1;
  }
}

void drawAxis(char s, color c){
  fill(c);
  pushMatrix();//draw axis
    switch(s){
      case'X': box(200,1,1);break;
      case'Y': box(1,200,1);break;
      case'Z': box(1,1,200);break;
    }
  popMatrix();
  pushMatrix();
    switch(s){
      case'X': translate(100,0,0);break;
      case'Y': translate(0,100,0);break;
      case'Z': translate(0,0,100);break;
    }
    sphere(3);//draw positive axis
    text(s,5,0,0);
  popMatrix();
}

void axis(char s, color c){
   int len = 200;
   fill(c);
   stroke(c);
   box(len, 1, 1);
   pushMatrix();
   translate(len / 2, 0, 0);
   sphere(3);
   text(s, 5, -5, 0);
   popMatrix();
   pushMatrix();
   translate(0, -len / 2, -len / 2);
   int ngrids = 20;//#ofgrid
   int xs = len / ngrids, ys = len / ngrids;//gridinterval
   for(int i = 1; i < ngrids; i++){
      line(0, 0, ys * i, 0, len, ys * i);//horizontalgrid
      line(0, xs * i, 0, 0, xs * i, len);//verticalgrid
    }
    popMatrix();
}
void drawGrid(char s, color c){
   switch(s){
      case'X':axis(s, c);break;
      case'Y':pushMatrix();rotateZ(PI / 2);axis(s, c);popMatrix();break;
      case'Z':pushMatrix();rotateY(-PI / 2);axis(s, c);popMatrix();break;
   }
}
