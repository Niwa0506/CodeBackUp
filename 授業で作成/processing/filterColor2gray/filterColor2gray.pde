size(480, 300);
PImage img = loadImage("check.png");

image(img, 0, 0,480,300);
img.filter(GRAY);
image(img, 0, 0,480,300);
img.save("rockyGray.jpg");
