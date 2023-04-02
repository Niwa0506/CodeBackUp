float angle = 0;
void setup(){
  background(0);
  size(400,400,P3D); 
  frameRate(60);
  noStroke();
}

void draw() {
  background(0);
 
  ambientLight(20, 20, 20);    
  lightSpecular(255, 255, 255);    
  directionalLight(100, 100, 100, 0, 1, -1); 
 
  pushMatrix();
  pushStyle();
  ambient(128,128,128);
  translate(100, height/2, 0);
  specular(200, 200, 200);  
  shininess(5.0);  
  sphere(50);
  popStyle();
  popMatrix();
 
  pushMatrix();
  translate(300, height/2, 0);
  //specular(200, 200, 200);  
  //shininess(1.0);   
  sphere(50);
  popMatrix();
}
