ArrayList<Fire> fires;
PVector gravity = new PVector(0,0,0);

void setup(){
  size(600,600,P3D);
  frameRate(30);
  fires = new ArrayList<Fire>();
}
int flag=0;
void draw(){
  background(255);
  if(flag==1){
  for(int i=0;i<100;i++)fires.add(new Fire());
  for(int i=0;i<fires.size();i++){
    fires.get(i).run();
    if(fires.get(i).fire.isDead())fires.remove(i);
  }
  }
  flag=1;
}

class Fire{
  ArrayList<Particle> particles;
  Particle fire;
  float hu;
  Fire(){
    hu = random(255);
    fire = new Particle(0,height/2,random(-400,0),hu);
  }
  void run(){
    if(fire!=null){
      fire.applyForce(gravity);
      if(fire.velocity.x>0)fire.applyForce(new PVector(-.4,0,0));
      fire.applyForce(new PVector(0,random(-1.5,1),random(-1,1)));
      fire.update();
      fire.display();
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
    velocity = new PVector(random(50,70),0,random(-1,1));
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
    //if(location.x>width/4*3)velocity.x*=-.2;
    lifespan -=5;
    //lifespan-=1;
    velocity.mult(0.9);
    acceleration.mult(0);
  }
  
  void display(){
    emissive(255,255,0);
    stroke(234,85,50);
    //stroke(240,160,25,lifespan);
    //stroke(157,204,224,lifespan);
    strokeWeight(4);
    pushMatrix();
    translate(0,0);
    translate(location.x,location.y,location.z);
    point(0,0);
    popMatrix();
  }
  boolean isDead(){
    if(lifespan<0.0/*||location.x<width/4*3*/)return true;
    return false;
  }
}
