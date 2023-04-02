void setup(){
  size(100, 100);
  background(255);
  fill(152, 251, 152);
  smooth();
  noStroke();
  translate(width / 2, height / 2);
  scale(100, 100);
  frameRate(30);
}

void draw(){
  background(255);
  translate(width / 2, height / 2);
  scale(100, 100);
  rotate_star();
}

void star(){
  beginShape();
  for(int i = 0; i < 5; i++){
    float theta = 2 * TWO_PI / 5 * i - HALF_PI;
    vertex(.5 * cos(theta), .5 * sin(theta));
  }
  endShape();
}
int j=0;
void rotate_star(){
  float angle = (PI+j++)/PI;
  rotate(angle);
  star();
}
