void setup(){
  size(2400, 300);
  PImage src = loadImage("check.png");
  image(src, 0, 0,480,300);
  for(int i = 1; i < 5; i++)
    image(mosaic(src, 2*i),i*480,0,480,300);
}

PImage mosaic(PImage img,int w){
  PImage filteredImg = createImage(img.width, img.height, RGB);
  img.loadPixels();
  for(int j = 0; j < img.height / w * w; j += w){//processuntilw*npixels.
    for(int i = 0; i < img.width / w * w; i += w){//(int)/(int)=(int)
      float sum_r = .0, sum_g = .0, sum_b = .0;
      for(int l = 0; l < w; l++){//calculateaverageofwxwpixels
        for(int k = 0; k < w; k++){
          int p = (j + l) * img.width + i + k;
          sum_r += red(img.pixels[p]);
          sum_g += green(img.pixels[p]);
          sum_b += blue(img.pixels[p]);
        }
      }
      sum_r /= (w * w); sum_g /= (w * w); sum_b /= (w * w);
      for(int l = 0; l < w; l++)
        for(int k = 0; k < w; k++)//savefilteredimage
          filteredImg.pixels[(j + l) * img.width + (i + k)] = color(sum_r, sum_g, sum_b);
     }
  }
  filteredImg.updatePixels();
  return filteredImg;
}
