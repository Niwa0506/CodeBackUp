PImage img;
void setup(){
  size(400, 300, P3D);
  frameRate(30);
  img = loadImage("as.jpg");
  img.resize(200,200);
  noStroke();
}
void texturedCube(){
  pushMatrix();
    translate(-.5, -.5, -.5);
    beginShape(TRIANGLE);
      textureMode(NORMAL);
      texture(img);
        vertex(0, 0, 0, 0.5, 0); vertex(0, 1, 0, 0, 1);
          vertex(1, 0, 0, 1, 1); 
        vertex(1, 0, 0, 0.5, 0); vertex(0, 1, 0, 0, 1);
          vertex(0, 0, 1, 1, 1); 
        vertex(0, 0, 1, 0.5, 0); vertex(0, 1, 0, 0, 1);
          vertex(0, 0, 0, 1, 1); 
        vertex(0, 0, 0, 0.5, 0); vertex(0, 0, 1, 0, 1);
          vertex(1, 0, 0, 1, 1); 
    endShape();
  popMatrix();
}

void frame(color c){
  fill(c);
  //body
  pushMatrix();
      translate(-1,-1.25,0);
      box(8.5,2.5,4);
      beginShape(QUADS);
        textureMode(NORMAL);
        texture(img);
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
      texture(img);
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
      texture(img);
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
}

void wheel(){
  float r =1;
  float length = .5;
  float x,y,z,x1,y1;
    pushMatrix();
      beginShape(TRIANGLE_FAN);
        fill(0);
        z = -length / 2;
        for(int deg = 0; deg <= 360; deg = deg + 10){
          x = cos(radians(deg)) * r;
          y = sin(radians(deg)) * r;
          vertex(0, 0, z);
          vertex(x, y, z);
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
void drawCar(float s,color c){
  scale(s,s,s);
  frame(c);
  wheels();
  
}

void draw(){
  background(255);
  lights();
  translate(200, 150, -200);
  rotateX(map(mouseY, 0, height, PI, -PI));
  rotateY(map(mouseX, 0, width, -PI, PI));
  scale(20, 20, 20);
  //texturedCube();
  drawCar(1,color(255,0,0));
}
