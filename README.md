# MAMJ-Downloader

### Usage

  
	mamj -u [links separated by space] -f [filenames separated by spaces]
 
For example
 
	mamj -u https://releases.ubuntu.com/20.04/ubuntu-20.04-desktop-amd64.iso https://archive.org/download/ElephantsDream/ed_hd_512kb.mp4 -f file1.txt file2.txt
  
 	mamj -u https://releases.ubuntu.com/20.04/ubuntu-20.04-desktop-amd64.iso
 	
 	mamj -f file1.txt
 	
 	mamj -u https://releases.ubuntu.com/20.04/ubuntu-20.04-desktop-amd64.iso https://archive.org/download/ElephantsDream/ed_hd_512kb.mp4
	
 	mamj -f file1.txt file2.txt
  
  Text file format:
  
  link1[eof]
  link2[eof]
  ...
  ...
  
  For example:
  
  	https://download.kiwix.org/zim/wikipedia/wikipedia_ab_all_maxi_2020-04.zim
  	https://download.kiwix.org/zim/wikibooks/wikibooks_af_all_maxi_2020-05.zim
  	https://download.kiwix.org/zim/ted/ted_en_business_2016-06.zim
  	https://download.kiwix.org/zim/gutenberg/gutenberg_ale_all_2018-07.zim
