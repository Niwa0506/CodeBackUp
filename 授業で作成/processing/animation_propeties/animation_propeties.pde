PImage img1,img2,img3,img4;
void setup(){
  size(400, 300, P3D);
  img1 = loadImage("as.jpg");
  img2 = loadImage("check.png");
  img3 = loadImage("penguin.jpg");
  img4 = loadImage("oozora.jpg");
  img1.resize(200,200);
  img2.resize(200,200);
  img3.resize(200,200);
  noStroke();
  frameRate(30);
}

void frame(color c){
  fill(c);
  //body
  pushStyle();
    //iron
    ambient(200);
    specular(200, 200, 200);  
    shininess(5.0);
    emissive(0);
    pushMatrix();
      translate(-1,-1.25,0);
      textureMode(NORMAL);
      beginShape(QUADS);
        texture(img2);
        vertex(-4.25,1.25,-2,0,0);vertex(4.25,1.25,-2,0,1);
          vertex(4.25,-1.25,-2,1,1);vertex(-4.25,-1.25,-2,1,0);
          
        vertex(4.25,1.25,-2,0,0);vertex(4.25,1.25,2,0,1);
          vertex(4.25,-1.25,2,1,1);vertex(4.25,-1.25,-2,1,0);
          
        vertex(-4.25,1.25,-2,0,0);vertex(-4.25,1.25,2,0,1);
          vertex(-4.25,-1.25,2,1,1);vertex(-4.25,-1.25,-2,1,0);
      
        vertex(-4.25,1.25,2,0,0);vertex(4.25,1.25,2,0,1);
          vertex(4.25,-1.25,2,1,1);vertex(-4.25,-1.25,2,1,0);
           vertex(-4.25,-1.25,-2,0,0);vertex(4.25,-1.25,-2,0,1);
          vertex(4.25,-1.25,2,1,1);vertex(-4.25,-1.25,2,1,0);
      endShape();
    popMatrix();
    
//body-sita
pushMatrix();
      translate(-1,-1.25,0);
      beginShape(QUADS);
        textureMode(NORMAL);
        texture(img3);
        pushStyle();
          //plastic
          ambient(128);
          emissive(0);
          specular(200);
          shininess(10);
        vertex(-4.25,1.25,-2,0,0);vertex(4.25,1.25,-2,0,1);
          vertex(4.25,1.25,2,1,1);vertex(-4.25,1.25,2,1,0);
          endShape();
        popStyle();
popMatrix();
       
    //yane
    pushMatrix(); 
      translate(0,-2.5,0);
      beginShape(QUADS);
        textureMode(NORMAL);
        texture(img2);
        //hidari
        vertex(3.25,0,-2,0,0);vertex(-4,0,-2,0,1);
        vertex(-3.5,-1.5,-1.5,1,1);vertex(2.5,-1.5,-1.5,1,0);
        //mae
        vertex(3.25,0,-2,0,0);vertex(3.25,0,2,0,1);
        vertex(2.5,-1.5,1.5,1,1);vertex(2.5,-1.5,-1.5,1,0);
        //migi
        vertex(3.25,0,2,0,0);vertex(2.5,-1.5,1.5,0,1);
        vertex(-3.5,-1.5,1.5,1,1);vertex(-4,0,2,1,0);
        //usiro
        vertex(-4,0,2,0,0);vertex(-3.5,-1.5,1.5,0,1);
        vertex(-3.5,-1.5,-1.5,1,1);vertex(-4,0,-2,1,0);
        //ue
        vertex(2.5,-1.5,1.5,0,0);vertex(2.5,-1.5,-1.5,0,1);
        vertex(-3.5,-1.5,-1.5,1,1);vertex(-3.5,-1.5,1.5,1,0);
      endShape();
    popMatrix();
    //front
    pushMatrix();
      beginShape(QUADS);
        textureMode(NORMAL);
        texture(img2);
        //hidari
        vertex(3.25,0,-2,0,0);vertex(5.25,0,-2,0,1);
        vertex(5.25,-2,-2,1,1);vertex(3.25,-2.5,-2,1,0);
        //mae
        vertex(5.25,0,-2,0,0);vertex(5.25,0,2,0,1);
        vertex(5.25,-2,2,1,1);vertex(5.25,-2,-2,1,0);
        //migi
        vertex(3.25,0,2,0,0);vertex(5.25,0,2,0,1);
        vertex(5.25,-2,2,1,1);vertex(3.25,-2.5,2,1,0);
         vertex(3.25,-2.5,-2,0,0);vertex(3.25,-2.5,2,0,1);
        vertex(5.25,-2,2,1,1);vertex(5.25,-2,-2,1,0);
      endShape();
    popMatrix();
   popStyle();
   
   pushStyle();
   pushMatrix();
     beginShape(QUADS);
        textureMode(NORMAL);
        texture(img3);
        //sita
        //plastic
         pushStyle();
          ambient(128);
          emissive(0);
          specular(200);
          shininess(10);
        vertex(5.25,0,2,0,0);vertex(5.25,0,-2,0,1);
        vertex(3.25,0,-2,1,1);vertex(3.25,0,2,1,0);
        endShape();
        popMatrix();
      popStyle();
    
  //front-light
  pushMatrix();
    pushStyle();
      fill(255);
      translate(5.25,-1.25,1.5);
      //light
      emissive(255,255,255);
      specular(128);
      ambient(255);
      shininess(255);
      rotateY(PI/2);
      rect(-.5,0,.75,.75);
    popStyle();
  popMatrix();
  
  pushMatrix();
    pushStyle();
      fill(255);
      translate(5.25,-1.25,-.75);
      //light
      emissive(255,255,255);
      ambient(128);
      shininess(255);
      specular(255);
      rotateY(PI/2);
      rect(.5,0,.75,.75);
    popStyle();
  popMatrix();
  //back-light
  pushMatrix();
    pushStyle();
      fill(255);
      translate(-5.25,-1.25,1.5);
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
      translate(-5.25,-1.25,-.75);
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
    translate(0,-2.3,0.5);
    beginShape(QUADS);
    textureMode(NORMAL);
    texture(img1);
      //usiro_l
      vertex(-3.25,-0.2,1.625,1,1);vertex(-2.75,-1.4,1.125,0,1);
      vertex(-0.3,-1.4,1.125,0,0);vertex(-0.3,-0.2,1.625,1,0);
      //mae_l
      vertex(-0.1,-1.4,1.125,1,1);vertex(-0.1,-0.2,1.625,0,1);
      vertex(2.65,-0.2,1.625,0,0);vertex(2,-1.4,1.125,1,0);
      //front
      vertex(3.4,0,-2.25,1,1);vertex(3.4,0,1.25,0,1);
      vertex(2.65,-1.5,0.75,0,0);vertex(2.65,-1.5,-1.75,1,0);
      //usiro_r
      vertex(-3.25,-0.2,-2.625,1,1);vertex(-2.75,-1.4,-2.125,0,1);
      vertex(-0.3,-1.4,-2.125,0,0);vertex(-0.3,-0.2,-2.625,1,0);
      //mae_r
      vertex(-0.1,-1.4,-2.125,1,1);vertex(-0.1,-0.2,-2.625,0,1);
      vertex(2.65,-0.2,-2.625,0,0);vertex(2,-1.4,-2.125,1,0);
      //usiro
      vertex(-4.125,-0.2,1.25,1,1);vertex(-3.625,-1.5,0.75,0,1);
      vertex(-3.625,-1.5,-1.75,0,0);vertex(-4.125,-0.2,-2.25,1,0);
    endShape();
  popMatrix();
  popStyle();
}
void wheel(){
  float r =1;
  float length = .5;
  float x1,y1,z,x2,y2;
  z = length / 2+.125;
  pushStyle();
    shininess(255);
        emissive(0);
        ambient(20);
        specular(145);
    pushMatrix();
      beginShape(TRIANGLE);
        textureMode(NORMAL);
        texture(img4);
        fill(0);
        for(int deg = 0; deg < 360; deg++){
          x1 = cos(radians(deg));
          y1 = sin(radians(deg));
          x2 = cos(radians(deg+1));
          y2 = sin(radians(deg+1));
          vertex(0, 0, z,.5,.5);
          vertex(r*x1, r*y1, z,.5*x1,.5*y1);
          vertex(r*x2, r*y2, z,.5*x2,.5*y2);
          
          vertex(0, 0, -z,.5,.5);
          vertex(r*x1, r*y1, -z,.5*x1,.5*y1);
          vertex(r*x2, r*y2, -z,.5*x2,.5*y2);
        }
      endShape(); 
      popStyle();
      pushStyle();
        ambient(200);
        emissive(0);
        shininess(5.0);
        specular(200,200,200);
      beginShape(TRIANGLE);
        fill(255);
        for(int deg = 0; deg < 360; deg++){
          x1 = cos(radians(deg));
          y1 = sin(radians(deg));
          x2 = cos(radians(deg+1));
          y2 = sin(radians(deg+1));
          vertex(0, 0, z);
          vertex(r*x1/2, r*y1/2, z);
          vertex(r*x2/2, r*y2/2, z);
          
          vertex(0, 0, -z);
          vertex(r*x1/2, r*y1/2, -z);
          vertex(r*x2/2, r*y2/2, -z);
        }
        endShape();
      popStyle();
      pushStyle();
        shininess(255);
        emissive(0);
        ambient(20);
        specular(145);
        beginShape(QUADS);
          textureMode(NORMAL);
          texture(img4);
          //fill(0);
          float x = .0;
          for(int deg = 0; deg < 360; deg++){
            x1 = cos(radians(deg));
            y1 = sin(radians(deg));
            x2 = cos(radians(deg+1));
            y2 = sin(radians(deg+1));
            vertex(r*x1, r*y1, z,x,0);
            vertex(r*x2, r*y2, z,x+.003,0);
            vertex(r*x2, r*y2, -z,x+.003,1);
            vertex(r*x1, r*y1, -z,x,1);
            x+=.003;
          }
      endShape();
    popStyle();
  popMatrix();
}
void wheels(){
  pushMatrix();
    translate(-3,0,2);
    wheel();
  popMatrix();
 
  pushMatrix();
    translate(3,0,-2);
    wheel();
  popMatrix();
  
  pushMatrix();
    translate(-3,0,-2);
    wheel();
  popMatrix();
  
  pushMatrix();
    translate(3,0,2);
    wheel();
  popMatrix();
}


void drawCar(float s,color c){
  scale(s,s,s);
  frame(c);
  wheels();
  
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
  background(0);
  ambient(128);
  ambientLight(100,100,100);
  lightSpecular(255,255,255);
  directionalLight(100,100,100,map(mouseX,0,width,1,-1),map(mouseY,0,height,1,-1),-1);
  translate(width/2,height/2,0);
  set_camera();
  drawCar(12.5,color(0,0,255));
}
