size(480, 300);
PImage img = loadImage("check.png");
image(img, 0, 0);
img.filter(INVERT);
image(img,0,0,480,300);
