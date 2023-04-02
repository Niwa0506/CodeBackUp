int size_car;
void setup(){
  size(400, 300, P3D);
  noStroke();
  frameRate(30);
}
void leaf(int r,int g,int b){
    fill(r, g, b);
    beginShape(TRIANGLES);
      vertex(0, -.5, 0); vertex(.5, 0, .5); vertex(-.5, 0, .5);
      vertex(0, -.5, 0); vertex(-.5, 0, .5); vertex(-.5, 0, -.5);
      vertex(0, -.5, 0); vertex(-.5, 0, -.5); vertex(.5, 0, -.5);
      vertex(0, -.5, 0); vertex(.5, 0, -.5); vertex(.5, 0, .5);
      vertex(.5, 0, .5); vertex(-.5, 0, -.5); vertex(-.5, 0, .5);
      vertex(.5, 0, .5); vertex(.5, 0, -.5); vertex(-.5, 0, -.5);
    endShape();
  }
void leaves(){
  pushMatrix(); translate(0, -.5, 0); scale(.6, .6, .6); leaf(0, 224, 0); popMatrix();
  pushMatrix(); translate(0, -.25, 0); scale(.8, .8, .8); leaf(0, 192, 0); popMatrix();
  leaf(0, 128, 0);
}
void trunk(){
  fill(128, 64, 0);
  pushMatrix();
    scale(.2, .4, .2);
    translate(0, -.5, 0);
    box(1);
  popMatrix();
}
void frame(color c){
  fill(c);
  //body
  pushMatrix();
      translate(-1,-1.25,0);
      box(8.5,2.5,4);
  popMatrix();
  //yane
  pushMatrix(); 
    translate(0,-2.5,0);
    beginShape(QUADS);
      //hidari
      vertex(3.25,0,-2);vertex(-4,0,-2);
      vertex(-3.5,-1.5,-1.5);vertex(2.5,-1.5,-1.5);
      //mae
      vertex(3.25,0,-2);vertex(3.25,0,2);
      vertex(2.5,-1.5,1.5);vertex(2.5,-1.5,-1.5);
      //migi
      vertex(3.25,0,2);vertex(2.5,-1.5,1.5);
      vertex(-3.5,-1.5,1.5);vertex(-4,0,2);
      //usiro
      vertex(-4,0,2);vertex(-3.5,-1.5,1.5);
      vertex(-3.5,-1.5,-1.5);vertex(-4,0,-2);
      //ue
      vertex(2.5,-1.5,1.5);vertex(2.5,-1.5,-1.5);
      vertex(-3.5,-1.5,-1.5);vertex(-3.5,-1.5,1.5);
    endShape();
  popMatrix();
  //front
  pushMatrix();
    beginShape(QUADS);
      //hidari
      vertex(3.25,0,-2);vertex(4.25,0,-2);
      vertex(5.25,-2,-2);vertex(3.25,-2.5,-2);
      //mae
      vertex(5.25,0,-2);vertex(5.25,0,2);
      vertex(5.25,-2,2);vertex(5.25,-2,-2);
      //migi
      vertex(3.25,0,2);vertex(5.25,0,2);
      vertex(5.25,-2,2);vertex(3.25,-2.5,2);
      //sita
      vertex(5.25,0,2);vertex(5.25,0,-2);
      vertex(3.25,0,-2);vertex(3.25,0,2);
      //ue
      vertex(3.25,-2.5,-2);vertex(3.25,-2.5,2);
      vertex(5.25,-2,2);vertex(5.25,-2,-2);
    endShape();
  popMatrix();
  pushMatrix();
    fill(0);
    translate(0,-2.3,0.5);
    beginShape(QUADS);
      //usiro_l
      vertex(-3.25,-0.2,1.625);vertex(-2.75,-1.4,1.125);
      vertex(-0.3,-1.4,1.125);vertex(-0.3,-0.2,1.625);
      //mae_l
      vertex(-0.1,-1.4,1.125);vertex(-0.1,-0.2,1.625);
      vertex(2.65,-0.2,1.625);vertex(2,-1.4,1.125);
      //front
      vertex(3.4,0,-2.25);vertex(3.4,0,1.25);
      vertex(2.65,-1.5,0.75);vertex(2.65,-1.5,-1.75);
      //usiro_r
      vertex(-3.25,-0.2,-2.625);vertex(-2.75,-1.4,-2.125);
      vertex(-0.3,-1.4,-2.125);vertex(-0.3,-0.2,-2.625);
      //mae_r
      vertex(-0.1,-1.4,-2.125);vertex(-0.1,-0.2,-2.625);
      vertex(2.65,-0.2,-2.625);vertex(2,-1.4,-2.125);
      //usiro
      vertex(-4.125,-0.2,1.25);vertex(-3.625,-1.5,0.75);
      vertex(-3.625,-1.5,-1.75);vertex(-4.125,-0.2,-2.25);
    endShape();
  popMatrix();
}
void wheel(){
  float r =1;
  float length = .5;
  float x,y,z;
    pushMatrix();
      beginShape(TRIANGLE_FAN);
        fill(0);
        z = -length / 2;
        vertex(0, 0, z);
        for(int deg = 0; deg <= 360; deg = deg + 10){
          x = cos(radians(deg)) * r;
          y = sin(radians(deg)) * r;
          vertex(x, y, z);
        }
      endShape(); 
      beginShape(TRIANGLE_FAN);
        fill(255);
        vertex(0, 0, z);
        for(int deg = 0; deg <= 360; deg = deg + 10){
          x = cos(radians(deg)) * r;
          y = sin(radians(deg)) * r;
          vertex(x/2, y/2, z);
        }
      endShape();
      beginShape(TRIANGLE_FAN);
      fill(0);
        z = length / 2;
        vertex(0, 0, z);
        for(int deg = 0; deg <= 360; deg = deg + 10){
          x = cos(radians(deg)) * r;
          y = sin(radians(deg)) * r;
          vertex(x, y, z);
        }
    endShape();
    beginShape(TRIANGLE_FAN);
      fill(255);
        vertex(0, 0, z);
        for(int deg = 0; deg <= 360; deg = deg + 10){
          x = cos(radians(deg)) * r;
          y = sin(radians(deg)) * r;
          vertex(x/2, y/2, z);
        }
    endShape();
    beginShape(TRIANGLE_STRIP);
      fill(0);
      for(int deg =0; deg <= 360; deg = deg + 5){
        x = cos(radians(deg)) * r;
        z = -length / 2;
        y = sin(radians(deg)) * r;
        vertex(x, y, z);
        x = cos(radians(deg)) * r;
        z = length / 2;
        y = sin(radians(deg)) * r;
        vertex(x, y, z);
       }
    endShape();
  popMatrix();
}
void wheels(){
  pushMatrix();
    translate(-3,0,2);
    wheel();
  popMatrix();
 
  pushMatrix();
    translate(3,0,-2);
    wheel();
  popMatrix();
  
  pushMatrix();
    translate(-3,0,-2);
    wheel();
  popMatrix();
  
  pushMatrix();
    translate(3,0,2);
    wheel();
  popMatrix();
}
void drawTree(float s){
    scale(s, s, s);
    trunk();
    translate(0,-.4,0);
    leaves();
}

