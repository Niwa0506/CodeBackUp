// parameters
final float A = 0.001;
final float B = 0.01;
final int W = 10;

// resource
PImage koara;
color[] k_pixs;
color[] koara_bilateral;
int w, h;

void setup() {
  size(600,300);
  koara = loadImage("penguin.jpg");
  koara.resize(300,300);
  w = koara.width;
  h = koara.height;
  k_pixs = koara.pixels;
  koara_bilateral = new color[h*w];
  for (int i=0; i<h*w; i++) { koara_bilateral[i]=color(100); }
  image(koara,0,0);
}


void draw() {
  for (int y=W; y<h-W; y++) {
    for (int x=W; x<w-W; x++) {
      color c = bilateral(x, y);
      koara_bilateral[y*w+x] = c;
      set(x, y, koara_bilateral[y*w+x]);
    }
  }
  image(koara, w,0);
  k_pixs=koara_bilateral.clone();
}

color bilateral(int i, int j) {
  float sum_r = 0.0;
  float W_3_r = 0.0;
  float sum_g = 0.0;
  float W_3_g = 0.0;
  float sum_b = 0.0;
  float W_3_b = 0.0;
  for (int n=-W; n<=W; n++) {
    for (int m=-W; m<=W; m++) {
      color c_ij = k_pixs[i+j*w];
      color c_nm = k_pixs[(i+n)+(j+m)*w];
      sum_r += gauss(n*n+m*m, pow(red(c_ij)-red(c_nm), 2), A, B)*red(c_nm);
      W_3_r += gauss(n*n+m*m, pow(red(c_ij)-red(c_nm), 2), A, B);
      sum_g += gauss(n*n+m*m, pow(green(c_ij)-green(c_nm), 2), A, B)*green(c_nm);
      W_3_g += gauss(n*n+m*m, pow(green(c_ij)-green(c_nm), 2), A,B);
      sum_b += gauss(n*n+m*m, pow(blue(c_ij)-blue(c_nm), 2), A,B)*blue(c_nm);
      W_3_b += gauss(n*n+m*m, pow(blue(c_ij)-blue(c_nm), 2), A, B);
    }
  }
  return color(sum_r/W_3_r, sum_g/W_3_g, sum_b/W_3_b);
}

float gauss(float x, float y, float a, float b) {
  return exp(-a*x-b*y);
}
