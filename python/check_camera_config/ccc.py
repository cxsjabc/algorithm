import os
import sys

class CheckRule:
	def __init__(self,type,first,second):
		self.type = type;
		self.first = first;
		self.second = second;
		
	def __del__(self):
		pass
		
	def show(self):
		print "type:",self.type,",first:",self.first,",second:",self.second
		
# cequal: use set,is equal	1   ov2680 hi545   	2  hi545 ov2680
# equal: completed equal	1   hi545 ov2680  	2  hi545 ov2680
# in:  is subset           	1   hi545   		2  hi545 ov2680
all_check_rules = [ \
					CheckRule("cequal","CUSTOM_HAL_IMGSENSOR","CUSTOM_KERNEL_IMGSENSOR"), \
					CheckRule("in","CUSTOM_HAL_MAIN_IMGSENSOR","CUSTOM_HAL_IMGSENSOR"), \
					CheckRule("in","CUSTOM_HAL_SUB_IMGSENSOR","CUSTOM_HAL_IMGSENSOR"), \
					CheckRule("in","CUSTOM_KERNEL_MAIN_IMGSENSOR","CUSTOM_KERNEL_IMGSENSOR"), \
					CheckRule("in","CUSTOM_KERNEL_SUB_IMGSENSOR","CUSTOM_KERNEL_IMGSENSOR"), \
					CheckRule("cequal","CUSTOM_HAL_LENS","CUSTOM_KERNEL_LENS"), \
					CheckRule("in","CUSTOM_KERNEL_MAIN_LENS","CUSTOM_KERNEL_LENS"), \
					CheckRule("in","CUSTOM_KERNEL_SUB_LENS","CUSTOM_KERNEL_LENS"), \
					CheckRule("in","CUSTOM_HAL_MAIN_LENS","CUSTOM_HAL_LENS"), \
					CheckRule("in","CUSTOM_HAL_SUB_LENS","CUSTOM_HAL_LENS"), \
					CheckRule("cequal","CUSTOM_HAL_FLASHLIGHT","CUSTOM_KERNEL_FLASHLIGHT"), \
				  ]

def add_key_value_to_dict(split_with_char_assign):
	#print split_with_char_assign[0]
	list_len = len(split_with_char_assign)
	split_result = split_with_char_assign
	if list_len == 2:
		key = split_result[0]
		key_strip = key.strip()
		value_strip = split_result[1].strip()
		print "Key:<",key_strip,">, Value:<", value_strip,">","Key Length:",len(key_strip)
		if (key_strip == "" and list_len > 1):
			print "Warning: key is empty!",value_strip
		elif (key_strip == "" and list_len == 1):
			print "Warning: key is empty!"
		if(key_strip not in dict_info):
			dict_info[key_strip]=value_strip.split(" ")
		else:
			print "Warning: Key:", key_strip, "already exists!","Exist Value:",dict_info[key_strip],"New value:",value_strip
	elif len == 1:
		print "Key:",key, "Value:<null>"
	elif len == 0:
		print "Key:<null>"
	return

def special_process_for_each_line(line, strip_line, split_with_char_assign):
	#print line
	split_result = split_with_char_assign
	if(split_result[0] == "CUSTOM_HAL_IMGSENSOR"):
		print line

	return

def special_process_for_all_dict(dict_infos):
	# add processing for all dicts
	return

def check_each_line(line, strip_line, split_with_char_assign):
	return

def check_use_rule(rule, dict_info):
	type = rule.type;
	first = rule.first;
	second = rule.second;
	has_first_key = dict_info.has_key(first)
	has_second_key = dict_info.has_key(second)
	#print has_first_key,",",has_second_key
	if(has_first_key and has_second_key):
		# it is ok now
		pass
	elif has_first_key:
		print "Error:","key",second,"is missing!"
		return
	elif has_second_key:
		print "Error:","key",first,"is missing!"
		return
	else:
		print "Error:","key",first," ",second,"are both missing!"
		return
		
	if(type == "cequal"):
		first_value = dict_info[first]
		first_value_backup = first_value
		first_value.sort()
		second_value = dict_info[second]
		second_value_backup = second_value
		second_value.sort()
		if(first_value == second_value):
			print "First Value:",first_value_backup,"Second Value:",second_value_backup
			return True
		else:
			print "First Value:",first_value_backup,"Second Value:",second_value_backup
			return False
			
	if(type == "equal"):
		first_value = dict_info[first]
		second_value = dict_info[second]
		if(first_value == second_value):
			print "First Value:",first_value,"Second Value:",second_value
			return True
		else:
			print "First Value:",first_value,"Second Value:",second_value
			return False
			
	if(type == "in"):
		first_value = dict_info[first]
		second_value = dict_info[second]
		if(set(first_value).issubset(set(second_value))):
			print "First Value:",first_value,"Second Value:",second_value
			return True
		else:
			print "First Value:",first_value,"Second Value:",second_value
			return False
	return

