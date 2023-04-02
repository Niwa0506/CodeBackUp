void setup(){
  size(500, 500, P3D);
  noStroke();
  smooth();
  frameRate(60);
}

void draw(){
  lights();
  background(255);
  translate(width/2,height/2);
  rotateX(map(mouseY, 0, height, PI, -PI));
  rotateY(map(mouseX, 0, width, -PI, PI));
  drawAxis();
}
int i,j,k;
void drawAxis(){
   for(i=0;i<11;i++){
     for(j=0;j<11;j++){
       for(k=0;k<11;k++){
         if(i==0&&k==0&&j==0)fill(0,0,0);
         else fill(255*(i+1)/11,255*(j+1)/11,255*(k+1)/11);
         pushMatrix();
         translate(-100,-100,-100);
         translate(i*200/11,j*200/11,k*200/11);
         box(100/11,100/11,100/11);
         popMatrix();
       }
     }
   }
}
