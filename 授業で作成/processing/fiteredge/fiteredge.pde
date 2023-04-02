float[][] sobelH = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};//horizontaldirection
float[][] sobelV = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};//verticaldirection
void setup(){
  size(360, 150);
  PImage src = loadImage("penguin.jpg");
  src.resize(120,150);
  image(src, 0, 0);
  image(filtering(src, sobelH), src.width, 0);
  image(filtering(src, sobelV), 2 * src.width, 0);
}

PImage filtering(PImage img, float f[][]){
  PImage filteredImg = createImage(img.width, img.height, ALPHA);
  float[] diff =new float[img.width * img.height];//arrayforsavedfferentials
  float min = 1000, max = -1000;
  for(int j = 1; j < img.height - 1; j++){//scanimage
    for(int i = 1; i < img.width - 1; i++){
      float sum = .0;
      for(int l = -1; l <= 1; l++)//filteringprocess
        for(int k = -1; k <= 1; k++)  
          sum += f[l + 1][k + 1] * color(img.pixels[(j + l) * img.width + i + k]);
     if(sum < min) min = sum;
     else if(sum > max) max = sum;
     diff[j * img.width + i] = sum;
   }
 }
 float max_v = max > abs(min) ? max : abs(min);
 filteredImg.loadPixels();
 for(int p = 0; p < img.width * img.height; p++)//savemagnitude
   filteredImg.pixels[p] = color(255 * (1 - abs(diff[p] / max_v)));
 filteredImg.updatePixels();
 return (filteredImg);
}
