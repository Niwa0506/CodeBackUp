int n = 1;
void setup(){
  size(800,800);
  textFont(createFont("Tempus Sans ITC",24));
  fill(0);
  smooth();
}

void drawKoch(int level,float length){
  float length2 = length/1.5;
  if(1==level){
    line(0,0,0,length);
    return;
  }
  
  translate(0,length);
  
  pushMatrix();
  rotate(PI/7.58);
  if(level!=2)line(0,0,0,length2);
  drawKoch(--level,length2);
  popMatrix();
  
  pushMatrix();
  rotate(-PI/7.6);
  if(level!=1)line(0,0,0,length2);
  drawKoch(level,length2);
  popMatrix();

}

void mousePressed(){
  if((mouseButton ==LEFT)&&(n<15))n++;
  else if((mouseButton ==RIGHT)&&(n>0))n--;
}

void draw(){
  background(255);
  text("n = "+n,10,30);
  translate(width/2,height);
  line(0,0,0,-float(width)/4);
  if(n>1){
    drawKoch(n,-float(width)/4);}
}
