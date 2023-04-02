
  
void back(){
  background(0);
  pushMatrix();
    translate(0,0,-700);
  pushStyle();
    emissive(255);
    shininess(255);
    make_star();
  popStyle();
  popMatrix();
  lights();
  //cloud.update();
  ground.update2();
  //cloud.show();
}
void create_star(){
  for(int i=0;i<5;i++){
    star_x[i] = int(random(width));
    star_y[i] = int(random(height));
  }
  for(int x = 25;x>0;x--){
    dist[x-1] = sq(x);
    dist[x-1] /=25;
    dist_r[x-1] = constrain(int(80/dist[x-1]),0,255);
    dist_g[x-1] = constrain(int(80/dist[x-1]),0,255);
    dist_b[x-1] = constrain(int(200/dist[x-1]),0,255);
  }
}

void make_star(){
  pushStyle();
  for(int x = 25;x>0;x--){
    
    fill(dist_r[x-1],dist_g[x-1],dist_b[x-1]);
    ellipse(width/2,height/2,x*25,x*25);
  }
  filter(BLUR,5);
  popStyle();

}
