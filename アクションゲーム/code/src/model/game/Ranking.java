package model.game;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class Ranking {
	ArrayList<Score> ranking =new ArrayList<Score>();int i=0;
	public Ranking() {
			File file = new File("ranking.dat");
				 if (!file.exists())
					try {
						file.createNewFile();
					} catch (IOException e) {
						e.printStackTrace();
					}
			try (
			FileInputStream f = new FileInputStream("ranking.dat");
			BufferedInputStream b = new BufferedInputStream(f);
			ObjectInputStream in = new ObjectInputStream(b) ){
			ranking= (ArrayList<Score>)in.readObject();i=1;
		}catch(IOException e) {
			if(i==1)e.printStackTrace();
		}catch(ClassNotFoundException e) {
			e.printStackTrace();
		}
	}
	public void saveData() {
		try(FileOutputStream f = new FileOutputStream("ranking.dat");
			BufferedOutputStream b = new BufferedOutputStream(f);
			ObjectOutputStream out = new ObjectOutputStream(b)){
			out.writeObject(ranking);
		}catch(IOException e) {
			e.printStackTrace();
		}
		//確認用
		for(int i=0;i<ranking.size();i++)
			System.out.println(ranking.get(i).getScore()+" "+ranking.get(i).getName());
	}
	public void add(Score player) {
		int flag=0;
		if(ranking.size()!=0) {
		for(int i=0;i<ranking.size();i++) {
			if(ranking.get(i).getName().equals(player.getName())) {
				if(ranking.get(i).getScore()<player.getScore()) {
					ranking.get(i).setScore(player.getScore());
				}
				flag=1;break;
			}
		}
		if(flag==0){ranking.add(player);}
		}else{ranking.add(player);}
		Collections.sort(ranking,new MyComp());
	}
	class MyComp implements Comparator<Score> {
	    public int compare(Score c1, Score c2) {
	        if(c1.getScore() < c2.getScore()) {
	            return -1;
	        } else if(c1.getScore() > c2.getScore()) {
	            return 1;
	        } else {
	            return c1.getName().compareTo(c2.getName());
	        }
	    }
	}

}
