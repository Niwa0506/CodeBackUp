class Ground{
  /*
  int cols;
  int rows;
  int scl;
  */
  int w=2000;
  int h=1600;
  float flying;
  float[][] terrain;
  double[][] nn;
  int[] p;
  int[] permutation;
  /*
  Ground(int scl,int w,int h,float flying){
    this.scl = scl;
    this.w = w;
    this.h = h;
    this.flying = flying;
    this.cols = w/scl;
    this.rows = h/scl;
    terrain = new float[cols][rows];
  }
  */
  Ground(){
    permutation = new int[256];
    for(int i=0;i<256;i++)permutation[i]=int(random(256));
    p = new int[512];
    for(int i=0;i<256;i++)p[i]=p[i+256]=permutation[i];
    nn = new double[256][256];
  }
  /*
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
  */
  void update2(){
    float x=-1;
    for(int i=0;i<256;i++){
      float y=-1;
      for(int j=0;j<256;j++){
        nn[i][j] = perlin(noise(x,y),noise(x,y),noise(x,y));
        y+=.1;
      }
      x+=.1;
    }
    pushStyle();
      fill(163,104,64);
      ambient(164,104,64);
    pushMatrix();
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
