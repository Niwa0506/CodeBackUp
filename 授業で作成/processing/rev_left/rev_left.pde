void setup(){
  size(480,300);
  background(255);
  PImage src = loadImage("check.png");
  src.resize(480,300);
  PImage rev = reverse(src);
  image(rev,0,0);
}

 PImage reverse(PImage src){
   PImage src_rev= createImage(src.width,src.height,RGB);
   src.loadPixels();
   int i=src.width-1,y=0,j=0,hw = src.width/2;
   for(int p = 0;p < src.width*src.height;p++){
     if(p<hw+y*src.width){src_rev.pixels[p]=src.pixels[p];}
     else{src_rev.pixels[p]= src.pixels[y*src.width+hw-j];j++;}
     if(p==src.width-1+y*src.width){
       y+=1;j=0;
     }
   }
   src_rev.updatePixels();
   return src_rev;
 }
