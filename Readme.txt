this is first add file1

�ο����£�
1. �git������
https://www.liaoxuefeng.com/wiki/0013739516305929606dd18361248578c67b8067c8c017b000/00137583770360579bc4b458f044ce7afed3df579123eca000
2. ���Զ�̿� 
https://www.liaoxuefeng.com/wiki/0013739516305929606dd18361248578c67b8067c8c017b000/0013752340242354807e192f02a44359908df8a5643103a000
3. ��Զ�̿��¡
https://www.liaoxuefeng.com/wiki/0013739516305929606dd18361248578c67b8067c8c017b000/001375233990231ac8cf32ef1b24887a5209f83e01cb94b000


step 1. �git������
1)��װgit
2������һ��git�û�
sudo adduser git
3)����֤���½
  -���Լ���PC�ˣ�ִ�С�Git bash here��������git bash������
  -ִ��ssh-keygen��������Ĭ�����ݣ�Ҳ����ָ��·�����ַ���
  -��id-rsa.pub�ļ������ݣ�������׷�ӵ�/home/git/.ssh/authorized_keys�ļ��У�һ��һ����
  
4)��ʼ��git�ֿ�
  sudo git init --bare sample.git
  git�ͻᴴ��һ����ֿ⣬��ֿ�û�й���������Ϊ�������ϵ�git�ֿⴿ����Ϊ�˹������Բ����û�ֱ�ӵ�¼����������ȥ�Ĺ�������
  ���ҷ������ϵ�git�ֿⶼͨ����.git��β��Ȼ�󣬰�owner��Ϊgit��
  sudo chown -R git:git sample:git
 
5)����shell��¼��

���ڰ�ȫ���ǣ��ڶ���������git�û��������¼shell�������ͨ���༭/etc/passwd�ļ���ɡ��ҵ����������һ�У�

git:x:1001:1001:,,,:/home/git:/bin/bash
��Ϊ��

git:x:1001:1001:,,,:/home/git:/usr/bin/git-shell
������git�û���������ͨ��sshʹ��git�����޷���¼shell����Ϊ����Ϊgit�û�ָ����git-shellÿ��һ��¼���Զ��˳� 

step2. ���Զ�̿�
1�� git remote add origin1 ssh://git@111.207.107.222:/data/home/git/src/HQCo.git
 ��Ӻ�Զ�̿�����־���origin1������GitĬ�ϵĽз���Ҳ���Ըĳɱ�ģ�����origin1�������һ����֪����Զ�̿⡣
2�� ��һ�����Ϳ��԰ѱ��ؿ�������������͵�Զ�̿���
git push -u origin1 master
�ѱ��ؿ���������͵�Զ�̣���git push���ʵ�����ǰѵ�ǰ��֧master���͵�Զ�̡�

����Զ�̿��ǿյģ����ǵ�һ������master��֧ʱ��������-u������Git������ѱ��ص�master��֧�������͵�Զ���µ�master��֧��
����ѱ��ص�master��֧��Զ�̵�master��֧�������������Ժ�����ͻ�����ȡʱ�Ϳ��Լ����

step 3. ��¡Զ�ֿ̲⣺

���ڣ�����ͨ��git clone�����¡Զ�ֿ̲��ˣ��ڸ��Եĵ��������У�
git clone git@123.207.107.107:/data/home/git/src/HQCo.git

step 4. Զ�̿�¡�����
git pull

 