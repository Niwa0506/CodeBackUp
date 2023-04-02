struct node { char*name;int num,edge[5],dist;};
struct node map[14] ={
	{"yokohama",3,{1,3,4},-1},//0
	{"kawasaki",3,{0,2,5},-1},//1
	{"shinagawa",3,{1,3,9},-1},//2
	{"osaki",3,{0,2,6},-1},//3
	{"hachiouji",1,{13},-1},//4
	{"tachikawa",3,{1,4,6},-1},//5
	{"shinjuku",4,{3,5,8,7},-1},//6
	{"ikebukuro",3,{6,11,12},-1},//7
	{"ochanomizu",3,{6,9,10},-1},//8
	{"tokyo",3,{2,8,10},-1},//9
	{"akihabara",3,{8,9,11},-1},//10
	{"tabata",3,{7,10,12},-1},//11
	{"akabane",2,{7,11},-1},//12
	{"toyota",1,{13},-1}//13

};