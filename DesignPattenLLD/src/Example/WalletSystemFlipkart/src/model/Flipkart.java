package Example.WalletSystemFlipkart.src.model;

import java.util.HashMap;
import java.util.Map;

public class Flipkart {

    Map<String, User> userMap;

    public Flipkart(){
        userMap = new HashMap<>();
    }

    public Map<String, User> getUserMap() {
        return userMap;
    }

    public void setUserMap(Map<String, User> userMap) {
        this.userMap = userMap;
    }
}