def check_all_dict(argument_dict_info):
	'''
	dict_info = argument_dict_info
	has_key_hal_imgsensor = dict_info.has_key("CUSTOM_HAL_IMGSENSOR")
	has_key_kernel_imgsensor = dict_info.has_key("CUSTOM_KERNEL_IMGSENSOR")
	if  has_key_hal_imgsensor and has_key_kernel_imgsensor:
		temp_hal_imgsensor_arr = dict_info["CUSTOM_HAL_IMGSENSOR"]
		temp_hal_imgsensor_arr.sort()
		dict_info["CUSTOM_HAL_IMGSENSOR"] = temp_hal_imgsensor_arr
		#print dict_info["CUSTOM_HAL_IMGSENSOR"]
		
		temp_kernel_imgsensor_arr = dict_info["CUSTOM_KERNEL_IMGSENSOR"]
		temp_kernel_imgsensor_arr.sort()
		dict_info["CUSTOM_KERNEL_IMGSENSOR"] = temp_kernel_imgsensor_arr
		#print dict_info["CUSTOM_KERNEL_IMGSENSOR"]
		
		if(dict_info["CUSTOM_HAL_IMGSENSOR"] == dict_info["CUSTOM_KERNEL_IMGSENSOR"]):
			print "CUSTOM_HAL_IMGSENSOR","is equal to","CUSTOM_KERNEL_IMGSENSOR"
		else:
			print "CUSTOM_HAL_IMGSENSOR","is not equal to","CUSTOM_KERNEL_IMGSENSOR"
			
	if dict_info.has_key("CUSTOM_HAL_MAIN_IMGSENSOR"):
		if(set(dict_info["CUSTOM_HAL_MAIN_IMGSENSOR"]).issubset(dict_info["CUSTOM_HAL_IMGSENSOR"])):
			print "CUSTOM_HAL_MAIN_IMGSENSOR","is subset of CUSTOM_HAL_IMGSENSOR"
		else:
			print "Error: CUSTOM_HAL_MAIN_IMGSENSOR:",dict_info["CUSTOM_HAL_IMGSENSOR"],"is not subset of CUSTOM_HAL_IMGSENSOR:",dict_info["CUSTOM_HAL_IMGSENSOR"]
	'''
	
	# use rules to check
	for rule in all_check_rules:
		rule.show()
		if check_use_rule(rule, dict_info):
			print "				Rule:  PASS..."
		else:
			print "				Rule:  Failed..."
	
	return

# show current directory
curr_dir = os.getcwd()
print curr_dir

# dict info from file
dict_info = dict()

# check arguments
if len(sys.argv) < 2:
	print 'Arguments missing...'
	print 'Syntax: python ccc.py <project_name>'
	print 'Eg: python ccc.py tb6735ma1'
	sys.exit()

# show arguments
print sys.argv[1]

# check ProjectConfig.mk
try:
	fpc = open('device/mediatek/' + sys.argv[1] + '/ProjectConfig.mk')
	for line in fpc.readlines():
		# line, line stripped, split with "="
		#print '|', line, '|'
		strip_line = line.strip()
		#print '|', strip_line, '|'
		split_with_char_assign = strip_line.split('=')
		#print type(split_with_char_assign)
		
		# add key/value into dict
		add_key_value_to_dict(split_with_char_assign)

		# call special processing 
		special_process_for_each_line(line, strip_line, split_with_char_assign)
		
		#if you needs other processing, just add it here
		# ....
		
		# call check for each line
		check_each_line(line, strip_line, split_with_char_assign)

	#print dict_info.items()
	
	# special processing for add dict
	special_process_for_all_dict(dict_info)
	
	# check for all dict
	check_all_dict(dict_info)
	
except IOError, e:
	print 'Exception happens...'
	print e
 
