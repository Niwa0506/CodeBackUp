boolean isAmbientLight = true,isAmbient = true;
void setup(){
  size(400,300,P3D);
  noStroke();
  frameRate(60);
}

void keyPressed(){
  switch(key){
    case 'l':
      isAmbientLight = !isAmbientLight;
    case 'a':
      isAmbient = !isAmbient;
      break;
  }
}

void draw(){
  background(32);
  directionalLight(255, 255, 255, map(mouseX, 0, width, 1, -1), map(mouseY, 0, height,1, -1), -1);
  if(isAmbientLight) ambientLight(128, 128, 0);
  if(isAmbient) ambient(0, 128, 0);
  else fill(128);
  translate(width / 2, height / 2, 0);
  sphere(100);
}
