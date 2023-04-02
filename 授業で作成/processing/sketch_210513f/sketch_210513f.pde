void setup(){
  size(400,200);
  smooth();
  fill(200,255,200);
  noStroke();
  frameRate(30);
}

void draw(){
  background(255);
  movestraight_star();
}

int i=10;
void star(){
  beginShape();
  for(int i=0;i<5;i++){
    int R = 50;
    vertex(R*cos(radians(i*144-90))+50,R*sin(radians(i*144-90))+height/2);
  }
  endShape(CLOSE);
}

void movestraight_star(){
  pushMatrix();
  translate(i++,0);
  star();
  popMatrix();
}
