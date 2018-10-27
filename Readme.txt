this is first add file1

参考文章：
1. 搭建git服务器
https://www.liaoxuefeng.com/wiki/0013739516305929606dd18361248578c67b8067c8c017b000/00137583770360579bc4b458f044ce7afed3df579123eca000
2. 添加远程库 
https://www.liaoxuefeng.com/wiki/0013739516305929606dd18361248578c67b8067c8c017b000/0013752340242354807e192f02a44359908df8a5643103a000
3. 从远程库克隆
https://www.liaoxuefeng.com/wiki/0013739516305929606dd18361248578c67b8067c8c017b000/001375233990231ac8cf32ef1b24887a5209f83e01cb94b000


step 1. 搭建git服务器
1)安装git
2）创建一个git用户
sudo adduser git
3)创建证书登陆
  -在自己的PC端，执行“Git bash here”，调出git bash命令行
  -执行ssh-keygen，可以用默认内容，也可以指定路径和字符串
  -将id-rsa.pub文件的内容，拷贝，追加到/home/git/.ssh/authorized_keys文件中，一行一个。
  
4)初始化git仓库
  sudo git init --bare sample.git
  git就会创建一个裸仓库，裸仓库没有工作区，因为服务器上的git仓库纯粹是为了共享，所以不让用户直接登录到服务器上去改工作区。
  并且服务器上的git仓库都通常以.git结尾。然后，把owner改为git：
  sudo chown -R git:git sample:git
 
5)禁用shell登录：

出于安全考虑，第二步创建的git用户不允许登录shell，这可以通过编辑/etc/passwd文件完成。找到类似下面的一行：

git:x:1001:1001:,,,:/home/git:/bin/bash
改为：

git:x:1001:1001:,,,:/home/git:/usr/bin/git-shell
这样，git用户可以正常通过ssh使用git，但无法登录shell，因为我们为git用户指定的git-shell每次一登录就自动退出 

step2. 添加远程库
1） git remote add origin1 ssh://git@111.207.107.222:/data/home/git/src/HQCo.git
 添加后，远程库的名字就是origin1，这是Git默认的叫法，也可以改成别的，但是origin1这个名字一看就知道是远程库。
2） 下一步，就可以把本地库的所有内容推送到远程库上
git push -u origin1 master
把本地库的内容推送到远程，用git push命令，实际上是把当前分支master推送到远程。

由于远程库是空的，我们第一次推送master分支时，加上了-u参数，Git不但会把本地的master分支内容推送的远程新的master分支，
还会把本地的master分支和远程的master分支关联起来，在以后的推送或者拉取时就可以简化命令。

step 3. 克隆远程仓库：

现在，可以通过git clone命令克隆远程仓库了，在各自的电脑上运行：
git clone git@123.207.107.107:/data/home/git/src/HQCo.git

 