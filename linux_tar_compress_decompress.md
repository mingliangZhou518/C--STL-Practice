压缩和解压缩

linux操作系统中，默认支持的压缩格式:gzip、bzip2，这两种压缩格式只能压缩单个，不支持打包，压缩后源文件消失

在linux中压缩和解压缩需要借助tar命令来完成，tar的作用时打包，解压缩，源文件不会消失

压缩

格式：

tar zcvf 压缩的名字.tar.gz 所需要压缩的原材料

tar zcvf test2vim.tar.gz 压缩原材料

z:使用gzip的格式压缩，弱国使用的是bzip2压缩，将z替换成j

c:create

v:visual

f:file 用来指定压缩包包名。f必须是是最后一个参数，前面的三个参数的顺序无所谓

tar jcvf test2vim.tar.bz2 ./test.dir/ //test.txt ./vimrc



解压缩

格式：tat zxvf 压缩包名.tat.gz

tar jxvf 压缩包包名.tat.bz2

x:解压缩的字母



系统不强制加上后缀，但是为了方便后续的操作，最好是要加上的（解压缩的时候，这样才能区分压缩格式选用对应的解压缩指令）



将文件压缩到指定空目录

使用参数 -c

jxvf tarvim2.tar.bz2 -c ./outdir/



