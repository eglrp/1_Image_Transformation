程序运行的环境：win 10，Visual Studio 2012。
 

库：opencv，包含在opencv_debug中。


操作：需要在可执行文件相同目录中包含与主程序中名字一样的图像文件，然后运行就可。按提示操作，图片出来以后把图片关闭即可继续操作。

image文件夹里包含原始图片和输出图片，其中对于图片名：旋转的后缀中前一个是旋转角度，后一个是插值方法；畸变的也是，前一个指即便类型（pillow 或 bucket)后一个是插值方法。旋转的中心点和旋转圆半径没有列出。