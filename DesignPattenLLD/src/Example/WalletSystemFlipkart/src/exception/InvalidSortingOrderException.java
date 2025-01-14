package Example.WalletSystemFlipkart.src.exception;

public class InvalidSortingOrderException extends RuntimeException{
    public InvalidSortingOrderException() {
    }

    public InvalidSortingOrderException(String message) {
        super(message);
    }
}
