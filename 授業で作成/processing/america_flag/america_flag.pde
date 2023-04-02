void setup(){
  size(494, 260);
  background(255);
  smooth();
  noStroke();
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

void redline(){
  fill(178,34,52);
  rect(0,0,width,height/13);
}
int bw,bh;
void bluerect(){
  bw = int(width/2.5);bh = height/13*7;
  fill(60,59,110);
  rect(0,0,bw,bh);
}

void raw_star(int start_x,int start_y,int n){
  pushMatrix();
  translate(start_x,start_y);
  for(int i=0;i<3+n;i++){
    pushMatrix();
    scale(15,15);
    star();
    popMatrix();
    translate(0,n*start_y);
  }
  popMatrix();
    
}
//10:19
void drawflag(){
  for(int k = 0;k<7;k++){
    pushMatrix();
    translate(0,height/13*k*2);
    redline();
    popMatrix();
  }
  bluerect();
  int start_x = bw/12,start_y = bh/10;
  fill(255);
  pushMatrix();
  for(int h = 0;h<6;h++){
    raw_star(start_x+h*start_x*2,start_y,2);
  }
  popMatrix();
  start_x = bw/6;start_y = bh/5;
  pushMatrix();
  for(int h = 0;h<5;h++){
    raw_star(start_x+h*start_x,start_y,1);
  }
  popMatrix();
}
