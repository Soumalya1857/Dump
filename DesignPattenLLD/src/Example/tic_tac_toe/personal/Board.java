package Example.tic_tac_toe.personal;

import java.util.List;

public class Board {
    private State currentState;
    private Integer dimension;
    private List<Player> playerList;

    private Player currPlayer;

    public Board(State currentState, Integer dimension, List<Player> playerList){
        this.currentState = currentState;
        this.dimension = dimension;
        this.playerList = playerList;
    }

    public Player getNextPlayer(){
        return null;
        // set currPlayer also
    }

    public State getCurrentState(){
        return this.currentState;
    }

    private boolean calculateWinner(){
        return false;
    }

    public boolean drawMove(List<Integer> move){
        // assign move

        return calculateWinner()
;    }

}
