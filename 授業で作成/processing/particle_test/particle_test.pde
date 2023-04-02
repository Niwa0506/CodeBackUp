PVector gravity = new PVector(0,0.4);
ArrayList<Particle> fireworks;
int n=0;
void setup(){
  size(600,600);
  background(0);
  fireworks = new ArrayList<Particle>();
  fireworks.add(new Particle(width/2,height/2,255-n));
  fill(255);
  textSize(24);
  text("n="+n,30,30);
}

void mousePressed(){
  background(0);
  for(int i=0;i<fireworks.size();i++){
    Particle f = fireworks.get(i);
    f.run();
  }
  fill(255);
  text("n="+n,10,10);
  n+=1;
}
void draw(){}

class Particle {
  PVector location;
  PVector velocity;
  float hu;
  int done =-1;
  Particle(float x, float y,float h){
    hu = h;
    //velocity = new PVector(0,random(-25,-10));
    location = new PVector(x,y);
  }
  
  Particle(PVector l,float h){
    hu = h;
    velocity  = PVector.random2D();
    velocity.mult(random(50,100));
    location = l.copy();
    location.add(velocity);
  }
  
  void run(){
    display();
    explode();
    done+=1;
  }
  
  void display(){
    noStroke();
    pushStyle();
    fill(hu*50,hu*30,255);
    pushMatrix();
      translate(location.x,location.y);
      ellipse(0,0,5,5);
    popMatrix();
    popStyle();
  }
  void explode(){
    if(done==0)for(int i=0;i<10;i++){done+=1;fireworks.add(new Particle(location,n+1));}
  }
}
