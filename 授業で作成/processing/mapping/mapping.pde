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
   translate(-.5,-.5,-.5);
   translate(-.5,-.5,-.5);
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
    translate(1,1,1);
    beginShape(TRIANGLE);
      textureMode(NORMAL);
      texture(img);
        vertex(0.5, 1, 0.5, 0.5, 0); vertex(0.5, 0, 0, 0, 1);
          vertex(0, 0, 0.5, 1, 1);
        vertex(0.5, 1, 0.5, 0.5, 0); vertex(0.5, 0, 0, 0, 1);
          vertex(1, 0, 0.5, 1, 1);
        vertex(0.5, 1, 0.5, 0.5, 0); vertex(1, 0, 0.5, 0, 1);
          vertex(0.5, 0, 1, 1, 1);
        vertex(0.5, 1, 0.5, 0.5, 0); vertex(0.5, 0, 1, 0, 1);
          vertex(0, 0, 0.5, 1, 1);
    endShape();
    beginShape(QUADS);
      textureMode(NORMAL);
      texture(img);
      vertex(0.5, 0, 0, 0, 0); vertex(1, 0, 0.5, 0, 1);
      vertex(0.5, 0, 1, 1, 1); vertex(0,0,0.5,1,0);
    endShape();
    translate(-.25,-.25,-.25);
    beginShape(QUADS);
      textureMode(NORMAL);
      texture(img);
      float x = 0;
      for(int j=0;j<360;j++){
        float i = radians(j);
        float k = radians(j+1);
        vertex(.5*cos(i),.5,.5*sin(i),x,0);vertex(.5*cos(k),.5,.5*sin(k),x+0.01,0);
        vertex(.5*cos(k),-.5,.5*sin(k),x+0.01,1);vertex(.5*cos(i),-.5,.5*sin(i),x,1);
        x+=0.01;
        if(x+0.01>1)x=0;
        
    }
    endShape();
    beginShape(TRIANGLE);
      textureMode(NORMAL);
      texture(img);
      for(int j=0;j<360;j++){
        float i = radians(j);
        float k = radians(j+1);
        
        vertex(.5*cos(i),.5,.5*sin(i),.5*cos(i)+.5,.5*sin(i)+.5);
        vertex(.5*cos(k),.5,.5*sin(k),.5*cos(k)+.5,.5*sin(k)+.5);
        vertex(0,.5,0,.5,.5);
          
        vertex(.5*cos(i),-.5,.5*sin(i),.5*cos(i)+.5,.5*sin(i)+.5);
        vertex(.5*cos(k),-.5,.5*sin(k),.5*cos(k)+.5,.5*sin(k)+.5);
        vertex(0,-.5,0,.5,.5);
      }
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
  texturedCube();
}
