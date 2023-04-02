PImage bakuha;
void effect(Enemy e){
  int n = e.count,d=0;
  if(n>7){d=1;n-=8;}
  bakuha = loadImage("explode.png");
  pushMatrix();
    translate(e.location.x,e.location.y,e.location.z);
    PImage pimg = bakuha.get(n*bakuha.width/8,d*bakuha.height/2,bakuha.width/8,bakuha.height/2);
    pimg.resize(100,100);
    image(pimg,-bakuha.width/16,-bakuha.height/4);
  popMatrix();
  e.count+=1;
  if(e.count>15)e.create();
}
