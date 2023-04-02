float wide = 1.5;
float h = -.5;

void frame(color c){
  fill(c);
  //body
  pushStyle();
    //iron
    ambient(c);
    specular(200, 200, 200);  
    shininess(5.0);
    emissive(0);
    pushMatrix();
      translate(-1,-1.25,0);
      beginShape(QUADS);
         //left
        vertex(-4.25,1.25-.25,-wide);vertex(4.25,1.25-.25,-wide);
          vertex(4.25,-1.25+.25,-wide);vertex(-4.25,-1.25+.25,-wide);
         //mae
        vertex(4.25,1.25,-wide+.25);vertex(4.25,1.25,wide-.25);
          vertex(4.25,-1.25,wide-.25);vertex(4.25,-1.25,-wide+.25);
         //ushiro_ue
        vertex(-4.25,-1,-wide+.25);vertex(-4.25,-1,wide-.25);
          vertex(-4.25,-1.25,wide-.25);vertex(-4.25,-1.25,-wide+.25);
         //ushiro_sita
         vertex(-4.25,1,-wide+.25);vertex(-4.25,1,wide-.25);
          vertex(-4.25,1.25,wide-.25);vertex(-4.25,1.25,-wide+.25);
         //ushiro_migi
         vertex(-4.25,1,wide);vertex(-4.25,1,wide-.25);
          vertex(-4.25,-1,wide-.25);vertex(-4.25,-1,wide);
         //ushiro_hidari
         vertex(-4.25,1,-wide+.25);vertex(-4.25,1,-wide);
            vertex(-4.25,-1,-wide);vertex(-4.25,-1,-wide+.25);
         //ushiro_mannaka
         vertex(-4.25,1,-wide+.25);vertex(-4.25,1,wide-.25);
          vertex(-4.25,-1,wide-.25);vertex(-4.25,-1,-wide+.25);
        //right
        vertex(-4.25,1.25-.25,wide);vertex(4.25,1.25-.25,wide);
          vertex(4.25,-1.25+.25,wide);vertex(-4.25,-1.25+.25,wide);
        //ue
           vertex(-4.25,-1.25,-wide+.25);vertex(4.25,-1.25,-wide+.25);
          vertex(4.25,-1.25,wide-.25);vertex(-4.25,-1.25,wide-.25);
          
          float r = .25;
          float x = wide-.25;
          for(int j=0;j<90;j++){
            float i = radians(j);
            float k = radians(j+1);
            //up_left
            vertex(-4.25,r*sin(i+PI)-1,r*cos(i+PI)-x);vertex(4.25,r*sin(i+PI)-1,r*cos(i+PI)-x);
              vertex(4.25,r*sin(k+PI)-1,r*cos(k+PI)-x);vertex(-4.25,r*sin(k+PI)-1,r*cos(k+PI)-x);
            
            //down_left 
            vertex(-4.25,r*sin(i+PI/2)+1,r*cos(i+PI/2)-x);vertex(4.25,r*sin(i+PI/2)+1,r*cos(i+PI/2)-x);
              vertex(4.25,r*sin(k+PI/2)+1,r*cos(k+PI/2)-x);vertex(-4.25,r*sin(k+PI/2)+1,r*cos(k+PI/2)-x);
            
            //down_right
            vertex(-4.25,r*sin(i)+1,r*cos(i)+x);vertex(4.25,r*sin(i)+1,r*cos(i)+x);
              vertex(4.25,r*sin(k)+1,r*cos(k)+x);vertex(-4.25,r*sin(k)+1,r*cos(k)+x);
            
            //up_right
            vertex(-4.25,r*sin(i-PI/2)-1,r*cos(i-PI/2)+x);vertex(4.25,r*sin(i-PI/2)-1,r*cos(i-PI/2)+x);
              vertex(4.25,r*sin(k-PI/2)-1,r*cos(k-PI/2)+x);vertex(-4.25,r*sin(k-PI/2)-1,r*cos(k-PI/2)+x);
            
            }
      endShape();
      
      translate(-4.25,0,0);
      
      pushMatrix();
      translate(0,-1,wide-.25);
      rotateY(PI/2); 
      ellipse(0,0,2*r,2*r);
      popMatrix();
  
      pushMatrix();
      translate(0,1,wide-.25);
      rotateY(PI/2); 
      ellipse(0,0,2*r,2*r);
      popMatrix();
      
      pushMatrix();
      translate(0,-1,-wide+.25);
      rotateY(PI/2); 
      ellipse(0,0,2*r,2*r);
      popMatrix();
     
      pushMatrix();
      translate(0,1,-wide+.25); 
      rotateY(PI/2);
      ellipse(0,0,2*r,2*r);
      popMatrix();
      
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
   
    
  //front-light
  pushMatrix();
    pushStyle();
      fill(255);
      translate(5.25,-1,(wide-.5));
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
      translate(5.25,-1,-(wide-1.25));
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
        vertex(-4.25,1.25,-wide+.25);vertex(4.25,1.25,-wide+.25);
          vertex(4.25,1.25,wide-.25);vertex(-4.25,1.25,wide-.25);
          endShape();
        popStyle();
    popMatrix();
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
