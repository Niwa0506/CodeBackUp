Game game;
void setup(){
  size(400,300,P3D);
  noStroke();
  frameRate(60);
  game = new Game();
}


void draw(){
  game.update();
}

class Game{
  Enemy[] enemies;
  ArrayList<Bullet>bullets;
  Player player;
  int flag=0;
  ArrayList<Firework> fireworks;
  PVector gravity = new PVector(0,0.4);
  Star star;
  PImage bakuha;
  Ground ground1;
  Ground ground2;
  Design design;
  Game(){
    enemies = new Enemy[10];
    bullets = new ArrayList<Bullet>();
    fireworks = new ArrayList<Firework>();
    star = new Star();
    bakuha = loadImage("explode.png");
    //ground1 = new Ground(20,2000,1600);
    design = new Design();
    ground2 = new Ground();
    for(int i=0;i<10;i++){
      Enemy e = new Enemy();
      enemies[i]=e;
    }
    player = new Player();
  }
  void back(){
    background(0);
    star.make();
    lights();
    //ground1.update();
    ground2.update2();
  }
  
  void update(){
   back();
   if(flag==0){
     if(keyPressed)
     if(key==' ')bullets.add(new Bullet(mouseX,mouseY,-100,-10));
     player.scoreDisp();
     enemies();
     player();
     bullets();
     isgameover();
     }else{player.displayScore();}
  }
  void isgameover(){
    if(player.hp<=0){flag=1;}
  }
  void player(){
    player.view();
    player.isdamage();
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
    ArrayList<Bullet> bullets = game.bullets;
    if(bullets.size()>i)bullets.remove(i);
  }
   
  void bullets(){
    ArrayList<Bullet> bullets = game.bullets;
    if(bullets!=null)
      for(int i=0;i<bullets.size();i++)bullets.get(i).run();
  }
  
  void enemies(){
    for(Enemy enemy:game.enemies)enemy.run();
  }
}
//particle of firework
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
  }
  boolean isDead(){
    if(lifespan<0.0)return true;
    return false;
  }
}
//firework of background
class Firework{
  ArrayList<Particle> particles;
  Particle firework;
  float hu;
  
  Firework(){
    hu = random(255);
    firework = new Particle(random(-width/2,width/2),height/2,random(-400,0),hu);
    particles = new ArrayList<Particle>();
  }
  
  boolean done(){
    if(firework == null&&particles.isEmpty())return true;
    return false;
  }
  void run(){
    PVector g = game.gravity;
    if(firework!=null){
      fill(hu,255,255);
      firework.applyForce(g);
      firework.update();
      firework.display();
      
      if(firework.explode()){
        for(int i=0;i<750;i++){
          particles.add(new Particle(firework.location,hu));
        }
        firework = null;
      }
    }
    for(int i=particles.size()-1;i>=0;i--){
      Particle p = particles.get(i);
      p.applyForce(g);
      p.run();
      if(p.isDead())particles.remove(i);
    }
  }
  boolean dead(){
    if(particles.isEmpty())return true;
    return false;
  }
}
//ground of background
class Ground{
  int cols;
  int rows;
  int scl;
  int w=2000;
  int h=1600;
  float flying=0;
  float[][] terrain;
  double[][] nn;
  int[] p;
  int[] permutation;
  
  Ground(int scl,int w,int h){
    this.scl = scl;
    this.w = w;
    this.h = h;
    this.cols = w/scl;
    this.rows = h/scl;
    terrain = new float[cols][rows];
  }
  
  Ground(){
    permutation = new int[256];
    for(int i=0;i<256;i++)permutation[i]=int(random(256));
    p = new int[512];
    for(int i=0;i<256;i++)p[i]=p[i+256]=permutation[i];
    nn = new double[256][256];
    make_random();
  }
  
  void update(){
    flying -=1;
    float yoff = flying;
    for(int y=0;y<rows;y++){
      float xoff = 0;
      for(int x = 0;x<cols;x++){
        terrain[x][y] = map(noise(xoff,yoff),0,1,-100,100);
        xoff+=.2;
      }
      yoff+=.2;
    }
    fill(163,104,64);
    pushStyle();
      ambient(164,104,64);
    pushMatrix();
      translate(width/2,height/2+100,-100);
      rotateX(PI/2);
      translate(-w/2,-h/2);
      for(int y=0;y<rows-1;y++){
        beginShape(TRIANGLE_STRIP);
        for(int x= 0;x<cols;x++){
          vertex(x*scl,y*scl,terrain[x][y]);
          vertex(x*scl,(y+1)*scl,terrain[x][y+1]);
        }
        endShape();
      }
    popMatrix();
    popStyle();
  }
  
