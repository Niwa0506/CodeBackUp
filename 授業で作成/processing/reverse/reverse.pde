void setup(){
  size(960,300);
  background(255);
  PImage src = loadImage("check.png");
  src.resize(480,300);
  image(src,0,0);
  PImage rev = reverse(src);
  image(rev,src.width,0);
}

 PImage reverse(PImage src){
   PImage src_rev= createImage(src.width,src.height,RGB);
   src.loadPixels();
   int i=src.width-1,y=0,j=0;
   
   for(int p = 0;p < src.width*src.height;p++){
     src_rev.pixels[p] = src.pixels[y*src.width+i-j];j++;
     if(p==src.width-1+y*src.width){
       y+=1;j=0;
     }
   }
   src_rev.updatePixels();
   return src_rev;
 }
