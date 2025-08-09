public class Company{
    
    private int n;
    Company(){
        this.n = 0;
    }

    public void produce() throws InterruptedException {
        n++;
        System.out.println("Produced " + n);
        Thread.sleep(1000);

    }

    public void consume() throws InterruptedException {
        System.out.println("Consumed " + n);
        Thread.sleep(3000);
    }
}