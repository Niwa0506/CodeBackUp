PImage img;
void setup(){
  size(400, 400, P3D);
  frameRate(30);
  img = loadImage("as.jpg");
  img.resize(400,400);
  noStroke();
}
void texturedCube(){
  float theta;
  
  pushMatrix();
    translate(-.5, -.5, -.5);
    beginShape(QUADS);
      textureMode(NORMAL);
      texture(img);
      for(theta=0;theta<361;theta++){
        float x = 0.5+0.5*cos(radians(theta));
        float y = 0.5+0.5*sin(radians(theta));
        float x1= 0.5+0.5*cos(radians(theta+1));
        float y1= 0.5+0.5*sin(radians(theta+1));
        vertex(0.5,0,0.5,0.5,0.5);
        vertex(x,0,y,x,y);
        vertex(x1,0,y1,x1,y1);
        vertex(0.5,0,0.5,0.5,0.5);
      }
    endShape();
  popMatrix();
  
 pushMatrix();
    translate(-.5, -.5, -.5);
    beginShape(QUADS);
      texture(img);
      textureMode(NORMAL);
      for(theta=0;theta< 361;theta++){
        float x = 0.5*cos(radians(theta))+0.5;
        float y = 0.5*sin(radians(theta))+0.5;
        float x1=0.5*cos(radians(theta+1))+0.5;
        float y1=0.5*sin(radians(theta+1))+0.5;
        vertex(0.5,1,0.5,0.5,0);
        vertex(x,0,y,theta/360,1);
        vertex(x1,0,y1,(theta+1)/360,1);
        vertex(0.5,1,0.5,0.5,0);
      }
    endShape();
  popMatrix();
}
void draw(){
  background(255);
  lights();
  translate(200, 150, -150);
  rotateX(map(mouseY, 0, height, PI, -PI));
  rotateY(map(mouseX, 0, width, -PI, PI));
  scale(200, 200, 200);
  texturedCube();
}
