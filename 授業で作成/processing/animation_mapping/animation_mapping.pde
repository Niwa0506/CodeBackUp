PImage img1,img2,img3,img4;
void setup(){
  size(400, 300, P3D);
  img1 = loadImage("as.jpg");
  img2 = loadImage("check.png");
  img3 = loadImage("penguin.jpg");
  img4 = loadImage("oozora.jpg");
  img1.resize(200,200);
  img2.resize(200,200);
  img3.resize(200,200);
  noStroke();
  frameRate(30);
}
void leaf(int r,int g,int b){
    fill(r, g, b);
    beginShape(TRIANGLES);
      textureMode(NORMAL);
      texture(img1);
      vertex(0, -.5, 0,.5,0); vertex(.5, 0, .5,0,1); vertex(-.5, 0, .5,1,1);
      vertex(0, -.5, 0,.5,0); vertex(-.5, 0, .5,0,1); vertex(-.5, 0, -.5,1,1);
      vertex(0, -.5, 0,.5,0); vertex(-.5, 0, -.5,0,1); vertex(.5, 0, -.5,1,1);
      vertex(0, -.5, 0,.5,0); vertex(.5, 0, -.5,0,1); vertex(.5, 0, .5,1,1);
      vertex(.5, 0, .5,.5,0); vertex(-.5, 0, -.5,0,1); vertex(-.5, 0, .5,1,1);
      vertex(.5, 0, .5,.5,0); vertex(.5, 0, -.5,0,1); vertex(-.5, 0, -.5,1,1);
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
    beginShape(QUADS);
      textureMode(NORMAL);
      texture(img3);
      vertex(-.5,-.5,.5,0,0);vertex(-.5,.5,.5,0,1);
      vertex(.5,.5,.5,1,1);vertex(.5,-.5,.5,1,0);
      
      vertex(.5,-.5,.5,0,0);vertex(.5,.5,.5,0,1);
      vertex(.5,.5,-.5,1,1);vertex(.5,-.5,-.5,1,0);
      
      vertex(.5,-.5,-.5,0,0);vertex(.5,.5,-.5,0,1);
      vertex(-.5,.5,-.5,1,1);vertex(-.5,-.5,-.5,1,0);
      
      vertex(-.5,-.5,-.5,0,0);vertex(-.5,.5,-.5,0,1);
      vertex(-.5,.5,.5,1,1);vertex(-.5,-.5,.5,1,0);
    endShape();
  popMatrix();
}
void frame(color c){
  fill(c);
  //body
  pushMatrix();
      translate(-1,-1.25,0);
      textureMode(NORMAL);
      beginShape(QUADS);
        texture(img2);
        vertex(-4.25,1.25,-2,0,0);vertex(4.25,1.25,-2,0,1);
          vertex(4.25,-1.25,-2,1,1);vertex(-4.25,-1.25,-2,1,0);
        vertex(4.25,1.25,-2,0,0);vertex(4.25,1.25,2,0,1);
          vertex(4.25,-1.25,2,1,1);vertex(4.25,-1.25,-2,1,0);
        vertex(-4.25,1.25,-2,0,0);vertex(-4.25,1.25,2,0,1);
          vertex(-4.25,-1.25,2,1,1);vertex(-4.25,-1.25,-2,1,0);
        vertex(-4.25,1.25,2,0,0);vertex(4.25,1.25,2,0,1);
          vertex(4.25,-1.25,2,1,1);vertex(-4.25,-1.25,2,1,0);
        vertex(-4.25,1.25,-2,0,0);vertex(4.25,1.25,-2,0,1);
          vertex(4.25,1.25,2,1,1);vertex(-4.25,1.25,2,1,0);
        vertex(-4.25,-1.25,-2,0,0);vertex(4.25,-1.25,-2,0,1);
          vertex(4.25,-1.25,2,1,1);vertex(-4.25,-1.25,2,1,0);
      endShape();
  popMatrix();
  //yane
  pushMatrix(); 
    translate(0,-2.5,0);
    beginShape(QUADS);
      textureMode(NORMAL);
      texture(img2);
      //hidari
      vertex(3.25,0,-2,0,0);vertex(-4,0,-2,0,1);
      vertex(-3.5,-1.5,-1.5,1,1);vertex(2.5,-1.5,-1.5,1,0);
      //mae
      vertex(3.25,0,-2,0,0);vertex(3.25,0,2,0,1);
      vertex(2.5,-1.5,1.5,1,1);vertex(2.5,-1.5,-1.5,1,0);
      //migi
      vertex(3.25,0,2,0,0);vertex(2.5,-1.5,1.5,0,1);
      vertex(-3.5,-1.5,1.5,1,1);vertex(-4,0,2,1,0);
      //usiro
      vertex(-4,0,2,0,0);vertex(-3.5,-1.5,1.5,0,1);
      vertex(-3.5,-1.5,-1.5,1,1);vertex(-4,0,-2,1,0);
      //ue
      vertex(2.5,-1.5,1.5,0,0);vertex(2.5,-1.5,-1.5,0,1);
      vertex(-3.5,-1.5,-1.5,1,1);vertex(-3.5,-1.5,1.5,1,0);
    endShape();
  popMatrix();
  //front
  pushMatrix();
    beginShape(QUADS);
      textureMode(NORMAL);
      texture(img2);
      //hidari
      vertex(3.25,0,-2,0,0);vertex(4.25,0,-2,0,1);
      vertex(5.25,-2,-2,1,1);vertex(3.25,-2.5,-2,1,0);
      //mae
      vertex(5.25,0,-2,0,0);vertex(5.25,0,2,0,1);
      vertex(5.25,-2,2,1,1);vertex(5.25,-2,-2,1,0);
      //migi
      vertex(3.25,0,2,0,0);vertex(5.25,0,2,0,1);
      vertex(5.25,-2,2,1,1);vertex(3.25,-2.5,2,1,0);
      //sita
      vertex(5.25,0,2,0,0);vertex(5.25,0,-2,0,1);
      vertex(3.25,0,-2,1,1);vertex(3.25,0,2,1,0);
      //ue
      vertex(3.25,-2.5,-2,0,0);vertex(3.25,-2.5,2,0,1);
      vertex(5.25,-2,2,1,1);vertex(5.25,-2,-2,1,0);
    endShape();
  popMatrix();
  pushMatrix();
    fill(0);
    translate(0,-2.3,0.5);
    beginShape(QUADS);
    textureMode(NORMAL);
    texture(img1);
      //usiro_l
      vertex(-3.25,-0.2,1.625,1,1);vertex(-2.75,-1.4,1.125,0,1);
      vertex(-0.3,-1.4,1.125,0,0);vertex(-0.3,-0.2,1.625,1,0);
      //mae_l
      vertex(-0.1,-1.4,1.125,1,1);vertex(-0.1,-0.2,1.625,0,1);
      vertex(2.65,-0.2,1.625,0,0);vertex(2,-1.4,1.125,1,0);
      //front
      vertex(3.4,0,-2.25,1,1);vertex(3.4,0,1.25,0,1);
      vertex(2.65,-1.5,0.75,0,0);vertex(2.65,-1.5,-1.75,1,0);
      //usiro_r
      vertex(-3.25,-0.2,-2.625,1,1);vertex(-2.75,-1.4,-2.125,0,1);
      vertex(-0.3,-1.4,-2.125,0,0);vertex(-0.3,-0.2,-2.625,1,0);
      //mae_r
      vertex(-0.1,-1.4,-2.125,1,1);vertex(-0.1,-0.2,-2.625,0,1);
      vertex(2.65,-0.2,-2.625,0,0);vertex(2,-1.4,-2.125,1,0);
      //usiro
      vertex(-4.125,-0.2,1.25,1,1);vertex(-3.625,-1.5,0.75,0,1);
      vertex(-3.625,-1.5,-1.75,0,0);vertex(-4.125,-0.2,-2.25,1,0);
    endShape();
  popMatrix();
}
void wheel(){
  float r =1;
  float length = .5;
  float x1,y1,z,x2,y2;
  z = length / 2+.125;
    pushMatrix();
      rotateZ(radians(i*2));
      beginShape(TRIANGLE);
        textureMode(NORMAL);
        texture(img4);
        fill(0);
        for(int deg = 0; deg < 360; deg++){
          x1 = cos(radians(deg));
          y1 = sin(radians(deg));
          x2 = cos(radians(deg+1));
          y2 = sin(radians(deg+1));
          vertex(0, 0, z,.5,.5);
          vertex(r*x1, r*y1, z,.5*x1,.5*y1);
          vertex(r*x2, r*y2, z,.5*x2,.5*y2);
          
          vertex(0, 0, -z,.5,.5);
          vertex(r*x1, r*y1, -z,.5*x1,.5*y1);
          vertex(r*x2, r*y2, -z,.5*x2,.5*y2);
        }
      endShape(); 
      beginShape(TRIANGLE);
        fill(255);
        for(int deg = 0; deg < 360; deg++){
          x1 = cos(radians(deg));
          y1 = sin(radians(deg));
          x2 = cos(radians(deg+1));
          y2 = sin(radians(deg+1));
          vertex(0, 0, z);
          vertex(r*x1/2, r*y1/2, z);
          vertex(r*x2/2, r*y2/2, z);
          
          vertex(0, 0, -z);
          vertex(r*x1/2, r*y1/2, -z);
          vertex(r*x2/2, r*y2/2, -z);
        }
      endShape();
      beginShape(QUADS);
        textureMode(NORMAL);
        texture(img4);
        //fill(0);
        float x = .0;
        for(int deg = 0; deg < 360; deg++){
          x1 = cos(radians(deg));
          y1 = sin(radians(deg));
          x2 = cos(radians(deg+1));
          y2 = sin(radians(deg+1));
          vertex(r*x1, r*y1, z,x,0);
          vertex(r*x2, r*y2, z,x+.003,0);
          vertex(r*x2, r*y2, -z,x+.003,1);
          vertex(r*x1, r*y1, -z,x,1);
          x+=.003;
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
      textureMode(NORMAL);
      texture(img1);
      vertex(-.6,0,.6,0,1);vertex(-.6,0,-.6,1,1);vertex(0,-0.6,0,0.5,0);
      vertex(.6,0,-.6,0,1);vertex(-.6,0,-.6,1,1);vertex(0,-0.6,0,0.5,0);
      vertex(.6,0,.6,0,1);vertex(.6,0,-.6,1,1);vertex(0,-0.6,0,0.5,0);
      vertex(.6,0,.6,0,1);vertex(-.6,0,.6,1,1);vertex(0,-0.6,0,0.5,0);
    endShape();
  popMatrix();
}

void body(){
  pushMatrix();
    beginShape(QUADS);
      textureMode(NORMAL);
      texture(img2);
      //-x
      vertex(-0.5,-0.5,-0.5,0,0);vertex(-0.5,-0.5,0.5,1,0);
      vertex(-0.5,0.5,0.5,1,1);vertex(-0.5,0.5,-0.5,0,1);
      //-z
      vertex(-0.5,-0.5,-0.5,0,0);vertex(0.5,-0.5,-0.5,1,0);
      vertex(0.5,0.5,-0.5,1,1);vertex(-0.5,0.5,-0.5,0,1);
      //+x
      vertex(0.5,-0.5,-0.5,0,0);vertex(0.5,-0.5,0.5,1,0);
      vertex(0.5,0.5,0.5,1,1);vertex(0.5,0.5,-0.5,0,1);
      //+z
      vertex(-0.5,-0.5,0.5,0,0);vertex(0.5,-0.5,0.5,1,0);
      vertex(0.5,0.5,0.5,1,1);vertex(-0.5,0.5,0.5,0,1);
    endShape();
  popMatrix();
  pushMatrix();
    translate(0,0,0.525);
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

void set_camera(){
  if(k==0)
    camera(width/2+i, height/2, 400, width/2+i, height/2, 0, 0.0, 1.0, 1.0);
  else if(k==1)
    camera(width/2+i+width/3*2, height/2, 100, width/2+i, height/2, 100,-1.0, 1.0, 0);
  else if(k==2)
    camera(width/2+i-width/3*2, height/2, 100, width/2+i, height/2, 100,1.0, 1.0, 0);
  else
    camera(width/2+i, height/2, -300, width/2+i, height/2, 0, 0.0, 1.0, 1.0);
}
void draw_ground(){
  box(2*width,(height-170)*2,1000);
}
int i=0,n=1;
void draw_background(){
  for(int j=0;j<=n;j++){
    pushMatrix();
    fill(147,103,67);
      translate(width*j,height,0);
      draw_ground();
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
}

void draw_car_and_load(){
  pushMatrix();
    translate(width/2+i,156.5,100);
    fill(204,204,204);
    pushMatrix();
     translate(0,12.5,0);
     box(width*2,2,100);
    popMatrix();
    translate(75,0,0);
    drawCar(12.5,color(0,0,255));
  popMatrix();
  pushMatrix();
    translate(width/2+i-75,156.5,100);
    drawCar(12.5,color(255,0,0));
  popMatrix();
}

void draw(){
  background(137,189,222);
  lights(); 
  set_camera();
  draw_background();
  draw_car_and_load();
  i++;
  if(i%(width/2)==0)n++;
}
