Quadtree qtree;
public void setup (){

size(400 ,400);
background(0);
  qtree = new Quadtree (new Rectangle (width/2 , height/2 , width/2 , height/2) , 4);
}

public void draw (){
  if(mousePressed){
    for (int i  = 0 ; i < 5 ; i++){
       qtree.insert(new Point ( mouseX +random(-5,5) , mouseY+random(-5,5)));
    }
  }
  qtree.show();

  
} 
