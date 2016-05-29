import string
import re 

#f = open("ProjectConfig.mk")
#f = open("config.ftbl.gc2235mipi_raw.h")
f = open("config.ftbl.gc2235_pic_size.h")
content = f.read()
#print content

#m = re.match(r"KEY_AS_\(MtkCameraParameters::KEY_PICTURE_SIZE\),[\s\S]*ITEM_AS_DEFAULT_\((?P<default_pic_size>)\)", content)
p0 = re.compile('KEY_AS_\(')
#p0 = re.compile('[a-z]+')
m = p0.match(content)
#m = p0.match('sKEY_PICTURE_SIZEt')
#m = re.match()
#print m
#print m.group()
w = content.find(r'KEY_PICTURE_SIZE')
print w
print content[w:]
str_start_with_xx = content[w:]
print str_start_with_xx
item_as_default_begin = str_start_with_xx.find(r'(')
print item_as_default_begin
item_as_default_end = str_start_with_xx.find(r')')
print item_as_default_end
item_as_default = content[item_as_default_begin:item_as_default_end]
print item_as_default

#exit 0

m1 = re.match(r'xiyi', "hello xiyi ")

p = re.compile('[a-z]+')
p
p.match("")
#print p.match("")
m2 = p.match("xiyi")
#print m2
#print m2.group()
#print m2.start(), m2.end()
#print m2.span()



f.close()
