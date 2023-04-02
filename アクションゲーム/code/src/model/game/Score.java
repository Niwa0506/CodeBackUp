package model.game;

import java.io.Serializable;

public class Score implements Serializable{
	int score;
	String name;
	Score(int score,String name){
		this.score = score;
		this.name = name;
	}
	public int getScore() {
		return score;
	}
	public String getName() {
		return name;
	}
	public void setScore(int score) {
		this.score =score;
	}
}
