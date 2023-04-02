final int N = 256;
float [][] h = new float[N+1][N+1];
int w = N;

void setup(){
  size(800,800,P3D);
  frameRate(30);
  randomSeed(millis());
  h[0][0]=h[N][0]=h[0][N]=h[N][N] = 0;
}

void mouseClicked(){
  generate();
}

void generate(){
  if(w==1)return;
  for(int x =0;x<N;x+=w){
    for(int y = 0;y<N;y+=w){
      h[x+w/2][y]=(h[x][y]+h[x+w][y])/2+rnd();
      h[x][y+w/2]=(h[x][y]+h[x][y+w])/2+rnd();
      h[x+w/2][y+w/2]=(h[x][y]+h[x+w][y]+h[x+w][y+w]+h[x][y+w])/4+rnd();
    }
  }
  for(int i=0;i<N;i+=N){
    h[i+w/2][N] = (h[i][N]+h[i+w][N])/2+rnd();
    h[N][i+w/2] = (h[N][i]+h[N][i+w])/2+rnd();
  }
  w/=2;
}
float rnd(){
  return random(-0.2,+0.2)*w;
}

void draw(){
  background(50,50,150);
  lights();
  translate(width/2,height/2);
  rotateX(PI/4);
  rotateZ(radians(frameCount));
  noStroke();
  //fill(180,150,50);
  fill(255);
  scale(2.0);translate(-N/2,-N/2,0);
  beginShape(QUADS);
    for(int x = 0;x<N;x+=w){
      for(int y = 0;y<N;y+=w){
        vertex(x,y,h[x][y]);
        vertex(x,y+w,h[x][y+w]);
        vertex(x+w,y+w,h[x+w][y+w]);
        vertex(x+w,y,h[x+w][y]);
      }
    }
    endShape();
}
