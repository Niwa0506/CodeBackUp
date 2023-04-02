void setup(){
  size(500, 500, P3D);
  noStroke();
  smooth();
  frameRate(60);
  colorMode(HSB,360,100,100);
}
void draw(){
  background(255);
  drawAxis();
}

void drawAxis(){
   for(int i=0;i<21;i++){
     for(int j=0;j<21;j++){
       fill(360/21*j,100/21*i,99);
       pushMatrix();
       translate(i*400/21+50,j*400/21+50,0);
       box(400/42,400/42,400/42);
       popMatrix();
     }
   }
}
