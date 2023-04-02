ArrayList<Water> waters;
PVector gravity = new PVector(0,0.9,0);

void setup(){
  size(600,600,P3D);
  frameRate(30);
  waters = new ArrayList<Water>();
}
int flag=0;
void draw(){
  background(255);
  if(flag==1){
  for(int i=0;i<100;i++)waters.add(new Water());
  for(int i=0;i<waters.size();i++){
    waters.get(i).run();
    if(waters.get(i).water.isDead())waters.remove(i);
  }
  }
  flag=1;
}

class Water{
  ArrayList<Particle> particles;
  Particle water;
  float hu;
  Water(){
    hu = random(255);
    water = new Particle(0,height/2,random(-400,0),hu);
  }
  void run(){
    if(water!=null){
      water.applyForce(gravity);
      if(water.velocity.y<0)
      water.applyForce(new PVector(random(-2,2),0,random(-2,2)));
      water.update();
      water.display();
    }
  }
}

class Particle {
  PVector location;
  PVector velocity;
  PVector acceleration;
  float lifespan;
  float col;
  boolean seed = false;
  
  float hu;
  
  Particle(float x, float y, float z,float h){
    hu = h;
    acceleration = new PVector(0,0);
    velocity = new PVector(random(-1,1),random(-70,-50),random(-1,1));
    location = new PVector(x,y,z);
    //col = abs(x)/width*4;
    lifespan = 255.0;
  }
  
  void applyForce(PVector force){
    acceleration.add(force);
  }
  
  void run(){
    update();
    display();
  }
  
  void update(){
    velocity.add(acceleration);
    location.add(velocity);
    //if(location.y<-height/4)velocity.y*=-1;
    lifespan -=5;
    //lifespan-=1;
    velocity.mult(0.9);
    acceleration.mult(0);
  }
  
  void display(){
    //stroke(234,85,50,lifespan);
    stroke(157,204,224);
    strokeWeight(4);
    pushMatrix();
    translate(width/2,height/2,0);
    translate(location.x,location.y,location.z);
    //sphere(1);
    point(0,0);
    popMatrix();
  }
  boolean isDead(){
    if(lifespan<0.0/*||velocity.y>0*/)return true;
    return false;
  }
}
