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
void draw(){
  background(255);
  lights();
  translate(200, 150, -200);
  rotateX(map(mouseY, 0, height, PI, -PI));
  rotateY(map(mouseX, 0, width, -PI, PI));
  scale(200, 200, 200);
  //texturedCube();
  drawTree(1);
}

void leaf(int r,int g,int b){
    fill(r, g, b);
    beginShape(TRIANGLES);
      textureMode(NORMAL);
      texture(img);
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
    box(1);
    beginShape(QUADS);
      textureMode(NORMAL);
      texture(img);
      //ok
      vertex(-.5,.5,-.5,0,0);vertex(.5,.5,-.5,0,1);
        vertex(.5,.5,.5,1,1);vertex(-.5,.5,.5,1,0);
        //ok
      vertex(-.5,-.5,-.5,0,0);vertex(-.5,.5,-.5,0,1);
        vertex(.5,.5,-.5,1,1);vertex(.5,-.5,-.5,1,0);
        //error
      vertex(.5,-.5,-.5,0,0);vertex(.5,.5,-.5,0,1);
        vertex(.5,.5,.5,1,1);vertex(.5,-.5,.5,1,0);
        //ok
      vertex(-.5,-.5,-.5,0,0);vertex(-.5,.5,-.5,0,1);
        vertex(-.5,.5,.5,1,1);vertex(-.5,-.5,.5,1,0);
        //error
      vertex(-.5,-.5,.5,0,0);vertex(-.5,.5,.5,0,1);
        vertex(.5,.5,.5,1,1);vertex(.5,-.5,.5,1,0);
    endShape();
  popMatrix();
}

void drawTree(float s){
    scale(s, s, s);
    trunk();
    translate(0,-.4,0);
    leaves();
}
