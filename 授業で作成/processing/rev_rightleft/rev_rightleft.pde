void setup(){
  size(1440,300);
  background(255);
  PImage src = loadImage("check.png");
  src.resize(480,300);
  image(src,0,0);
  PImage rev_right = reverse_right(src);
  image(rev_right,src.width,0);
  PImage rev_left = reverse_left(src);
  image(rev_left,src.width+rev_right.width,0);
  
}

 PImage reverse_right(PImage src){
   PImage src_rev= createImage(src.width,src.height,RGB);
   src.loadPixels();
   int i=src.width-1,y=0,j=0,hw = src.width/2;
   for(int p = 0;p < src.width*src.height;p++){
     if(p>hw+y*src.width){src_rev.pixels[p]=src.pixels[p];}
     else{src_rev.pixels[p]= src.pixels[y*src.width+i-j];j++;}
     if(p==src.width-1+y*src.width){
       y+=1;j=0;
     }
   }
   src_rev.updatePixels();
   return src_rev;
 }
 
 PImage reverse_left(PImage src){
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
