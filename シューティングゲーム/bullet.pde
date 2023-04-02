class Bullet{
  PVector location;
  PVector direction;
  
  Bullet(float x,float y,float z,int dir){
    location = new PVector(x,y,z);
    this.direction = new PVector(0,0,dir);
  }
  void run(){
    show();
    move();
    crash();
  }
  void show(){
    pushStyle();
    fill(0,0,255);
    pushMatrix();
      translate(location.x,location.y,location.z);
      sphere(4);
    popMatrix();
    popStyle();
  }
  void move(){
    location.add(direction);
  }
  boolean isHit(float x,float y,float z,float check,int i){
    float xx = (x-location.x)*(x-location.x);
    float yy = (y-location.y)*(y-location.y);
    float zz = (z-location.z)*(z-location.z);
    if(sqrt(xx+yy+zz)<25&&10*check!=direction.z){vanish(i);return true;}
    return false;
  }
}

void crash(){
  if(bullets!=null)
    for(int i=0;i<bullets.size();i++){
      if(bullets.get(i).direction.z>0){
        for(int j=i+1;j<bullets.size();j++){
          if(bullets.get(j).direction.z<0){
            float d = dist(bullets.get(i).location.x,bullets.get(i).location.y,bullets.get(i).location.z,
                           bullets.get(j).location.x,bullets.get(j).location.y,bullets.get(j).location.z);
            if(d<10){vanish(i);vanish(j);}
          }
        }
      }
    }
}

void vanish(int i){
  if(bullets.size()>i)bullets.remove(i);
}

void bullets(){
  if(bullets!=null)
    for(int i=0;i<bullets.size();i++)bullets.get(i).run();
}
