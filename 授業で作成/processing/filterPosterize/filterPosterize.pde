size(480, 300);
PImage img = loadImage("check.png");
image(img,0,0,480,300);
img.filter(POSTERIZE, 4);
image(img,0,0,480,300);
save("filterPosterize.png");
