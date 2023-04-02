float th = 128.;
PImage src;
void setup(){
  size(480, 300);
  src = loadImage("check.png");
}
PImage binarize(PImage img){
  PImage bimg = createImage(img.width, img.height, ALPHA);
  img.loadPixels();
for(int p = 0; p < img.width * img.height; p++){
  if(red(img.pixels[p]) > th) bimg.pixels[p] = color(255);
  else bimg.pixels[p] = color(0);
}
bimg.updatePixels();
  return bimg;
}
void mouseMoved(){ 
  th = 255. * mouseX / width; 
}

void draw(){
  image(src, 0, 0,480,300);
  image(binarize(src),0,0,480,300);
}
