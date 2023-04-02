#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 256

struct node{
  int value;
  struct node *left;
  struct node *right;
};

int search_breadth1(int key, struct node *remain[]){
  int idx = 0;
  int last = 1;

  while(remain[idx] != NULL){
    if(remain[idx]->value == key){
      return 1;
    }else{
      if(remain[idx]->left != NULL){ remain[last++] = remain[idx]->left; }
      if(remain[idx]->right != NULL){ remain[last++] = remain[idx]->right; }
      idx++;
    }
  }

  return 0;
}

int search_breadth(struct node *root, int key){
  struct node *remain[BUFSIZE];
  int i;

  remain[0] = root;
  for(i = 1; i < BUFSIZE; i++){ remain[i] = NULL; }

  return search_breadth1(key, remain);
}

struct node *addnode(struct node *root, int depth, int val){
  struct node *n, *new;

  new = (struct node *)malloc(sizeof(struct node));
  new->value = val;
  new->left = new->right = NULL;

  if(root == NULL){
    return new;
  }else{
    n = root;
  }

  for( ; depth > 1; depth--){
    if(n->right != NULL){
      n = n->right;
    }else if(n->left != NULL){
      n = n->left;
    }else{
      return NULL;
    }
  }

  if(n->left == NULL){
    n->left = new;
  }else if(n->right == NULL){
    n->right = new;
  }else{
    return NULL;
  }

  return root;
}

struct node *loaddata(char *filename){
  int depth, val;
  FILE *input;
  struct node *root = NULL;
  char line[BUFSIZE];

  input = fopen(filename, "r");
  if(input == NULL){
    fprintf(stderr, "Can't open file: %s\n", filename);
    exit(1);
  }

  while(fgets(line, sizeof(line), input) != NULL){
    depth = 0;
    while(line[depth] == ' '){
      depth++;
    }

    sscanf(&line[depth], "%d", &val);
    root = addnode(root, depth, val);
    if(root == NULL){
      fprintf(stderr, "illegal input file: %s\n", line);
      exit(1);
    }
  }

  fclose(input);

  return root;
}

int main(int ac, char **av){
  int result;
  struct node *root;

  if(ac != 3){
    fprintf(stderr, "Usage: %s <datafile> <key>\n", av[0]);
    exit(1);
  }

  root = loaddata(av[1]);

  result = search_breadth(root, atoi(av[2]));

  printf("Key \"%s\" is %s.\n", av[2], result == 1 ? "found" : "not found");

  return 0;
}
