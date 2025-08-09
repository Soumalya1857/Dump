package Example.WalletSystemFlipkart.src.exception;

public class InvalidAmountDetectedException extends RuntimeException{
    public InvalidAmountDetectedException() {
    }

    public InvalidAmountDetectedException(String message) {
        super(message);
    }
}
