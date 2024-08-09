autoreplyprint
	开发包库文件，头文件，接口说明文件
samplepos
	票据打印
samplelabel
	标签打印
samplepage
	页模式打印

注意：
	普通票据打印机，可以使用samplepos测试
	大资源的票据打印机，如果支持页模式功能，可以使用samplepage测试
	标签打印机，可以使用samplelabel测试

编译及运行测试：
	make
	sudo ./samplepos /dev/usb/lp0 0

