int n = 0;
void setup(){
  size(800,300);
  textFont(createFont("Tempus Sans ITC",24));
  fill(0);
  smooth();
}

void dragon(int p,float length,int sign){
  if(p==0){
    line(0,0,length,0);
    return;
  }
  length*=sqrt(.5);
  pushMatrix();
  rotate(radians(45*sign));
  dragon(--p,length,1);
  popMatrix();
  
  pushMatrix();
  translate(length*cos(radians(45*sign)),length*sin(radians(45*sign)));
  rotate(radians(-45*sign));
  dragon(p,length,-1);
  popMatrix();
  
}

void mousePressed(){
  if((mouseButton ==LEFT)&&(n<15))n++;
  else if((mouseButton ==RIGHT)&&(n>0))n--;
}

void draw(){
background(255);
text("n = "+n,10,30);
translate(width/4,height/2);
dragon(n,width/2,1);
}
