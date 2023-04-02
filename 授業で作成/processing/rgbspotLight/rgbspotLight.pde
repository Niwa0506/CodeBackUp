void setup(){
  size(400,300,P3D);
  noStroke();
  frameRate(30);
}

void drawFloor(){
  fill(128);
  int s = 5;
  for(int z = -100;z < 100;z+=s){
    for(int x = -100;x<100;x +=s){
      beginShape(QUADS);
        vertex(x,0,z);vertex(x,0,z+s);
        vertex(x+s,0,z+s);vertex(x+s,0,z);
      endShape();
    }
  }
}
void drawSpot(int r,int g,int b){
  pushMatrix();
    spotLight(r,g,b,10,100,10,0,-1,0,PI/2,50);
  popMatrix();
}

float i = .0;
void draw(){
  background(192);
  lights();
  translate(200,200,-50);
  rotateX(radians(160));
  rotateY(radians(-30));
  pushMatrix();
    rotateY(i);
    drawSpot(255,0,0);
    rotateY(PI/3*2);
    drawSpot(0,255,0);
    rotateY(PI/3*2);
    drawSpot(0,0,255);
  popMatrix();
  drawFloor();
  i+=.05;
}
