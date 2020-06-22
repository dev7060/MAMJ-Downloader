# MAMJ-Downloader
Feed multiple links at once via arguments or through files containing the links. Downloads are done with FCFS priority.  

### Usage
***General format***
  
	mamj -u [links separated by space] -f [filenames separated by space]
 
#### For example
***Multiple links + Multiple files***
 
	mamj -u https://releases.ubuntu.com/20.04/ubuntu-20.04-desktop-amd64.iso https://archive.org/download/ElephantsDream/ed_hd_512kb.mp4 -f file1.txt file2.txt
	
***Single link***
  
 	mamj -u https://releases.ubuntu.com/20.04/ubuntu-20.04-desktop-amd64.iso
	
***Single file***
 	
 	mamj -f file1.txt
	
***Single link + Single file***
 	
 	mamj -u https://releases.ubuntu.com/20.04/ubuntu-20.04-desktop-amd64.iso https://archive.org/download/ElephantsDream/ed_hd_512kb.mp4
	
***Multiple files***
	
 	mamj -f file1.txt file2.txt
	
***Multiple links + Multiple files (change in the arguments order)***
 
	mamj -f file1.txt file2.txt-u https://releases.ubuntu.com/20.04/ubuntu-20.04-desktop-amd64.iso https://archive.org/download/ElephantsDream/ed_hd_512kb.mp4 
	
	
  
  ### ***Text file format***
  
     link1[newline]
     link2[newline]
     ...
     ...
     [eof]
  
  [Like this](https://github.com/dev7060/springer-direct-download-links/blob/master/links.txt) or below:
  
  
  	https://download.kiwix.org/zim/wikipedia/wikipedia_ab_all_maxi_2020-04.zim
  	https://download.kiwix.org/zim/wikibooks/wikibooks_af_all_maxi_2020-05.zim
  	https://download.kiwix.org/zim/ted/ted_en_business_2016-06.zim
  	https://download.kiwix.org/zim/gutenberg/gutenberg_ale_all_2018-07.zim
	
	

