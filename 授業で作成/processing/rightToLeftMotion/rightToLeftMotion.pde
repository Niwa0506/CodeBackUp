void setup(){
  size(400,200);
  smooth();
  noStroke();
  fill(200,255,200);
  ellipseMode(CORNER);
  frameRate(30);
}
int d = 20,x=380,vx = -1;
void draw(){
  background(255);
  ellipse(x,0,d,d);
  if(x<=-20)x=width-d;
  else{x +=vx;}
  
}
