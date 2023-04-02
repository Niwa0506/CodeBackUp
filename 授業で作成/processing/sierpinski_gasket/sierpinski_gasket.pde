int n = 0;
void setup(){
  size(800,300);
  textFont(createFont("Tempus Sans ITC",24));
  fill(0);
  smooth();
}

void drawKoch(int level,float x,float y,float length){
  float x1,y1,x2,y2,x3,y3;
  fill(0);
  x1 = x+length*cos(radians(30));
  y1 = y+length*sin(radians(30));
  x2 = x+length*cos(radians(150));
  y2 = y+length*sin(radians(150));
  x3 = x+length*cos(radians(270));
  y3 = y+length*sin(radians(270));
  if(level==0){triangle(x1,y1,x2,y2,x3,y3);return;}
  fill(255);
  x1 -= length/2*cos(radians(30));
  y1 -= length/2*sin(radians(30));
  x2 -= length/2*cos(radians(150));
  y2 -= length/2*sin(radians(150));
  x3 -= length/2*cos(radians(270));
  y3 -= length/2*sin(radians(270));
  drawKoch(--level,x1,y1,length/2);
  drawKoch(level,x2,y2,length/2);
  drawKoch(level,x3,y3,length/2);
}

void mousePressed(){
  if((mouseButton ==LEFT)&&(n<8))n++;
  else if((mouseButton ==RIGHT)&&(n>0))n--;
}

void draw(){
background(255);
text("n = "+n,10,30);
drawKoch(n,float(width)/2,float(height)/2,float(width)/8);
}
