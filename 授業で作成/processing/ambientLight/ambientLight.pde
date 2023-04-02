float theta = .0;

void setup(){
  size(400,400,P3D);
  frameRate(30);
  noStroke();
  fill(192);
}

void draw(){
  background(32);
  int m = int(map(mouseX,0,width,0,255));
  ambientLight(m,m,m);
  
  theta +=.01;
  pushMatrix();
    translate(width/2,height/2,0);
    rotateX(-PI/6);
    rotateY(theta);
    box(100);
  popMatrix();
}
