float[][] prewittH = {{-1, 0, 1}, {-1, 0, 1}, {-1, 0, 1}};//horizontaldirection
float[][] prewittV = {{-1, -1, -1}, {0, 0, 0}, {1, 1, 1}};//verticaldirection
PImage img;
float[] filtx,filty;
void setup(){
  size(150, 240);
  PImage src = loadImage("penguin.jpg");
  background(255);
  src.resize(width,height);
  img = src;
  filtx = filtering(src, prewittH);
  filty = filtering(src, prewittV);
}

void draw(){
  int i =int(random(img.width));
  int j =int(random(img.height));
  int r,g,b,p=j*width+i;
  r = int(red(img.pixels[p]));
  g = int(green(img.pixels[p]));
  b = int(blue(img.pixels[p]));
  fill(r,g,b);
  calc(p);
}
float[] filtering(PImage img,float f[][]){
  float[] diff =new float[img.width * img.height];//arrayforsavedfferentials
  for(int j = 1; j < img.height - 1; j++){//scan image
    for(int i = 1; i < img.width - 1; i++){
      float sum = .0;
      for(int l = -1; l <= 1; l++)//filtering process
        for(int k = -1; k <= 1; k++){
          float x=f[l + 1][k + 1] * color(img.pixels[(j + l) * img.width + i + k]);
          sum += x;
        }
      diff[j * img.width + i] = sum;
    }
  }
     return diff;
}

void calc(int p){
  float dx,dy,norm,ta;int n=0;
  dx =  filtx[p];
  dy =  filty[p];
  ta = atan(dy/dx);
  norm = sqrt((dx*dx)+(dy*dy));
  noStroke();
  pushMatrix();
  translate(p%img.width,p/img.width);
  rotate(ta);
   while(int(norm/10)!=0){norm /=10;n++;}
   n *=n;
   n/=5;
  ellipse(0,0,0.5*n,1.75*n);
  img.updatePixels();
  popMatrix();
}
  
