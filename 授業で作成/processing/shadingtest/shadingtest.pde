void setup(){
  size(400,300,P3D);
  noStroke();
  fill(192);
  frameRate(30);
}
void drawFloor(){
  fill(128);
  int s = 5;
  for(int z = -100; z < 100; z += s){
    for(int x = -100; x < 100; x += s){
      beginShape(QUADS);
        vertex(x, 0, z); vertex(x, 0, z + s);
        vertex(x + s, 0, z + s); vertex(x + s, 0, z);
      endShape();
    }
  }
}
void draw(){
  background(32);
  float theta = map(mouseY,0,height,-PI/2,PI/2);
  float phi = map(mouseX,0,width,-PI/2,PI/2);
  float x = 500*sin(phi);
  float y = 500*sin(theta);
  float z = 500*cos(phi)*cos(theta);
  int r = mouseX*255/400;
  int g = mouseY*255/300;
  int b = 255;
  pushMatrix();
    translate(width/2,height/2,0);
    pointLight(r,g,b,x,y,z);
    sphere(80);
    translate(0,80,0);
    drawFloor();
  popMatrix();
}
