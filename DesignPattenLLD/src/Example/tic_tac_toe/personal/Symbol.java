package Example.tic_tac_toe.personal;

public final class Symbol {
    private String symbolCode;
    public static final Symbol X = new Symbol("X");
    public static final Symbol O = new Symbol("O");
    public static final Symbol NULL = new Symbol("NULL");

    public Symbol(String str){
        this.symbolCode = str;
    }
}
