class Player{
  int hp;
  int score;
  Player(){
    hp = 10;
    score = 0;
  }
  
  void view(){
    pushMatrix();
      translate(mouseX,mouseY);
      rotateY(PI/2);
      drawCar(10,color(0,255,0));
    popMatrix();
  }

  void isdamage(){
    if(bullets!=null){
      for(int i=0;i<bullets.size();i++){
        if(bullets.get(i).isHit(mouseX,mouseY,0,-1,i)){
          hp -=1;
        }
      }
    }
    for(Enemy enemy:enemies){
     float x = (mouseX-enemy.location.x)*(mouseX-enemy.location.x);
     float y = (mouseY-enemy.location.y)*(mouseY-enemy.location.y);
     float z = enemy.location.z*enemy.location.z;
     if(sqrt(x+y+z)<35)hp-=1;
    }
  }
  void getscore(){
  score +=1; 
}

void scoreDisp(){
  textSize(24);
  fill(255);
  text("score:"+score,10,25);
  text("HP:"+player.hp,300,25);
}

void displayScore(){
  colorMode(HSB);
  if(random(1)<0.2)fireworks.add(new Firework());
   pushStyle();
    pushMatrix();
    translate(width/2,height,0);
  for (int i = fireworks.size()-1; i >= 0; i--) {
    Firework f = fireworks.get(i);
    f.run();
    if (f.done())fireworks.remove(i);
  }
  popMatrix();
  fill(60,100,100);
  text("score:"+score,width/2-50,height/2);
  popStyle();
  //text("game over ",width/2-80,height/2-20);
}
}

void player(){
  player.view();
  player.isdamage();
}
