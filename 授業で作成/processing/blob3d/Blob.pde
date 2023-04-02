 class Blob{
 PVector pos;
 float r;
 PVector vel;
 Blob(float x, float y){
    pos = new PVector(x,y);
    vel = PVector.random3D();
    vel.mult(random(2,5));
    r = 40;
    
  }
  void update(){
    pos.add(vel);
    if(pos.x>width||pos.x<0){
      vel.x *=-1;
    }
    if(pos.y>height||pos.y<0){
      vel.y *=-1;
    }
  }
  void show(){
    noFill();
    stroke(0);
    strokeWeight(4);
    pushMatrix();
      translate(pos.x,pos.y);
      sphere(r*2);
    popMatrix();
  }
}
