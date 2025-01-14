package Example.WalletSystemFlipkart.src.service;

import Example.WalletSystemFlipkart.src.exception.UserAlreadyPresentException;
import Example.WalletSystemFlipkart.src.exception.UserNotPresentException;
import Example.WalletSystemFlipkart.src.model.Flipkart;
import Example.WalletSystemFlipkart.src.model.User;
import Example.WalletSystemFlipkart.src.service.iservice.IFlipkartService;

import java.util.Objects;

public class FlipkartServiceImpl implements IFlipkartService {

    @Override
    public boolean registerUser(Flipkart flipkart, User user) throws RuntimeException{
        try{
            if(Objects.isNull(user)){
                throw new RuntimeException("User is null!");
            }

            if(flipkart.getUserMap().containsKey(user.getUserId())){
                throw new UserAlreadyPresentException("User with userId" + user.getUserId() + " already present in the system!");
            }

            flipkart.getUserMap().put(user.getUserId(), user);
            System.out.println(user.getUserName() + " registerd successfully!");
            return true;

        }catch (UserAlreadyPresentException e){
            throw new UserAlreadyPresentException(e.getMessage());
        }catch(RuntimeException e){
            throw new RuntimeException(e.getMessage());
        }
    }

    @Override
    public boolean deRegisterUser(Flipkart flipkart, User user) {
        try{
            if(Objects.isNull(user)){
                throw new RuntimeException("User is null!");
            }

            if(!flipkart.getUserMap().containsKey(user.getUserId())){
                throw new UserNotPresentException("User with userId" + user.getUserId() + " already present in the system!");
            }

            flipkart.getUserMap().remove(user.getUserId());
            System.out.println(user.getUserName() + " de-registerd successfully!");
            return true;

        }catch (UserNotPresentException e){
            throw new UserNotPresentException(e.getMessage());
        }catch(RuntimeException e){
            throw new RuntimeException(e.getMessage());
        }
    }
}
