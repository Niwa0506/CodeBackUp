PImage img;
void setup(){
  size(360, 420);
  background(255);
  noStroke();
  img = loadImage("check.png");
  img.resize(360,420);
  draw_rev();
  image(img,0,0);
  }
void draw_rev(){
  float r,g,b;
  img.loadPixels();
  for(int p=0;p<img.width*img.height;p++){
    r = 255-red(img.pixels[p]);
    g = 255-green(img.pixels[p]);
    b = 255-blue(img.pixels[p]);
   img.pixels[p] = color(r,g,b);
}
  img.updatePixels();
}
