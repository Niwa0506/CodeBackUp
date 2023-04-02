float wide = 1.5;
float h = -.5;

void setup(){
  size(400, 300, P3D);
  noStroke();
  frameRate(30);
}

void frame(color c){
  fill(c);
  //body
  pushStyle();
    //iron
    ambient(c);
    //specular(200, 200, 200); 
    specular(c); 
    shininess(5.0);
    emissive(0);
    pushMatrix();
      translate(-1,-1.25,0);
      beginShape(QUADS);
       
        vertex(-4.25,1.25,-wide);vertex(4.25,1.25,-wide);
          vertex(4.25,-1.25,-wide);vertex(-4.25,-1.25,-wide);
          
        vertex(4.25,1.25,-wide);vertex(4.25,1.25,wide);
          vertex(4.25,-1.25,wide);vertex(4.25,-1.25,-wide);
          
        vertex(-4.25,1.25,-wide);vertex(-4.25,1.25,wide);
          vertex(-4.25,-1.25,wide);vertex(-4.25,-1.25,-wide);
      
        vertex(-4.25,1.25,wide);vertex(4.25,1.25,wide);
          vertex(4.25,-1.25,wide);vertex(-4.25,-1.25,wide);
          
           vertex(-4.25,-1.25,-wide);vertex(4.25,-1.25,-wide);
          vertex(4.25,-1.25,wide);vertex(-4.25,-1.25,wide);
      endShape();
    popMatrix();
    
//body-sita
   pushMatrix();
      translate(-1,-1.25,0);
      beginShape(QUADS);
        pushStyle();
          //plastic
          ambient(128);
          emissive(0);
          specular(200);
          shininess(10);
        vertex(-4.25,1.25,-wide);vertex(4.25,1.25,-wide);
          vertex(4.25,1.25,wide);vertex(-4.25,1.25,wide);
          endShape();
        popStyle();
    popMatrix();
    //front
    pushMatrix();
      beginShape(QUADS);
        //hidari
        vertex(3.25,0,-wide);vertex(6.25,0,-wide+1);
        vertex(6.25,h,-wide+1);vertex(3.25,h-2,-wide);
        //mae
        vertex(6.25,0,-wide+1);vertex(6.25,0,wide-1);
        vertex(6.25,h,wide-1);vertex(6.25,h,-wide+1);
        //migi
        vertex(3.25,0,wide);vertex(6.25,0,wide-1);
         vertex(6.25,h,wide-1);vertex(3.25,h-2,wide);
        
      endShape();
    popMatrix();
   popStyle();
   
   pushStyle();
   pushMatrix();
     beginShape(QUADS);
        //sita
        //plastic
         pushStyle();
          ambient(128);
          emissive(0);
          specular(200);
          shininess(10);
        vertex(6.25,0,wide-1);vertex(6.25,0,-wide+1);
        vertex(3.25,0,-wide);vertex(3.25,0,wide);
        endShape();
        popMatrix();
      popStyle();
  //back-light
  pushMatrix();
    pushStyle();
      fill(255);
      translate(-5.25,-1.25,(wide-.5));
      //light
      emissive(255,0,0);
      specular(255);
      ambient(128);
      shininess(255);
      rotateY(PI/2);
      rect(-.5,0,.75,.75);
    popStyle();
  popMatrix();
  
  pushMatrix();
    pushStyle();
      fill(255);
      translate(-5.25,-1.25,-(wide-1.25));
      //light;
      emissive(255,0,0);
      specular(200);
      ambient(128);
      shininess(255);
      rotateY(PI/2);
      rect(.5,0,.75,.75);
    popStyle();
  popMatrix();
  //window
  
  pushStyle();
    shininess(255);
    emissive(0);
    ambient(20);
    specular(145);
  pushMatrix();
    fill(0);
    //translate(0,-2.3,0.5);
    beginShape(TRIANGLE);
      //hidari
        vertex(3.25,h-2,-wide);vertex(6.25,h,-wide+1);
         vertex(3.25,h,-wide);
        //migi
        vertex(3.25,h-2,wide);vertex(6.25,h,wide-1);
         vertex(3.25,h,wide);
         //mae
    endShape();
    beginShape(QUAD);
     vertex(3.25,h-2,-wide);vertex(3.25,h-2,wide);
         vertex(6.25,h,wide-1);vertex(6.25,h,-wide+1);
    endShape();
  popMatrix();
  popStyle();
}

