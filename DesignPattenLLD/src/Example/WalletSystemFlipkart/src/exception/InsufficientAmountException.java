package Example.WalletSystemFlipkart.src.exception;

public class InsufficientAmountException extends RuntimeException{
    public InsufficientAmountException() {
    }

    public InsufficientAmountException(String message) {
        super(message);
    }
}
