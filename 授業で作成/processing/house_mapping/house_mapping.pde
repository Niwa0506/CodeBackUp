PImage img;
void setup(){
  size(400, 300, P3D);
  frameRate(30);
  img = loadImage("as.jpg");
  img.resize(200,200);
  noStroke();
}

void yane(){
  fill(85,88,89);
  pushMatrix();
    beginShape(QUADS);
      textureMode(NORMAL);
      texture(img);
      vertex(-.6,0,.6);vertex(-.6,0,-.6);
      vertex(.6,0,-.6);vertex(.6,0,.6);
    endShape();
    popMatrix();
    pushMatrix();
    beginShape(TRIANGLE);
      textureMode(NORMAL);
      texture(img);
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
      textureMode(NORMAL);
      texture(img);
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
}
void drawHouse(float s,color c){
  fill(c);
  scale(s,s,s);
  translate(0,-.4,0);
  body();
  translate(0,-.5,0);
  yane();
}

void draw(){
  background(255);
  lights();
  translate(200, 150, -200);
  rotateX(map(mouseY, 0, height, PI, -PI));
  rotateY(map(mouseX, 0, width, -PI, PI));
  scale(200, 200, 200);
  drawHouse(1,color(255,0,0));
}
