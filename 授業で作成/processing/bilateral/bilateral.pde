PImage src;
float[][] gaussianFilter;
int w = 5;//filterwidth
int hw =int(w / 2);//halfsizeoffilterwidth
float s1=1000,s2=100;
void setup(){
  size(1200, 250);
  background(255);
  src = loadImage("penguin.jpg");
   src.resize(240,250);
  image(src,0,0);
  PImage filt = src;
  for(int r = 1;r<5;r++){
    filt = filtering(filt); 
    image(filt,filt.width*r,0);
  }
}

PImage filtering(PImage img){
  PImage filteredImg = createImage(img.width, img.height, RGB);
  img.loadPixels();
  filteredImg.loadPixels();
  for(int j = hw; j < img.height - hw; j++){//scan image
    for(int i = hw; i < img.width - hw; i++){
      float sum_r = .0, sum_g = .0, sum_b = .0;
      float sum_rw = .0,sum_gw = .0,sum_bw =.0;
      for(int l = -hw; l <= hw; l++){//filter in process
        for(int k = -hw; k <= hw; k++){
          int p = (j + l) * img.width + i + k;
          color c_ij = img.pixels[j*img.width+i];
          color c_lk = img.pixels[p];
          sum_r   += (exp((-l*l-k*k)/2./s1)*exp(-pow(red(c_ij)-red(c_lk),2)/2./s2))*red(c_lk);
          sum_rw  += (exp((-l*l-k*k)/2./s1)*exp(-pow(red(c_ij)-red(c_lk),2)/2./s2));
          sum_g   += (exp((-l*l-k*k)/2./s1)*exp(-pow(green(c_ij)-green(c_lk),2)/2./s2)) * green(c_lk);
          sum_gw  += (exp((-l*l-k*k)/2./s1)*exp(-pow(green(c_ij)-green(c_lk),2)/2./s2));
          sum_b   += (exp((-l*l-k*k)/2./s1)*exp(-pow(blue(c_ij)-blue(c_lk),2)/2./s2)) * blue(c_lk);
          sum_bw  += (exp((-l*l-k*k)/2./s1)*exp(-pow(blue(c_ij)-blue(c_lk),2)/2./s2));
        }
      }
      filteredImg.pixels[j * img.width + i] = color(sum_r/sum_rw, sum_g/sum_gw, sum_b/sum_bw);
    }
  }
  filteredImg.updatePixels();
  return (filteredImg);
}