void drawCar(float s,color c){
  scale(s,s,s);
  frame(c);
  wheels();
  
}
void yane(){
  fill(85,88,89);
  pushMatrix();
    beginShape(QUADS);
      vertex(-.6,0,.6);vertex(-.6,0,-.6);
      vertex(.6,0,-.6);vertex(.6,0,.6);
    endShape();
    beginShape(TRIANGLE);
      vertex(-.6,0,.6);vertex(-.6,0,-.6);vertex(0,-0.6,0);
      vertex(.6,0,-.6);vertex(-.6,0,-.6);vertex(0,-0.6,0);
      vertex(.6,0,.6);vertex(.6,0,-.6);vertex(0,-0.6,0);
      vertex(.6,0,.6);vertex(-.6,0,.6);vertex(0,-0.6,0);
    endShape();
  popMatrix();
}

void body(){
  box(1,1,1);
  pushMatrix();
    translate(0,0,0.525);
    fill(0);
    beginShape(QUADS);
      //mae
      vertex(-0.25,-0.25,0);vertex(-0.01,-0.25,0);
      vertex(-0.01,-0.01,0);vertex(-0.25,-0.01,0);
      
      vertex(0.25,-0.25,0);vertex(0.01,-0.25,0);
      vertex(0.01,-0.01,0);vertex(0.25,-0.01,0);
      
      vertex(0.25,0.25,0);vertex(0.01,0.25,0);
      vertex(0.01,0.01,0);vertex(0.25,0.01,0);
      
      vertex(-0.25,0.25,0);vertex(-0.01,0.25,0);
      vertex(-0.01,0.01,0);vertex(-0.25,0.01,0);
    endShape();
    translate(-0.525,0,-0.525);
    fill(61, 29, 23);
    beginShape(QUADS);  
      vertex(0,-0.25,0.25);vertex(0,0.5,0.25);
      vertex(0,0.5,-0.25);vertex(0,-0.25,-0.25);
    endShape();
    translate(0,0.125,-0.24);
    fill(255);
    beginShape(TRIANGLE);
      for(int i=0;i<TWO_PI;i++){
        vertex(0,0.05*sin(i),0.05*cos(i));
        vertex(0,0.05*sin(i+1),0.05*cos(i+1));
        vertex(0,0,0);
      }
    endShape();
  popMatrix();
}
void drawHouse(float s,color c){
  fill(c);
  scale(s,s,s);
  translate(0,-.4,0);
  body();
  translate(0,-.5,0);
  yane();
}
int k=0;
void keyPressed(){
  if(key =='A'||key =='a'){
     k=0;
  }else if(key =='G'||key=='g'){
     k=1;
  }else if(key =='F'||key=='f'){
     k=2;
  }else if(key =='D'||key=='d'){
     k=3;
  }
}
int i=0,n=1;
void draw(){
  background(137,189,222);
  lights(); 
  if(k==0)
    camera(width/2+i, height/2, 400, width/2+i, height/2, 0, 0.0, 1.0, 1.0);
  else if(k==1)
    camera(width/2+i+width/3*2, height/2, 100, width/2+i, height/2, 100,-1.0, 1.0, 0);
  else if(k==2)
    camera(width/2+i-width/3*2, height/2, 100, width/2+i, height/2, 100,1.0, 1.0, 0);
  else
    camera(width/2+i, height/2, -300, width/2+i, height/2, 0, 0.0, 1.0, 1.0);
  for(int j=0;j<=n;j++){
    pushMatrix();
    fill(147,103,67);
      translate(width*j,height,0);
      box(2*width,(height-170)*2,1000);
      fill(255);
      
    popMatrix();
    pushMatrix();
      translate(100+width*j,170,-12.5);
      drawTree(100);
    popMatrix();
    pushMatrix();
      translate(250+width*j,170,-25);
      if(j%2==0)drawHouse(90,color(255,0,0));
      else if(j%3==0)drawHouse(90,color(0,255,0));
      else drawHouse(90,color(0,0,255));
    popMatrix();
  }
  pushMatrix();
    translate(width/2+i,/*height/2+50*/156.5,100);
    fill(204,204,204);
    pushMatrix();
    translate(0,12.5,0);
    box(width*2,2,100);
    popMatrix();
    translate(75,0,0);
    drawCar(12.5,color(0,0,255));
  popMatrix();
  pushMatrix();
    translate(width/2+i-75,/*height/2+50*/156.5,100);
    drawCar(12.5,color(255,0,0));
  popMatrix();
  i++;
  if(i%(width/2)==0)n++;
}
