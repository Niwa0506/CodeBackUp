int[] p;
int[] permutation;
double[][] terrain;
int scl = 20;
int w = 2000;
int h = 1600;
double max = 0;
void setup(){
  size(256,256);
  permutation = new int[256];
  for(int i=0;i<256;i++)permutation[i] = int(random(256));
  p = new int[512];
  for(int i=0;i<256;i++)p[i] = p[i+256] = permutation[i%256];
  terrain = new double[256][256];
  float x = -1;
  for(int i=0;i<256;i++){
    float y = -1;
    for(int j=0;j<256;j++){
       terrain[i][j] = perlin(noise(x,y),noise(x,y),noise(x,y));
       if(max<terrain[i][j])max=terrain[i][j];
       y+=.1;
    }
    x+=.1;
  } 
  max/=5;
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

float abs(double x){
  if(x>0)return (float)x;
  else return (float)(-x);
}
int flag(double x,double y){
  if(x<y)return 1;
  else if(x<2*y)return 2;
  else if(x<3*y)return 3;
  else if(x<4*y)return 4;
  else return 5;
}

boolean verse(double h){
  if(h>0)return false;
  else return true;
}
void draw(){
  background(0);
  noStroke();
  /*
  float flying =0;
  flying-=1;
    float yoff = flying;
    for(int y=0;y<256;y++){
      float xoff = 0;
      for(int x = 0;x<256;x++){
        terrain[x][y] = noise(xoff,yoff);
        xoff+=.2;
      }
      yoff+=.2;
    }
    */
  for(int x=0;x<256;x++){
    for(int y=0;y<256;y++){
     double h = terrain[x][y];
     double g = abs(h);
     int j = flag(g,max);
     if(verse(h))fill(0,0,255-j*50);
     else fill(j*50,0,0);
     ellipse(x,y,1,1);
    }
  }
}
 
