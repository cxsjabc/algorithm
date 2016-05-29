import string

#f = open("ProjectConfig.mk")
f = open("config.ftbl.gc2235mipi_raw.h")
line = f.readline()

while line:
#for (num, line) in enumerate(f):
	#print line
	line = f.readline()
	#l1 = line.split('=')
	#print s1
	#for s1 in l1:
		#s2 = s1.strip('\ \n\t')	
		#print s2
	if "PICTURE_SIZE" in line:
		print line		
		# now, search ITEM_AS_VALUES_
		line1 = f.readline()
		search_picture_size = 1
		while line1:
			if "ITEM_AS_VALUES_" in line1:
				print "[searched]%s" %(line1)
				#break
				line2 = f.readline()
				while line2:
					if ")" in line2:
						search_picture_size = 0	
					if search_picture_size == 0:
						break
					#print "[Searched]picture size values:%s" %(line2)
					line3 = line2.split(",")
					#print line3
					for line4 in line3:
						#print line4
						line5 = line4.strip("\ \"\t")
						#print line5
						line6 = line5.split("x")
						multi_value = 1
						for line7 in line6:
							print "%s " %(line7)
							if string.atoi(line7, 10) % 16 != 0:
								print "Error, not 16 aligned!"
							multi_value *= int(line7)
						print "multi_value:%s" %(multi_value)
					line2 = f.readline()
			if search_picture_size == 0:
				break
			line1 = f.readline()		

f.close()
