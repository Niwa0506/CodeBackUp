void setup(){
  size(600, 400);
  background(238,28,37);
  smooth();
  noStroke();
  fill(255,255,0);
  translate(100,100);
  drawflag();
}

void star(){
  beginShape();
  for(int i = 0; i < 5; i++){
    float theta = 2 * TWO_PI / 5 * i - HALF_PI;
    vertex(.5 * cos(theta), .5 * sin(theta));
  }
  endShape();
}

void write_star(int n,float i,int t,int k){
  pushMatrix();
  scale(n,n);
  rotate(i);
  translate(t,0);
  rotate(t*18/2);
  if(k==1)rotate(-9);
  if(k==2)rotate(18);
  star();
  popMatrix();
}

//3:2
void drawflag(){
  write_star(120,0,0,0);
  translate(60,0);
  
  for(int i=0;i<4;i++){
   write_star(40,-PI/8*3+PI/4*i,2,i);
  }
}