void wing(color c){
  pushStyle();
    //iron
    ambient(c);
    //specular(200, 200, 200); 
    specular(c); 
    shininess(5.0);
    emissive(0);
    pushMatrix();
    
      translate(-.5,-1,-wide);
      beginShape(TRIANGLE);
        vertex(4,0,0);vertex(0,0,-5);
         vertex(0,0,0);
        vertex(4,.5,0);vertex(0,0.5,-5);
         vertex(0,0.5,0);
      endShape();
      
      
      beginShape(QUAD);
        vertex(4,0,0);vertex(4,.5,0);
         vertex(0,.5,-5);vertex(0,0,-5);
         
        vertex(0,0,0);vertex(0,.5,0);
         vertex(0,.5,-5);vertex(0,0,-5);
      endShape();
      
      translate(-5,-1,0);
      beginShape(TRIANGLE);
        vertex(4,0,0);vertex(0,0,0);
         vertex(0,0,-2);
        vertex(4,.5,0);vertex(0,0.5,0);
         vertex(0,0.5,-2);
      endShape();
      
      beginShape(QUAD);
        vertex(4,0,0);vertex(4,.5,0);
         vertex(0,.5,-2);vertex(0,0,-2);
        vertex(0,0,0);vertex(0,.5,0);
         vertex(0,.5,-2);vertex(0,0,-2);
      endShape();
      
    popMatrix();
    
    pushMatrix();
      translate(-.5,-1,wide);
      beginShape(TRIANGLE);
        vertex(4,0,0);vertex(0,0,5);
         vertex(0,0,0);
        vertex(4,.5,0);vertex(0,0.5,5);
         vertex(0,0.5,0);
      endShape();
      
      beginShape(QUAD);
        vertex(4,0,0);vertex(4,.5,0);
         vertex(0,.5,5);vertex(0,0,5);
        vertex(0,0,0);vertex(0,.5,0);
         vertex(0,.5,5);vertex(0,0,5);
      endShape();
      
      translate(-5,-1,0);
      
      beginShape(TRIANGLE); 
        vertex(4,0,0);vertex(0,0,0);
         vertex(0,0,2);
        vertex(4,.5,0);vertex(0,0.5,0);
         vertex(0,0.5,2);
      endShape();
      
      beginShape(QUAD);
        vertex(4,0,0);vertex(4,.5,0);
         vertex(0,.5,2);vertex(0,0,2);
         
        vertex(0,0,0);vertex(0,.5,0);
         vertex(0,.5,2);vertex(0,0,2);
      endShape();
      
    popMatrix();
  popStyle();
}
void drawCar(float s,color c){
  scale(s,s,s);
  frame(c);
  wing(c);
}

int k=0;
void keyPressed(){
  if(key =='A'||key =='a'){
     k=0;
  }else if(key =='S'||key=='s'){
     k=1;
  }else if(key =='D'||key=='d'){
     k=2;
  }else if(key =='F'||key=='f'){
     k=3;
  }else if(key =='G' || key =='g'){
     k=4;
  }
}

void set_camera(){
  if(k==0)
    camera(0, -10, 150, 0, -10, 0, 0, 1.0, -1.0);
  else if(k==1)
    camera(150, 0, 0, 0, 0, 0,-1.0, 1.0, 0);
  else if(k==2)
    camera(-150, 0, 0, 0, 0, 0,1.0, 1.0, 0);
  else if(k==3)
    camera(0, -10, -150, 0, -10, 0, 0, 1.0, 1.0);
  else
    camera(0,100,0,0,0,0,0,1.0,-1.0);
}

void draw(){
  background(255);
  ambient(128);
  ambientLight(100,100,100);
  lightSpecular(255,255,255);
  directionalLight(100,100,100,map(mouseX,0,width,1,-1),map(mouseY,0,height,1,-1),-1);
  translate(width/2,height/2,0);
  set_camera();
  drawCar(12.5,color(0,0,255));
}
