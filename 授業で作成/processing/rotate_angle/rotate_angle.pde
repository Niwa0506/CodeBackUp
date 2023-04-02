void setup(){
  size(400,300,P3D);
  noStroke();
  frameRate(30);
}
float angle=0;
void draw(){
  background(255);
  lights();
  camera(200*cos(angle),-150,200*sin(angle),0,0,0,0,1,0);
  angle+=0.01;
  if(angle==3.14)angle=0;
  scale(100,100,100);
  coloredCube(255);
}
  
void coloredCube(float alpha){
   pushMatrix();
     scale(.5, .5, .5);
     beginShape(QUADS);
       fill(255, 0, 0, alpha);//Red
       vertex(1, -1, -1); vertex(1, -1, 1); vertex(1, 1, 1); vertex(1, 1, -1);
       fill(0, 255, 0, alpha);//Green
       vertex(1, 1, 1); vertex(-1, 1, 1); vertex(-1, 1, -1); vertex(1, 1, -1);
       fill(0, 0, 255, alpha);//Blue
       vertex(-1, 1, 1); vertex(1, 1, 1); vertex(1, -1, 1); vertex(-1, -1, 1);
       fill(255, 255, 0, alpha);//Yellow
       vertex(-1, -1, -1); vertex(-1, -1, 1); vertex( 1, -1, 1); vertex( 1, -1, -1);
       fill(255, 0, 255, alpha);//Magenta
       vertex(-1, 1, -1); vertex(-1, 1, 1); vertex(-1, -1, 1); vertex(-1, -1, -1);
       fill(0, 255, 255, alpha);//Cyan
       vertex(1, 1, -1); vertex(-1, 1, -1); vertex(-1, -1, -1); vertex(1, -1, -1);
     endShape();
   popMatrix();
 }
