int angle=0;
void setup(){
  size(400, 300, P3D);
  noStroke();
  frameRate(60);
}
void draw(){
  angle +=1;
  background(255);
  translate(200, 150, -50);
  rotateX(radians(angle));
  rotateY(radians(2*angle));
  scale(50, 50, 50);
  coloredCube(255);
}

void coloredCube(float alpha){
  pushMatrix();
  scale(.5, .5, .5);
  beginShape(QUADS);
    fill(255, 0, 0, alpha);//Red
    vertex(1, -1, -1);vertex(1, -1, 1);vertex(1, 1, 1);vertex(1, 1, -1);
    fill(0, 255, 0, alpha);//Green
    vertex(1, 1, 1);vertex(-1, 1, 1);vertex(-1, 1, -1);vertex(1, 1, -1);
    fill(0, 0, 255, alpha);//Blue
    vertex(-1, 1, 1);vertex(1, 1, 1);vertex(1, -1, 1);vertex(-1, -1, 1);
    fill(255, 255, 0, alpha);//Yellow
    vertex(-1, -1, -1);vertex(-1, -1, 1);vertex( 1, -1, 1);vertex( 1, -1, -1);
    fill(255, 0, 255, alpha);//Magenta
    vertex(-1, 1, -1);vertex(-1, 1, 1);vertex(-1, -1, 1);vertex(-1, -1, -1);
    fill(0, 255, 255, alpha);//Cyan
    vertex(1, 1, -1);vertex(-1, 1, -1);vertex(-1, -1, -1);vertex(1, -1, -1);
  endShape();
  popMatrix();
}
