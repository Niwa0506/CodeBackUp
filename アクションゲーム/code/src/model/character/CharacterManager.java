package model.character;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Random;

import model.game.GameManager;
import model.game.HealthyNPCCount;

public class CharacterManager{
	public static final int MAX_NPC_COUNT = 50;
	public static final int INFECTABLE_RANGE = 100;
	public static final int INFECT_CHECK_INTERVAL = 5;
	private int interval = 0;

	private int countNPC;
	private int countInfectedNPC;
	private List<Character> characters;
	private Player player;
	private HealthyNPCCount healthyNPCCount;

	public CharacterManager() {
		characters = new ArrayList<Character>();
		healthyNPCCount = new HealthyNPCCount();
		player = new Player(new Position(50, 50));
		init();
	}

	public boolean checkIsGameOver() {
		if(healthyNPCCount.getValue() <= 5) {
			return true;
		}else {
			return false;
		}
	}

	public void init() {
		characters.clear();
		countNPC = 0;
		countInfectedNPC = 0;
		player.setPosition(new Position(50, 50));
		characters.add(0, player);

		Random r = new Random();
		for(int i = 0; i < 3; i++) {
			addNPC(new Position(r.nextInt(700) + 50 , r.nextInt(600)), true);
		}
		for(int i = 0; i < 50; i++) {
			addNPC(new Position(r.nextInt(700) + 50 , r.nextInt(600)), false);
		}
		healthyNPCCount.setValue(countNPC - countInfectedNPC);
	}

	private void addNPC(Position pos, boolean isInfected) {
		if(!isNPCFull()) {
			NPC npc = new NPC(pos, isInfected);
			characters.add(npc);
			countNPC++;
			if(isInfected) {
				countInfectedNPC++;
			}
		}
	}

	public HealthyNPCCount getHealthyNPCCount() {
		return healthyNPCCount;
	}

	/*
	 *  キャラクターのリストを取得。奥にいるプレイヤーから順番にリストに格納されている。
	 */
	public List<Character> getCharacters(){
		return this.characters;
	}

	public boolean isNPCFull() {
		return countNPC >= MAX_NPC_COUNT;
	}

	public Player getPlayer() {
		return player;
	}

	private void infect(NPC npc) {
		npc.infected();
		countInfectedNPC++;
		healthyNPCCount.setValue(countNPC - countInfectedNPC);
		if(checkIsGameOver()){
			GameManager.getInstance().getGame().stop();
		}
	}

	//2重forを使っていて且つほとんど同じような処理を毎フレーム実行するのは非効率であるから、呼び出し頻度を下げている。
	public void runInfectedProcess() {
		for(int i = 0; i < characters.size(); i++) {
			if(characters.get(i) instanceof NPC) {
				NPC npc = (NPC)(characters.get(i));
				if(npc.isStay()) {
					if(npc.getIsInfected()) {
						Position p1 = npc.getPosition();
						for(int j = 0; j < characters.size(); j++) {
							if(characters.get(j) instanceof NPC) {
								NPC healthyNPC = (NPC)characters.get(j);
								if(healthyNPC.isStay()) {
									if(!healthyNPC.getIsInfected()) {
										Position p2 = healthyNPC.getPosition();
										if((p1.getX() - p2.getX())*(p1.getX() - p2.getX()) + (p1.getY() - p2.getY())*(p1.getY() - p2.getY()) <= INFECTABLE_RANGE*INFECTABLE_RANGE) {
											healthyNPC.infectTime++;
											if(healthyNPC.infectTime > healthyNPC.getInfectNecessaryTime()) {
												infect(healthyNPC);
											}
										}
									}
								}
							}
						}

					}
				}
			}
		}

	}

	public void update() {
		for(Character character : characters) {
			//ポリモーフィズムの恩恵...
			character.update();
		}
		Collections.sort(characters, new NPCComparator());
		if(++interval % INFECT_CHECK_INTERVAL == 0) {
			runInfectedProcess();
		}
	}
}

class NPCComparator implements Comparator<Character> {
	@Override
	public int compare(Character o1, Character o2) {
		int y1 = o1.getPosition().getY();
		int y2 = o2.getPosition().getY();
		if(y1 > y2) {
			return 1;
		}else if(y1 == y2) {
			return 0;
		}else {
			return -1;
		}
	}
}
