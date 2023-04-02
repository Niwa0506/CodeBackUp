void setup(){
size(400, 200);
smooth();
noStroke();
ellipseMode(CORNER);
fill(200, 255, 200);
frameRate(30);
}
float d = 20,x = 0,vx = 5,y = 5,vy = -3,g = 0.5;
void draw(){
  background(255);
  ellipse(x, y, d, d);
  vy  +=  g;
  x  +=  vx;
  y  +=  vy;
  if(x < 0 || x + d > width){
  vx *=-1;
  if(x < 0) x *= -1;
  else if(x + d > width) x = 2 * (width - d) - x;
  }
  if(y < 0||y + d > height){
  vy =-vy*0.8;
  if(y < 0) y *= -1;
  if(y + d > height){y = 2 * (height - d) - y;
  }
  }
}
