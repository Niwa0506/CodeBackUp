float theta;
int level;
class TREE{
  ArrayList<TREE> branch = null;
  int c;
  int theta =0;
  TREE(){}
  void s(int i){
    c = i;
  }
  void s_theta(int i){
    theta = i;
  }
  void s_branch(ArrayList<TREE> i){
    branch = i;
  }
}
ArrayList<TREE> current_list;
ArrayList<TREE> next_list;
void setup(){
  size(640,480);
  background(255);
  current_list = new ArrayList<TREE>();
  next_list = new ArrayList<TREE>();
  translate(width/2,height/4*3);
  line(0,0,0,float(width/4));
  set_list(1,1,1);
  int n = current_list.size();
  int k = 4;
  next_list = copy(current_list,next_list);
  //print_list(next_list);
  //current_list.get(0).c = 5;
  //print_l(next_list);
  //print_l(current_list);
  
  for(int i=0;i<k;i++){
    print_l(current_list);
    making(current_list,next_list);
    current_list = copy(next_list,current_list);
    //println("result");print_l(current_list);print_l(next_list);
  }
    //drawKoch(list,k,height);
  print_l(current_list);
}
//do each branch
void making(ArrayList<TREE> l1,ArrayList<TREE> l2){
  for(int i=0;i<l1.size();i++){
    if(l1.get(i).branch!=null)making(l1.get(i).branch,l2.get(i).branch);
  }
  doing(l1,l2);
}

ArrayList<TREE> copy(ArrayList<TREE> l1,ArrayList<TREE> l2){
  for(int i=0;i<l1.size();i++){
    if(l2.size()-1<i)l2.add(new TREE());
    l2.get(i).c = l1.get(i).c;
    if(l1.get(i).branch !=null){l2.get(i).branch = new ArrayList<TREE>();copy(l1.get(i).branch,l2.get(i).branch);}
  }
  return l2;
}

void doing(ArrayList<TREE> l1,ArrayList<TREE> l2){
  for(int i=0;i<l1.size();i++){l2.get(i).c=judge(i,l1,l2);}
}

int search(ArrayList<TREE> l){
  int n =0;
  for(int i =0;i<l.size();i++){
    if(l.get(i).branch!=null)n += l.get(i).branch.size()+1;
    else n+=1;
  }
  return n;
}

void set_list(int i, int j, int k){
   TREE tree1 = new TREE();
   TREE tree2 = new TREE();
   TREE tree3 = new TREE();
   tree1.s(i);
   tree2.s(j);
   tree3.s(k);
   current_list.add(tree1);
   current_list.add(tree2);
   current_list.add(tree3);
}

int judge(int i,ArrayList<TREE> l1,ArrayList<TREE> l2){
  if(i>0&&i<l1.size()-1){//println("judge");print_l(l2);println("l1");print_l(l1);
    if(l1.get(i-1).c==0&&l1.get(i).c==0&&l1.get(i+1).c==0)return 0;
    else if(l1.get(i-1).c==0&&l1.get(i).c==0&&l1.get(i+1).c==1){ 
            ArrayList<TREE> tree_list = new ArrayList<TREE>();
            TREE tree1 = new TREE();TREE tree2 = new TREE();
            tree1.s(1);tree2.s(1);tree1.s_theta(1);
            tree_list.add(tree1);tree_list.add(tree2);
            l2.get(i).s_branch(tree_list);
            return 1;//[+F1F1]
    }
    else if(l1.get(i-1).c==0&&l1.get(i).c==1&&l1.get(i+1).c==0) return 1;
    else if(l1.get(i-1).c==0&&l1.get(i).c==1&&l1.get(i+1).c==1) return 1;
    else if(l1.get(i-1).c==1&&l1.get(i).c==0&&l1.get(i+1).c==0) return 0;
    else if(l1.get(i-1).c==1&&l1.get(i).c==0&&l1.get(i+1).c==1){
          TREE tree1 = new TREE();
          tree1.s(1);  
          l2.add(i+1,tree1);
          return 1;//1F1
    }
    else if(l1.get(i-1).c==1&&l1.get(i).c==1&&l1.get(i+1).c==0) return 0;
    else if(l1.get(i-1).c==1&&l1.get(i).c==1&&l1.get(i+1).c==1) return 0;
    else if(l1.get(i).c == 2)return 3;
    else if(l1.get(i).c == 3)return 2;
  }
  return l1.get(i).c;
}
void drawKoch(ArrayList<TREE> l, int level, float length){
  float edge = length/level;
  for(int i=0;i<search(l);i++){
    if(l.get(i).theta==1)rotate(PI/3);
    else if(l.get(i).theta==2)rotate(-PI/3);
    line(0,0,0,edge);
    translate(0,edge);
    if(l.get(i).branch!=null&&l.get(i).c==1)drawKoch(l.get(i).branch,level,length);
  }
}

void print_list(ArrayList<TREE> l){
  for(int i=0;i<l.size();i++){
    print(l.get(i).c);
    if(l.get(i).branch!=null){print("[");print_list(l.get(i).branch);print("]");}
  }
  //println();
}

void print_l(ArrayList<TREE> l){
  print_list(l);
  println();
}
