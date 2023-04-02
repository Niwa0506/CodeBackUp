float theta = 0.;
void setup(){
  size(800,600,P3D);
  frameRate(30);
  noStroke();
}

void draw(){
  lights();
  background(255);
  fill(160,0,0);
  translate(width/2,height/2,0);
  rotateX(radians(-20));
  rotateY(radians(theta));
  rect(-200,-200,400,400);
  
  fill(0,160,0);
  rotateY(radians(90));
  rect(-200,-200,400,400);
  theta+=1;
}
