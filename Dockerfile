FROM ubuntu:18.04
run apt-get update
run apt install -y git
run git clone https://github.com/opencv/opencv.git
run apt install -y cmake
run apt install -y g++
workdir opencv/
run mkdir build
workdir build/
run apt install -y gdb
run apt install -y libgtk2.0-dev
run cmake -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=/usr/local -D WITH-GTK=ON ..
run make -j7 # runs 7 jobs in parallel
run make install
run apt install pkg-config
copy opencv.pc /usr/local/lib/pkgconfig/
run echo "PKG_CONFIG_PATH=$PKG_CONFIG_PATH:/usr/local/lib/pkgconfig" ~/.bashrc
run echo "export PKG_CONFIG_PATH" ~/.bashrc
run apt install -y vim

# copia arquivos de desenvolvimento
run mkdir ../src
workdir ../src
copy . ./
run ls -la 

