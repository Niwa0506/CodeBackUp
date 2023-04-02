void setup(){
  size(400,200);
  smooth();
  noStroke();
  fill(200,255,200);
  ellipseMode(CORNER);
  frameRate(30);
}
int d = 20, x = 0,vx= 1,y = 0, vy = 1;
void draw(){
  int h = height - d,w = width - d;
  background(255);
  ellipse(x,y,d,d);
  if(x>=w||x<0){vx = -1*vx;}
  if(y>=h||y<0){vy = -1*vy;}
  x += vx;y += vy;
}
