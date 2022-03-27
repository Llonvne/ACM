package user.userGroup.authentication;

/**
 * 类名:     Authentication
 * 描述:
 * 隶属于:   GradeManager
 * 建立事件： 2022/3/21
 * 作者：    llonvne
 * 邮箱：    Work@llonvne.cn
 * Copyright (c) 2022,All rights reserved.
 */
public class Authentication implements AuthenticationInterface{
    @Override
    public boolean userLogin(UserCertificate userCertificate, String password) {
        return false;
    }

    @Override
    public boolean resetPassword(UserCertificate userCertificate, String password) {
        return false;
    }
}
