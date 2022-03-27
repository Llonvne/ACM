package user.userGroup.authentication;

import user.UserTypes.User;
import user.userGroup.UserGroup;
import user.userGroup.UserReport;

/**
 * 类名:     UserCertificate
 * 描述:     用户证书
 * 隶属于:   GradeManager
 * 建立事件： 2022/3/21
 * 作者：    llonvne
 * 邮箱：    Work@llonvne.cn
 * Copyright (c) 2022,All rights reserved.
 */
public class UserCertificate implements UserCertificateInterface{
    // 用户是否登入信息
    private boolean isAuthenticated = false;
    // 用户句柄
    private User userHandle = null;
    // 用户组信息
    private UserGroup userGroup = null;
    // 密码
    private String password;


    @Override
    public boolean setLoginUsername(UserGroup ug,String username) {
        UserReport ur = ug.getUserHandle(username);
        if (!ur.isFound){
            return false;
        }
        userGroup = ug;
        userHandle = ur.userHandle;
        isAuthenticated = false;
        return true;
    }

    @Override
    public boolean setLoginPassword(String password) {
        if (userHandle != null && userGroup != null){
            this.password = password;
            return true;
        }
        return false;
    }

    @Override
    public boolean login() {
        if ()
    }

    @Override
    public boolean login(UserGroup userGroup, String username, String password) {

    }

    @Override
    public void logout() {
        this.isAuthenticated = false;
    }
}
