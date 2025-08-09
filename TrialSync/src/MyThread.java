class MyThread extends Thread{
    private boolean flag;
    private Company company;

    MyThread(boolean flag, Company company){
        super();
        this.company = company;
        this.flag = flag;
    }

    public void run(){
        int n = 10;
        while(n > 0){
            n--;
            if(flag){
                try {
                    synchronized (company) {
                        company.produce();
                    }
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
            } else{
                try {
                        company.consume();
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
            }
        }
    }
}