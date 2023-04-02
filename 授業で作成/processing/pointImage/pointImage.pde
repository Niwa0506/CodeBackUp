PImage img;
void setup(){
  size(360, 420);
  background(255);
  noStroke();
  img = loadImage("check.png");
  }
void draw(){
  int i =int(random(img.width));
  int j =int(random(img.height));
  int r,g,b;
  img.loadPixels();
  r = int(red(img.pixels[i*j]));
  g = int(green(img.pixels[i*j]));
  b = int(blue(img.pixels[i*j]));
  fill(r,g,b);
  ellipse(width/2,height/2,100,100);
}
