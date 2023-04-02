void setup(){
  size(640,480);
  background(255);
}

void drawGrid(color c){
  int x = 0,y = 0,interval = 100;
  stroke(c);
  while(y<height){
    line(0,y,width,y);
    y += interval;
  }
  while(x < width){
    line(x,0,x,height);
    x += interval;
  }
}
