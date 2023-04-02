boolean isEmissive =true;
void setup(){
  size(400, 300, P3D);
  noStroke();
  fill(255);
  frameRate(60);
}
void keyPressed(){
  switch(key){
    case'e':
      isEmissive = !isEmissive;
      break;
    }
  }
void draw(){
  background(32);
  directionalLight(255, 255, 255, -.5, .5, -1);
  if(isEmissive) emissive(0, map(mouseX, 0, width, 0, 255), 0);
  else emissive(0, 0, 0);
  translate(width / 2, height / 2, 0);
  sphere(100);
}
