PGraphics buffer1;
PGraphics buffer2;
PImage cooling;
int w = 600;
int h = 400;

float ystart = 0.0;
int[] p;
int[] permutation;
double[][] terrain;
double max;
void setup() {
  size(600, 400);
  buffer1 = createGraphics(w, h);
  buffer2 = createGraphics(w, h);
  cooling = createImage(w,h,RGB);
  permutation = new int[256];
  for(int i=0;i<256;i++)permutation[i] = int(random(256));
  p = new int[1024];
  for(int i=0;i<256;i++)p[i] = p[i+256] = p[i+512] = p[i+768]= permutation[i%256];
  terrain = new double[600][400];
}
void make_random(){
float x = -1;
  for(int i=0;i<600;i++){
    float y = -1;
    for(int j=0;j<400;j++){
       terrain[i][j] = perlin(noise(x,y),noise(x,y),noise(x,y));
       if(max<terrain[i][j])max=terrain[i][j];
       y+=.1;
    }
    x+=.1;
  } 
  max/=5;

}

void cool(){
  cooling.loadPixels();
  float xoff = 0.0; // Start xoff at 0
  float increment = 0.02;
  // For every x,y coordinate in a 2D space, calculate a noise value and produce a brightness value
  for (int x = 0; x < w; x++) {
    xoff += increment;   // Increment xoff 
    float yoff = ystart;   // For every xoff, start yoff at 0
    for (int y = 0; y < h; y++) {
      yoff += increment; // Increment yoff
      // Calculate noise and scale by 255
      double n = noise(xoff,yoff);
      float bright = pow((float)n, 3) * 255;
      //if(xoff<1)println("n"+n);
      cooling.pixels[x+y*w] = color(bright);
    }
  }

  cooling.updatePixels();
  ystart += increment;
}
void fire(int rows) {
  buffer1.beginDraw();
  buffer1.loadPixels();
  for (int x = 0; x < w; x++) {
    for (int j = 0; j < rows; j++) {
      int y = h-(j+1);
      int index = x + y * w;
      buffer1.pixels[index] = color(255);//color(233,163,38);
    }
  }
  buffer1.updatePixels();
  buffer1.endDraw();
}

void draw() {
  fire(2);
  if (mousePressed) {
    buffer1.beginDraw();
    buffer1.fill(255);
    buffer1.noStroke();
    buffer1.ellipse(mouseX, mouseY, 100, 100); 
    buffer1.endDraw();
  }
  cool();
  background(0);
  buffer2.beginDraw();
  buffer1.loadPixels();
  buffer2.loadPixels();
  for (int x = 1; x < w-1; x++) {
    for (int y = 1; y < h-1; y++) {
      int index0 = (x) + (y) * w;
      int index1 = (x+1) + (y) * w;
      int index2 = (x-1) + (y) * w;
      int index3 = (x) + (y+1) * w;
      int index4 = (x) + (y-1) * w;
      color c1 = buffer1.pixels[index1];
      color c2 = buffer1.pixels[index2];
      color c3 = buffer1.pixels[index3];
      color c4 = buffer1.pixels[index4];
      color c5 = cooling.pixels[index0];
      float newC = brightness(c1) + brightness(c2)+ brightness(c3) + brightness(c4);
      newC = newC * 0.25 - brightness(c5);

      buffer2.pixels[index4] = color(newC);
    }
  }
  buffer2.updatePixels();
  buffer2.endDraw();
  
  // Swap
  PGraphics temp = buffer1;
  buffer1 = buffer2;
  buffer2 = temp;
  PImage buffer3 = buffer2.get(width/2-width/4,height/2+height/4,width/4,height/4);
  PImage buffer4 = buffer3.get(buffer3.width/2,buffer3.height/2,buffer3.width/2,buffer3.height/2);
  buffer4.resize(600,400);
  image(buffer4, 0, 0);
  //image(cooling,w,0);
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
