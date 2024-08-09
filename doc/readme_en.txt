autoreplyprint
	dll headers and interface detail
samplepos
	Receipt print
samplelabel
	Label print
samplepage
	PageMode print

Attention:
	Ordinary ticket printer, can use samplepos test
	For large-resource ticket printers, use the samplepage test if page mode functionality is supported
	Label printer can use samplelabel test

make and test:
	make
	sudo ./samplepos /dev/usb/lp0 0

