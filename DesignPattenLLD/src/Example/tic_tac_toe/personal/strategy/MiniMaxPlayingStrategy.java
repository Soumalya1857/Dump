package Example.tic_tac_toe.personal.strategy;

import Example.tic_tac_toe.personal.State;

import java.util.List;

public class MiniMaxPlayingStrategy implements IPlayingStrategy{
    @Override
    public List<Integer> nextMove(State state) {
        System.out.println("Minimax playing strategy activated");
        return null;
    }
}
