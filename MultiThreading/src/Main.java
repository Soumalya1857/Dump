
public class Main {
    public static void main(String[] args) {
        System.out.println("main is starting ......");

        UserThread thread1 = new UserThread("User Thread");
        thread1.start();

        Thread thread = new Thread(new RunnableThread(), "Runnable Thread");
        thread.start();

        System.out.println("main is existing....");
    }
}