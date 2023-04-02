PImage img;
void setup(){
  size(480, 320);
  background(255);
  noStroke();
  img = loadImage("check.png");
  img.loadPixels();
  img.resize(width,height);
  //image(img,0,0);
}

void draw(){
  int i =int(random(img.width));
  int j =int(random(img.height));
  int r,g,b,p=j*width+i;
  r = int(red(img.pixels[p]));
  g = int(green(img.pixels[p]));
  b = int(blue(img.pixels[p]));
  fill(r,g,b);
  pushMatrix();
  translate(p%img.width,p/img.width);
  rotate(-45);
  ellipse(0,0,10,5);
  img.updatePixels();
  popMatrix();
}