  void update2(){
    //make_random();
    fill(163,104,64);
    pushStyle();
      pushMatrix();
      ambient(164,104,64);
      translate(width/2,height/2+200,-100);
      rotateX(PI/2);
      translate(-w/2,-h/2);
      for(int xa = 0;xa<255;xa++){
        beginShape(TRIANGLE_STRIP);
        for(int y = 0;y<256;y++){
          float xx = (float)nn[xa][y];
          float xx2 = (float)nn[xa+1][y];
          vertex(xa*20,20*y,300*xx);
          vertex(20*(xa+1),20*y,300*xx2);
        }
        endShape();
      }
      popMatrix();
    popStyle();
  }
  void make_random(){
    float x=-1;
    for(int i=0;i<256;i++){
      float y=-1;
      for(int j=0;j<256;j++){
        nn[i][j] = perlin(noise(x,y),noise(x,y),noise(x,y));
        y+=.1;
      }
      x+=.1;
    }
  }
  double perlin(double x,double y,double z){
   int X =(int)Math.floor(x)&255;
   int Y =(int)Math.floor(y)&255;
   int Z =(int)Math.floor(z)&255;
   X -=Math.floor(x);
   Y -=Math.floor(y);
   Z -=Math.floor(z);
   double u = fade(x);
   double v = fade(y);
   double w = fade(z);
   int A = p[X]+Y,AA = p[A]+Z,AB = p[A+1]+Z;
   int B = p[X+1]+Y,BA = p[B]+Z,BB= p[B+1]+Z;
   return lerp(w,lerp(v,lerp(u,grad(p[AA],x,y,z),
                                grad(p[BA],x-1,y,z)),
                         lerp(u,grad(p[AB],x,y-1,z),
                                grad(p[BB],x-1,y-1,z))),
                  lerp(v,lerp(u,grad(p[AA+1],x,y,z-1),
                                grad(p[BA+1],x-1,y,z-1)),
                         lerp(u,grad(p[AB+1],x,y-1,z-1),
                                grad(p[BB+1],x-1,y-1,z-1))));
  }
  double fade(double t){
    return t*t*t*(t*(t*6-15)+10);
  }
  double lerp(double t,double a,double b){
    return a+t*(b-a);
  }

  double grad(int hash,double x,double y,double z){
    int h = hash&15;
    double u = h<8?x:y;
    double v = h<4 ?y:h==12||h==14?x:z;
    return ((h&1) ==0 ? u:-u)+((h&2)==0?v:-v);
  }
}

//star of background
class Star{
  int x;
  int y;
  int z;
  float[] dist;
  float[] dr;
  float[] dg;
  float[] db;
  Star(){
    x = int(random(width));
    y = int(random(height));
    dist = new float[25];
    dr = new float[25];
    dg = new float[25];
    db = new float[25];
    for(int x = 25;x>0;x--){
      dist[x-1] = sq(x);
      dist[x-1] /=25;
      dr[x-1] = constrain(int(80/dist[x-1]),0,255);
      dg[x-1] = constrain(int(80/dist[x-1]),0,255);
      db[x-1] = constrain(int(200/dist[x-1]),0,255);
    }
  }
  void make(){
    pushMatrix();
    translate(0,0,-700);
      pushStyle();
        emissive(255);
        shininess(255);
        for(int i = 25;i>0;i--){
          fill(dr[i-1],dg[i-1],db[i-1]);
          ellipse(width/2,height/2,i*25,i*25);
        }
        filter(BLUR,5);
      popStyle();
    popMatrix();
  }
}
//bullet
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
    game.crash();
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
    if(sqrt(xx+yy+zz)<25&&10*check!=direction.z){game.vanish(i);return true;}
    return false;
  }
}


//enemy
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
    speed = new PVector(0,0,int(random(2,6)));
    hp = 10;
    count = -1;
  }
  
  void run(){
    move();
    show();
    isdamage();
  }
  
  void move(){
    if(int(random(100))%26==0)game.bullets.add(new Bullet(location.x,location.y,location.z,10));
    if(count==-1)location.add(speed);
    if(location.z>500)create();
  }
  
  void show(){
    if(count==-1){
      pushMatrix();
        translate(location.x,location.y,location.z);
        rotateY(-PI/2);
        game.design.drawCar(10,color(255,0,0));
      popMatrix();
    }else{
      effect();
    }
  }
  void isdamage(){
    if(game.bullets!=null){
      for(int i=0;i<game.bullets.size();i++){
        if(game.bullets.get(i).isHit(location.x,location.y,location.z,1,i))hp-=1;
        if(hp<=0&&count==-1){
          count+=1;game.player.score+=1;
        }    
      }
    }
  }
  void effect(){
    int n = count,d=0;
    
    if(n>7){d=1;n-=8;}
    pushMatrix();
    translate(location.x,location.y,location.z);
    PImage pimg = game.bakuha.get(n*game.bakuha.width/8,d*game.bakuha.height/2,game.bakuha.width/8,game.bakuha.height/2);
    pimg.resize(100,100);
    image(pimg,-game.bakuha.width/16,-game.bakuha.height/4);
    popMatrix();
    count+=1;
    if(count>15)create();
  }
}
//machine_design
class Design{
  float wide;
  float h;
  Design(){
    wide = 1.5;
    h = -.5;
  }
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
}
//player

class Player{
  int hp;
  int score;
  Player(){
    hp = 10;
  }
  
  void view(){
    pushMatrix();
      translate(mouseX,mouseY);
      rotateY(PI/2);
      game.design.drawCar(10,color(0,255,0));
    popMatrix();
  }

  void isdamage(){
    if(game.bullets!=null){
      for(int i=0;i<game.bullets.size();i++){
        if(game.bullets.get(i).isHit(mouseX,mouseY,0,-1,i)){
          hp -=1;
        }
      }
    }
    for(Enemy enemy:game.enemies){
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
    text("HP:"+hp,300,25);
  }

  void displayScore(){
    colorMode(HSB);
    if(random(1)<0.2)game.fireworks.add(new Firework());
    pushStyle();
      lights();
      ambient(255,255,0);
      fill(255,255,0);
      pushMatrix();
        translate(width/2,height,0);
        for (int i = game.fireworks.size()-1; i >= 0; i--) {
          Firework f = game.fireworks.get(i);
          f.run();
          if (f.done())game.fireworks.remove(i);
        }
      popMatrix();
    popStyle();
    //text("game over ",width/2-80,height/2-20);
    text("score:"+score,width/2-50,height/2);
  }
}
