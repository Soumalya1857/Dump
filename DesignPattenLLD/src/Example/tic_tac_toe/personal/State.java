package Example.tic_tac_toe.personal;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class State {
    private List<List<Symbol>> boardState;
    private int dimension;

    public State(int dimension){
        this.dimension = dimension;
        boardState = new ArrayList<>();

        for(int i=0; i<dimension; i++){
            boardState.add(Collections.nCopies(dimension, Symbol.NULL));
        }
    }
}
