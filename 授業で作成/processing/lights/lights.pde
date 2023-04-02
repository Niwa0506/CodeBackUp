float theta =.0;

void setup(){
  size(400,300,P3D);
  noStroke();
  fill(192);
  frameRate(30);
}

void draw(){
  background(32);
  lights();
  
  theta +=.01;
  pushMatrix();
    translate(width/2,height/2,0);
    rotateX(-PI/6);
    rotateY(theta);
    box(100);
  popMatrix();
}
