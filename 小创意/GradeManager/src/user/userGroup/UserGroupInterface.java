package user.userGroup;

import user.UserTypes.User;

public interface UserGroupInterface {
    // 获得用户句柄
    public UserReport getUserHandle(String name);
    public boolean isUserExist(User user);
    // 增加用户
    public UserReport insertUser(User user);
    // 删除用户
    public UserReport deleteUser(User user);
}

