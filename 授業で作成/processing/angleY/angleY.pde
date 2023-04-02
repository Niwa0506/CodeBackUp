void setup(){
  size(400, 300, P3D);
  noStroke();
  frameRate(30);
}
void draw(){
    background(255);
    lights();
    float fov = (PI / 300.)*mouseY;
    if(fov<0.35)fov = 0.35;
    text(fov,0,0);
    float cameraZ = (height / 2) / tan(fov);
    perspective(fov,float(width) /float(height), cameraZ / 10, cameraZ * 10);
    translate(width / 2, height / 2, -50);
    rotateX(-PI / 8);
    rotateY(-PI / 6);
    scale(100, 100, 100);
    coloredCube(255);
}

void coloredCube(float alpha){
   pushMatrix();
     scale(.5, .5, .5);
     beginShape(QUADS);
       fill(255, 0, 0, alpha);//Red
       vertex(1, -1, -1); vertex(1, -1, 1); vertex(1, 1, 1); vertex(1, 1, -1);
       fill(0, 255, 0, alpha);//Green
       vertex(1, 1, 1); vertex(-1, 1, 1); vertex(-1, 1, -1); vertex(1, 1, -1);
       fill(0, 0, 255, alpha);//Blue
       vertex(-1, 1, 1); vertex(1, 1, 1); vertex(1, -1, 1); vertex(-1, -1, 1);
       fill(255, 255, 0, alpha);//Yellow
       vertex(-1, -1, -1); vertex(-1, -1, 1); vertex( 1, -1, 1); vertex( 1, -1, -1);
       fill(255, 0, 255, alpha);//Magenta
       vertex(-1, 1, -1); vertex(-1, 1, 1); vertex(-1, -1, 1); vertex(-1, -1, -1);
       fill(0, 255, 255, alpha);//Cyan
       vertex(1, 1, -1); vertex(-1, 1, -1); vertex(-1, -1, -1); vertex(1, -1, -1);
     endShape();
   popMatrix();
 }
