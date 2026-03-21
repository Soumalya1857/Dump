class Solution { // test case failing for wrong answer, not sure why!!! :(
    double radius;
    double x_center;
    double y_center;

    double lower_x_limit;
    double upper_x_limit;

    public Solution(double radius, double x_center, double y_center) {
        this.radius = radius;
        this.x_center = x_center;
        this.y_center = y_center;

        this.lower_x_limit = x_center - radius;
        this.upper_x_limit = x_center + radius;
    }
    
    public double[] randPoint() {
        double random_x_coord = this.lower_x_limit + (this.upper_x_limit - this.lower_x_limit) * Math.random();
        return new double[] {random_x_coord, getRandomYcoordinate(random_x_coord)};
    }

    private double getRandomYcoordinate(double x_coord) {
        // (x-xc)2 + (y-yc)2 = r2
        double root = Math.sqrt((radius*radius) - (x_coord - this.x_center)*(x_coord - this.x_center));
        double minYcoord = Math.min(root + this.y_center, -1*root + this.y_center);
        double maxYcoord = Math.max(root + this.y_center, -1*root + this.y_center);

        return minYcoord + (maxYcoord - minYcoord) * Math.random();
    }
}

// https://leetcode.com/problems/generate-random-point-in-a-circle/submissions/1953277340/

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(radius, x_center, y_center);
 * double[] param_1 = obj.randPoint();
 */



//=========================================================================
// Rejection sampling 
// https://leetcode.com/problems/generate-random-point-in-a-circle/solutions/6655436/master-random-point-generation-inside-a-ux0my/

// Generate a point in x*y rectangle, check if lies inside he circle, do it in an infinite loop

class Solution {
    constructor(radius, x_center, y_center) {
        this.radius = radius;
        this.xc = x_center;
        this.yc = y_center;
    }

    randPoint() {
        while (true) {
            const x = Math.random() * 2 * this.radius - this.radius;
            const y = Math.random() * 2 * this.radius - this.radius;
            if (x * x + y * y <= this.radius * this.radius) {
                return [this.xc + x, this.yc + y];
            }
        }
    }
}

class Solution {
    double radius;
    double x_center;
    double y_center;

    double lower_y_limit;
    double upper_y_limit;

    double lower_x_limit;
    double upper_x_limit;

    public Solution(double radius, double x_center, double y_center) {
        this.radius = radius;
        this.x_center = x_center;
        this.y_center = y_center;

        // this.lower_x_limit = x_center - radius;
        // this.upper_x_limit = x_center + radius;

        // this.lower_y_limit = y_center - radius;
        // this.upper_y_limit = y_center + radius;
    }
    
    public double[] randPoint() {
        while(true){
            // double random_x_coord = this.lower_x_limit + (this.upper_x_limit - this.lower_x_limit) * Math.random();
            // double random_y_coord = this.lower_y_limit + (this.upper_y_limit - this.lower_y_limit) * Math.random();

            // if(random_x_coord*random_x_coord + random_y_coord*random_y_coord <= this.radius*this.radius) {
            //     return new double[] {random_x_coord, random_y_coord};
            // }

            double x = Math.random() * 2 * this.radius - this.radius; // 0,0 center of rectange
            double y = Math.random() * 2 * this.radius - this.radius;

            if(x*x + y*y <= this.radius * this.radius){
                return new double[]{x+this.x_center, y+this.y_center};
            }
        }
    }
}

// https://leetcode.com/problems/generate-random-point-in-a-circle/submissions/1953277340/

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(radius, x_center, y_center);
 * double[] param_1 = obj.randPoint();
 */



// =============================================================================================
class Solution {
private double r, x, y;
    private Random rand = new Random();
    public Solution(double radius, double x_center, double y_center) {
     r = radius;
        x = x_center;
        y = y_center;      
    }
    
    public double[] randPoint() {
        double len = Math.sqrt(rand.nextDouble()) * r;
        double deg = rand.nextDouble() * 2 * Math.PI;
        return new double[]{
            x + len * Math.cos(deg),
            y + len * Math.sin(deg)
        };
    }
}
