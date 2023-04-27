# test_demo
1. shared_Memory_demo 
read.cpp file is write data to shared memory.
(read.cpp 文件是把数据写入共享内存)
send.cpp file is read data to shared memory.
(send.cpp 文件是把数据读取共享内存)
ipcs 查看开辟的共享内存id
ipcrm -m shmid 删除共享内存 (例如：ipcrm -m 32769)
ipcrm -q msqid 删除消息队列 (例如：ipcrm -q 32769)
