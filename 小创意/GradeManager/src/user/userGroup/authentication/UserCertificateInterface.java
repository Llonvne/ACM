package user.userGroup.authentication;

import user.userGroup.UserGroup;

public interface UserCertificateInterface {
    // 异步登入
    public boolean setLoginUsername(UserGroup ug,String username);
    public boolean setLoginPassword(String password);
    public boolean login();
    // 直接登入
    public boolean login(UserGroup userGroup, String username, String password);

    // 退出
    public void logout();
}
