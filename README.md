# google_breakpad

1.

sudo add-apt-repository ppa:ubuntu-toolchain-r/test
sudo apt-get update
sudo apt-get install g++-4.8
至此，g++-4.8已经安装，但还未被设为默认。再执行下面的命令切换链接。
sudo rm /usr/bin/g++
sudo ln -s /usr/bin/g++-4.8 /usr/bin/g++



