int n = 0;
void setup(){
  size(800,300);
  textFont(createFont("Tempus Sans ITC",24));
  fill(0);
  smooth();
}

void drawKoch(int level,float x1,float y1,float angle,float length){
  float x2,y2;
  
  if(0==level){
    x2 = x1+length*cos(angle);
    y2 = y1+length*sin(angle);
    line(x1,y1,x2,y2);
    return;
  }
  drawKoch(--level,x1,y1,angle,length);
  x2 = x1+length*cos(angle);
  y2 = y1+length*sin(angle);
  length/=1.5;
  drawKoch(level,x2,y2,angle+PI/6,length);
  drawKoch(level,x2,y2,angle-PI/6,length);
  
}

void mousePressed(){
  if((mouseButton ==LEFT)&&(n<8))n++;
  else if((mouseButton ==RIGHT)&&(n>0))n--;
}

void draw(){
background(255);
text("n = "+n,10,30);
drawKoch(n,float(width/2),float(height),radians(-90),float(height)/4);
}
