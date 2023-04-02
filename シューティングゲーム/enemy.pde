class Enemy{
  PVector location;
  PVector speed;
  int hp;
  int count;
  Enemy(){
    location = new PVector(int(random(width)),int(random(height/2+50)),-500);
    speed = new PVector(0,0,int(random(2,6)));
    hp = 10;
    count = -1;
  }
  void create(){
    location = new PVector(int(random(width)),int(random(height/2+50)),-500);
    hp = 10;
    count = -1;
  }
  
  void run(){
    move();
    show();
    isdamage();
  }
  
  void move(){
    if(int(random(100))%26==0)bullets.add(new Bullet(location.x,location.y,location.z,10));
    if(count==-1)location.add(speed);
    if(location.z>500)create();
  }
  
  void show(){
    if(count==-1){
      pushMatrix();
        translate(location.x,location.y,location.z);
        rotateY(-PI/2);
        drawCar(10,color(255,0,0));
      popMatrix();
    }else{
      effect(this);
    }
  }
  void isdamage(){
    if(bullets!=null){
      for(int i=0;i<bullets.size();i++){
        if(bullets.get(i).isHit(location.x,location.y,location.z,1,i))hp-=1;
        if(hp<=0&&count==-1){
          count+=1;player.score+=1;
        }    
      }
    }
  }
  
}

void enemies(){
  for(Enemy enemy:enemies)enemy.run();
  
}
