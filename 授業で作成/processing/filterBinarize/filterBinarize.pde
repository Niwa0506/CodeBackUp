size(480,300);
PImage img = loadImage("check.png");
image(img,0,0,480,300);
img.filter(THRESHOLD,.7);
image(img,0,0,480,300);
