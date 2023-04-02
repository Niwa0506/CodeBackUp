class Particle {
  PVector location;
  PVector velocity;
  PVector acceleration;
  float lifespan;
  
  boolean seed = false;
  
  float hu;
  
  Particle(float x, float y, float z,float h){
    hu = h;
    acceleration = new PVector(0,0);
    velocity = new PVector(0,random(-25,-10),0);
    location = new PVector(x,y,z);
    seed = true;
    lifespan = 255.0;
  }
  
  Particle(PVector l,float h){
    hu = h;
    acceleration = new PVector(0,0);
    velocity  = PVector.random3D();
    velocity.mult(random(8,16));
    location = l.copy();
    lifespan = 255.0;
  }
  
  void applyForce(PVector force){
    acceleration.add(force);
  }
  
  void run(){
    update();
    display();
  }
  
  boolean explode(){
    if(seed&&velocity.y>0){
      lifespan = 0;
      return true;
    }
    return false;
  }
  
  void update(){
    velocity.add(acceleration);
    location.add(velocity);
    if(!seed){
      lifespan -=5;
      velocity.mult(0.9);
    }
    acceleration.mult(0);
  }
  
  void display(){
    pushStyle();
    stroke(hu,255,255,lifespan);
    if(seed){
      strokeWeight(4);
    }else{
      strokeWeight(2);
    }
    pushMatrix();
    translate(location.x,location.y,location.z);
    point(0,0);
    popMatrix();
    popStyle();
  }
  boolean isDead(){
    if(lifespan<0.0)return true;
    return false;
  }
}
