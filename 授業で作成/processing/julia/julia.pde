int textHeight = 30,n = 0;
int max = 1000000,min = -max,max_ite = 100,max_colors = 8;
float min_re,max_re,min_im,max_im,re = .35,im = .4;
color[]c = new color[max_colors];
void  setup(){
  size(600, 600);
  textFont(createFont("Tempus Sans ITC", 24));
  min_re = min_im = -(max_re = max_im = 2.);
  int q = 256 / max_colors;//setcolors
  for(int i = 0; i < max_colors; i++) c[i] = color(0,float((i + 1) * q - 1), 0);
}

void drawJulia(float c_re,float c_im){
  double re, im, f_re, f_im;
  double re_step = (max_re - min_re) / width;
  double im_step = (max_im - min_im) / height;
  for(int j = 0; j < height; j++){
    for(int i = 0; i < width; i++){
      im = min_im + im_step * j;
      re = min_re + re_step * i;
      int ite = 0;
      do{//checkconvergenceornot
        f_re = re * re - im * im + c_re;
        f_im = 2 * re * im + c_im;
        re = f_re;
        im = f_im;
      }while(f_re * f_re + f_im * f_im < 4. && ite++ < max_ite);
      if(ite < max_ite){//changecoloraccordingtoconvergencelevel
        stroke(c[ite % c.length]);
        point(i, j);
      }
    }
  }
}

void mouseMoved(){
  re = 2 * (mouseX /float(width) - .5);
  im = 2 * (mouseY /float(height) - .5);
  background(0);
  drawJulia(re, im);
  text("c = "+ re +" + "+ im +"i", 10, textHeight);
 }
void draw(){}
