float[][] prewittH = {{-1, 0, 1}, {-1, 0, 1}, {-1, 0, 1}};//horizontaldirection
float[][] prewittV = {{-1, -1, -1}, {0, 0, 0}, {1, 1, 1}};//verticaldirection
int[][]bin;
PImage img;
int g,q;
float[] filt1,filt2;
float[] max_v = new float[2];
int o=0;
void setup(){
  size(300, 480);
  PImage src = loadImage("penguin.jpg");
  background(255);
  src.resize(width,height);
  img = src;
  bin = new int[src.width*src.height][3];
  filt1 = filtering(src, prewittH);
  filt2 = filtering(src, prewittV);
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
  PImage filteredImg = createImage(img.width, img.height, ALPHA);
  float[] diff =new float[img.width * img.height];//arrayforsavedfferentials
  float min = 1000, max = -1000,max_l=0;int max_i=0,max_j=0;
  for(int j = 1; j < img.height - 1; j++){//scan image
    for(int i = 1; i < img.width - 1; i++){
      float sum = .0;max_l=.0;max_i=i;max_j=j;
      for(int l = -1; l <= 1; l++)//filtering process
        for(int k = -1; k <= 1; k++){
          float x=f[l + 1][k + 1] * color(img.pixels[(j + l) * img.width + i + k]);
          sum += x;
          if(max_l<x){max_l=x;max_i=i+k;max_j=j+l;}
        }
      if(sum < min) min = sum;
      else if(sum > max){max = sum;g=i;q=j;}
      diff[j * img.width + i] = sum;
      /*bin[j*width+i][0]=max_i;
      bin[j*width+i][1]=max_j;*/
    }
  }
   max_v[o++] = max > abs(min) ? max : abs(min);
   /*for(int p = 0; p < img.width * img.height; p++){
     diff[p] = (1-abs(diff[p] / max_v));
   }*/
     return diff;
}

void calc(int p){
  float dx,dy,norm,ta;int n=0,m=0;
  dx =  filt1[p];
  dy =  filt2[p];
  float ddx=dx,ddy = dy;
  while(int(ddx/10)!=0){ddx /=10;n++;}
  while(int(ddy/10)!=0){ddy /=10;m++;}
  norm = sqrt((n*n)+(m*m));
  ta = atan(dy/dx);
  noStroke();
  pushMatrix();
  translate(p%img.width,p/img.width);
  rotate(ta);
  ellipse(0,0,0.5*norm,1.75*norm);
  img.updatePixels();
  popMatrix();
}
  
