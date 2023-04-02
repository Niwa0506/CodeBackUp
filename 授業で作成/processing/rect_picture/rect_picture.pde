PImage img;
void setup(){
  size(400, 300, P3D);
  frameRate(30);
  img = loadImage("penguin.jpg");
  img.resize(300,200);
  noStroke();
}

void texturedCube(){
  pushMatrix();
    translate(-.5, -.75, -.5);
    beginShape(QUADS);
      texture(img);
      textureMode(NORMAL);
      vertex(0, 1.5, 0, 0, 0); vertex(0, 0, 0, 0, 1);
        vertex(1, 0, 0, 1, 1); vertex(1, 1.5, 0, 1, 0);
      vertex(1, 1.5, 0, 0, 0); vertex(1, 0, 0, 0, 1);
        vertex(1, 0, 1, 1, 1); vertex(1, 1.5, 1, 1, 0);
      vertex(1, 1.5, 1, 0, 0); vertex(1, 0, 1, 0, 1);
        vertex(0, 0, 1, 1, 1); vertex(0, 1.5, 1, 1, 0);
      vertex(0, 1.5, 1, 0, 0); vertex(0, 0, 1, 0, 1);
        vertex(0, 0, 0, 1, 1); vertex(0, 1.5, 0, 1, 0);
      vertex(0, 1.5, 1, 0, 0); vertex(0, 1.5, 0, 0, 1);
        vertex(1, 1.5, 0, 1, 1); vertex(1, 1.5, 1, 1, 0);
      vertex(0, 0, 0, 0, 0); vertex(0, 0, 1, 0, 1);
        vertex(1, 0, 1, 1, 1); vertex(1, 0, 0, 1, 0);
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
