package user.userGroup;

import user.UserTypes.User;

/**
 * 类名:     UserGroup
 * 描述:
 * 隶属于:   GradeManager
 * 建立事件： 2022/3/21
 * 作者：    llonvne
 * 邮箱：    Work@llonvne.cn
 * Copyright (c) 2022,All rights reserved.
 */
public class UserGroup implements UserGroupInterface{
    @Override
    public UserReport getUserHandle(String name) {
        return null;
    }

    @Override
    public boolean isUserExist(User user) {
        return false;
    }

    @Override
    public UserReport insertUser(User user) {
        return null;
    }

    @Override
    public UserReport deleteUser(User user) {
        return null;
    }
}
