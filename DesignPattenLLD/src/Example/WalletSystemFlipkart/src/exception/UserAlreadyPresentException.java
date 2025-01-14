package Example.WalletSystemFlipkart.src.exception;

public class UserAlreadyPresentException extends RuntimeException{

    public UserAlreadyPresentException() {
    }

    public UserAlreadyPresentException(String msg){
        super(msg);
    }
}
