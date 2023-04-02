package model.game;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Observable;

import javax.swing.Timer;

import model.character.CharacterManager;
import model.character.NPC;
import model.character.Position;

public class Game extends Observable implements ActionListener {

	/*
	 * DISMISS_RANGE: 解散適応半径
	 */
	public static final int DISMISS_RANGE = 100;
	CharacterManager characterManager;
	int time = 0;
	boolean isGameOver;
	private Timer timer;
	private ScoreTime scoreTime;
	private Ranking ranking;


	public Game() {
		timer = new Timer(33, this);
		this.characterManager = new CharacterManager();
		scoreTime = new ScoreTime();
		ranking = new Ranking();
		initGame();
		start();
	}

	public boolean isGameOver() {
		return this.isGameOver;
	}

	public void initGame() {
		stop();
		this.time = 0;
		this.characterManager.init();
		this.scoreTime.init();
	}

	public void start() {
		this.isGameOver = false;
		scoreTime.setStartTime(System.currentTimeMillis());
		timer.start();
	}

	public void stop() {
		this.isGameOver = true;
		timer.stop();
		ranking.add(new Score(scoreTime.getScore(), "ゲスト"));
	}

	public CharacterManager getCharacterManager() {
		return this.characterManager;
	}

	public ScoreTime getScoreTime() {
		return scoreTime;
	}

	public void update() {
		characterManager.update();
		time++;
		setChanged();
		notifyObservers();

		scoreTime.setEndTime(System.currentTimeMillis());
	}

	/*
	 * 解散
	 */
	public void dismiss() {
		Position p1 =  characterManager.getPlayer().getPosition();
		for(int i = 0; i < characterManager.getCharacters().size(); i++) {
			if(characterManager.getCharacters().get(i)  instanceof NPC) {
				NPC npc = (NPC)characterManager.getCharacters().get(i);
				Position p2 = npc.getPosition();
				if((p1.getX() - p2.getX()) * (p1.getX() - p2.getX()) + (p1.getY() - p2.getY()) * (p1.getY() - p2.getY()) < DISMISS_RANGE*DISMISS_RANGE) {
					npc.dismiss();
				}
			}
		}
	}

	/*
	 * サーモグラフィー 廃止
	 */

	public void actionPerformed(ActionEvent e) {
		update();
	}
}
