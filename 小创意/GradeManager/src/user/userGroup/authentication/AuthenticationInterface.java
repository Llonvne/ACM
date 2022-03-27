package user.userGroup.authentication;

import user.UserTypes.User;
import user.userGroup.UserReport;

public interface AuthenticationInterface {
    public boolean userLogin(UserCertificate userCertificate,String password);
    public boolean resetPassword(UserCertificate userCertificate,String password);
}
