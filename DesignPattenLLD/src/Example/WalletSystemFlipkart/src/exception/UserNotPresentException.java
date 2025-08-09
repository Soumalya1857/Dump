package Example.WalletSystemFlipkart.src.exception;

public class UserNotPresentException extends RuntimeException{
    public UserNotPresentException() {
    }

    public UserNotPresentException(String message) {
        super(message);
    }
}
