void setup(){
  size(480, 300);
  PImage src = loadImage("check.png");
  image(src,0,0,480,300);
  PImage gray = color2gray(src);
  image(gray, src.width, 0);
  gray.save("rockyGray.jpg");
}
PImage color2gray(PImage colorImg){
  PImage grayImg = createImage(colorImg.width, colorImg.height, ALPHA);
  colorImg.loadPixels();
  for(int p = 0; p < colorImg.width * colorImg.height; p++){
    float r = red(colorImg.pixels[p]);
    float g = green(colorImg.pixels[p]);
    float b = blue(colorImg.pixels[p]);
    grayImg.pixels[p] = color((r + g + b) / 3.);
  }
grayImg.updatePixels();
return grayImg;
}
