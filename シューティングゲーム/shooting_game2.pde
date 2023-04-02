Enemy[] enemies;
ArrayList<Bullet>bullets;
Player player;
//int score;
int flag=0;
ArrayList<Firework> fireworks;
PVector gravity = new PVector(0,0.4);
int[] star_x = new int[5];
int[] star_y = new int[5];
int[] star_size = new int[5];
float[] dist = new float[25];
float[] dist_r = new float[25];
float[] dist_g = new float[25];
float[] dist_b = new float[25];
Ground ground;
//Cloud cloud;
void setup(){
  size(400,300,P3D);
  noStroke();
  frameRate(30);
  enemies = new Enemy[10];
  bullets = new ArrayList<Bullet>();
  fireworks = new ArrayList<Firework>();
  create_star();
  //ground = new Ground(20,2000,1600,0);
  ground = new Ground();
  //cloud = new Cloud();
  for(int i=0;i<10;i++){
    Enemy e = new Enemy();
    enemies[i]=e;
  }
  player = new Player();
}

void isgameover(){
  if(player.hp<=0){flag=1;}
}

void draw(){
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
