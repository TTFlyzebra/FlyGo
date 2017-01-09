url = "https://v.qq.com/x/cover/3iyj5snd63ua7sa/j0022jwxu8t.html"--视频地址
vurl = "https://v.qq.com/x/cover/3iyj5snd63ua7sa/j0022jwxu8t.html?ptag=bl.zy.bs_txfm_161218.161226"
ptag = "bl.zy.bs_txfm_161218.161226"
coverid ="3iyj5snd63ua7sa"
vid="j0022jwxu8t"
v = "TencentPlayerV3.2.19.358"--AD中的版本号
pversion="TencentPlayerV3.2.32.395"--数据包中的版本号
pid_l= "910cf5817970aa19d3a03b1b59412711"--随机字符串
pid_c = "910CF5817970AA19D3A03B1B59412711"--随机字符串
mbid_l = "00fb17ae30cf4b63cba991cca991720a"--随机字符串
guid_l = "ba26b181569b6e24ab1f55714fb9769e"--随机字符串
guid_c="BA26B181569B6E24AB1F55714FB9769E"--随机字符串
cookie_uuid="18cd969fe0be6b58"--cookie信息
cookie_pgv_info="ssid=s8393952490"
cookie_pgv_pvid="4405492254"
apid_c="4571888A47DB61BF4EE075669697E60B7AFC16BD"--随机字符串
userAgent= "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/47.0.2526.73 Safari/537.36"--浏览器标识
--打印等级设置
DEBUG(0)
--初始化随机种子
 math.randomseed(os.time())
 print(tostring( math.random(100,9999)))
 --初始化随机数 --此处可考虑是否每个循环都随机生成
 pid_l = getRandomStr(32)
 pid_c = string.upper(pid_l)
 mbid_l = getRandomStr(32)
 mbid_c = string.upper(mbid_l)
 guid_l = getRandomStr(32)
 guid_c = string.upper(guid_l)
 apid_c=getRandomStr(40)
 cookie_uuid = getRandomStr(16)
 cookie_pgv_info="ssid=s"..tostring( math.random(10000000,99999999))
 cookie_pgv_pvid= tostring( math.random(10000000,99999999))

for nn=1,1000000 do  
repeat
--开始循环发送数据包
--网页链接地址
curl1 = "curl '"..vurl.."' -H 'Host: v.qq.com' -H 'User-Agent: "..userAgent.."' -H 'Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8' -H 'Accept-Language: en-US,en;q=0.5' --compressed -H 'DNT: 1' -H 'Connection: keep-alive' -H 'Upgrade-Insecure-Requests: 1'"
SendCurlCmd(curl1,"index.html")
--print("finish get html!")
--获取广告列表
adurl = "curl 'https://livew.l.qq.com/livemsg?ty=web&ad_type=LD|KB&pf=in&pt=0&pc=0&live=0&from=0&pu=-1&v="..v.."&plugin=1.4.6&speed=0&adaptor=2&musictxt=&chid=0&st=0&resp_type=json&_t="..os.time().."&callback=lviewcb&rfid=&vid="..vid.."&vptag="..ptag.."&url="..UrlEncode(vurl).."&refer=&pid="..pid_l.."&mbid="..mbid_l.."&oid=&guid="..guid_l.."&coverid="..coverid.."' -H 'Host: livew.l.qq.com' -H 'User-Agent: "..userAgent.."' -H 'Accept: */*' -H 'Accept-Language: en-US,en;q=0.5' --compressed -H 'Referer: "..vurl.."' -H 'Cookie: tvfe_boss_uuid="..cookie_uuid.."' -H 'DNT: 1' -H 'Connection: keep-alive'"
--发送HTTP请求获取JSON文件
SendCurlCmd(adurl,"adurl.fly")
--print("finish get adurl!")
local file = io.open("adurl.fly", "r")
local data = file:read("*a")
io.close(file)
--此处需加入检测内容是否为json的脚本
--判断内容是否是正确的待解析的文本，如果不是结束当前循环，进入下一个循环
if string.find(data,"lviewcb")~=1 then
print("\n---------------error json data,program end!-----------------",nn)
break
end
--截取其中的json字符串
n_s= string.len("lviewcb(")+1
n_e= string.len(data)-string.len(")")
jsondata=string.sub(data,n_s,n_e)
--解析json字符串
local adTable = cjson.decode(jsondata)
--print("finish json.decode adurl-->ad play url--->")
--打印获取的AD信息
for aa=1,6 do
if adTable["adList"]["item"][aa]["url"]~="" then
print(aa.." "..adTable["adList"]["item"][aa]["url"].." "..adTable["adList"]["item"][aa]["duration"])
end
end

adsum = 0
for adi=1,6 do
if adTable["adList"]["item"][adi]["duration"]~="" then
nub = tonumber(adTable["adList"]["item"][adi]["duration"])
if nub then
adsum= adsum+nub
end
end
end
--头部固定发送数据包
sendcurl = "curl 'https://btrace.qq.com/kvcollect?BossId=3255&Pwd=2118551257&s_url="..UrlEncode(url).."&s_referrer=&s_ua="..UrlEncode(userAgent).."&s_uuid="..cookie_uuid.."&s_uin=&s_openid=&_dc="..string.format("%0.17f", math.random()).."&s_ptag="..ptag.."&s_app=vplay&s_module=event&s_behave=10&s_sub=cover-recommend&s_fifth=' --2.0 -H 'Host: btrace.qq.com' -H 'User-Agent: "..userAgent.."' -H 'Accept: */*' -H 'Accept-Language: en-US,en;q=0.5' --compressed -H 'Referer: "..vurl.."' -H 'Cookie: tvfe_boss_uuid="..cookie_uuid.."' -H 'DNT: 1' -H 'Connection: keep-alive'"
SendCurlCmd(sendcurl)

sendcurl= "curl 'https://btrace.qq.com/kvcollect?BossId=3255&Pwd=2118551257&s_url="..UrlEncode(url).."&s_referrer=&s_ua="..UrlEncode(userAgent).."&s_uuid="..cookie_uuid.."&s_uin=&s_openid=&_dc="..string.format("%0.17f", math.random()).."&s_ptag="..ptag.."&s_app=vplay&s_module=event&s_behave=10&s_sub=top-list&s_fifth=' --2.0 -H 'Host: btrace.qq.com' -H 'User-Agent: "..userAgent.."' -H 'Accept: */*' -H 'Accept-Language: en-US,en;q=0.5' --compressed -H 'Referer: "..vurl.."' -H 'Cookie: tvfe_boss_uuid="..cookie_uuid.."' -H 'DNT: 1' -H 'Connection: keep-alive'"
SendCurlCmd(sendcurl)

sendcurl = "curl 'https://btrace.qq.com/kvcollect?BossId=3255&Pwd=2118551257&s_url="..UrlEncode(url).."&s_referrer=&s_ua="..UrlEncode(userAgent).."&s_uuid="..cookie_uuid.."&s_uin=&s_openid=&_dc="..string.format("%0.17f", math.random()).."&s_ptag="..ptag.."&s_app=vplay&s_module=pageview&s_behave=10&s_sub=&s_fifth=' --2.0 -H 'Host: btrace.qq.com' -H 'User-Agent: "..userAgent.."' -H 'Accept: */*' -H 'Accept-Language: en-US,en;q=0.5' --compressed -H 'Referer: "..vurl.."' -H 'Cookie: tvfe_boss_uuid="..cookie_uuid.."' -H 'DNT: 1' -H 'Connection: keep-alive'"
SendCurlCmd(sendcurl)

sendcurl = "curl 'https://btrace.video.qq.com/kvcollect?BossId=3721&Pwd=1636975887&version=3.0.0&uid="..guid_l.."&pid="..pid_l.."&vid="..vid.."&player_type=flash&video_type=1&platform=10201&url="..UrlEncode(url).."%3Fptag%3D"..ptag.."&filename=txplayer.js&sub_version=0.0.0&_dc="..string.format("%0.17f", math.random()).."&browser=chrome&osname=windows&osver=10.0' --2.0 -H 'Host: btrace.video.qq.com' -H 'User-Agent: "..userAgent.."' -H 'Accept: */*' -H 'Accept-Language: en-US,en;q=0.5' --compressed -H 'Referer: "..vurl.."' -H 'Cookie: tvfe_boss_uuid="..cookie_uuid.."' -H 'DNT: 1' -H 'Connection: keep-alive'"
SendCurlCmd(sendcurl)
--起始地址包
--第1个固定AD包
sendcurl = "curl 'http://btrace.video.qq.com/kvcollect?sIp=&iQQ=&sBiz=&sOp=&iSta=0&iTy=2481&iFlow=0&sUrl=&sRef=&sPageId=&sPos=&step=2001&val=web&val1=&val2=&val3=&val4=&val5=&apid=1.4.6&pid=1.4.6&vid="..vid.."&platform=3&pversion="..pversion.."&version=1.4.6&bi=0&bt=0&idx=0&appid=0&ua=&adtype=0&vurl="..vurl.."&reporttime=&bdua=0&admtype=0&adid=4003&guid=&ispip=0&random="..tostring( math.random(100,9999)).."' -H 'Host: btrace.video.qq.com' -H 'User-Agent: "..userAgent.."' -H 'Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8' -H 'Accept-Language: en-US,en;q=0.5' --compressed -H 'Cookie: tvfe_boss_uuid="..cookie_uuid.."' -H 'DNT: 1' -H 'Connection: keep-alive'"
SendCurlCmd(sendcurl)

sendcurl = "curl 'http://btrace.video.qq.com/kvcollect' -H 'Host: btrace.video.qq.com' -H 'User-Agent: "..userAgent.."' -H 'Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8' -H 'Accept-Language: en-US,en;q=0.5' --compressed -H 'Cookie: tvfe_boss_uuid="..cookie_uuid.."' -H 'DNT: 1' -H 'Connection: keep-alive' --data 'int1=1772&itype=0&val2=4003&bid=pcvideo&vid="..vid.."&str2=1%2E4%2E6&ver="..UrlEncode(pversion).."&int2=0&str3="..UrlEncode(ptag).."&str4="..pid_c.."&url="..UrlEncode(vurl).."&val=4003&rnd=9066&iTy=2052&str1="..coverid.."&iSta=6'"
SendCurlCmd(sendcurl)

--第2个固定AD包
sendcurl = "curl 'http://btrace.video.qq.com/kvcollect?sIp=&iQQ=&sBiz=&sOp=&iSta=0&iTy=2481&iFlow=0&sUrl="..UrlEncode(url).."%3Fptag%3D"..ptag.."&sRef=&sPageId=&sPos=&step=3&val=288&val1=1&val2=0&val3=&val4=&val5=&apid="..apid_c.."&pid="..pid_c.."&vid="..vid.."&platform=1&pversion="..pversion.."&version=1.4.6&bi=2&bt=0&idx=0&appid=0&ua=Mozilla%2F5.0%20(Windows%20NT%2010.0%3B%20WOW64)%20AppleWebKit%2F537.36%20(KHTML%2C%20like%20Gecko)%20Chrome%2F47.0.2526.73%20Safari%2F537.36&adtype=0&vurl=http%3A%2F%2Flivew.l.qq.com%2Flivemsg%3Fty%3Dweb%26ad_type%3DLD%7CKB%26rfid%3D%26pf%3Din%26pt%3D0%26pc%3D0%26vid%3D"..vid.."%26coverid%3D"..coverid.."%26live%3D0%26from%3D0%26pu%3D0%26v%3D"..pversion.."%26plugin%3D1.4.6%26speed%3D0%26vptag%3D"..ptag.."%26pid%3D"..pid_c.."%26adaptor%3D2%26musictxt%3D%26chid%3D0%26mbid%3D"..mbid_l.."%26guid%3D"..guid_c.."%26url%3D"..UrlEncode(url).."%26refer%3D%26st%3D0&reporttime="..getUrlTime().."&bdua=0&admtype=0&adid=4003&guid="..guid_c.."&ispip=0&random="..tostring( math.random(100,9999)).."' -H 'Host: btrace.video.qq.com' -H 'User-Agent: "..userAgent.."' -H 'Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8' -H 'Accept-Language: en-US,en;q=0.5' --compressed -H 'Cookie: tvfe_boss_uuid="..cookie_uuid.."' -H 'DNT: 1' -H 'Connection: keep-alive'"
SendCurlCmd(sendcurl)

sendcurl= "curl '"..adTable["adList"]["item"][1]["reportUrl"].."&reqtime="..os.time().."' -H 'Host: livep.l.qq.com' -H 'User-Agent: "..userAgent.."' -H 'Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8' -H 'Accept-Language: en-US,en;q=0.5' --compressed -H 'Referer: https://imgcache.qq.com/tencentvideo_v1/playerv3/TencentPlayer.swf?max_age=86400&v=20161228' -H 'Cookie: tvfe_boss_uuid="..cookie_uuid.."; LKBturn=672; Lturn=481; adid=0; appuser=DB87753C7027D28F; o_minduid=un95A5GgLr_zVHO5wMSvV-xgdAMneQ_D' -H 'DNT: 1' -H 'Connection: keep-alive'"
SendCurlCmd(sendcurl)

sendcurl="curl 'https://btrace.video.qq.com/kvcollect' --2.0 -H 'Host: btrace.video.qq.com' -H 'User-Agent: "..userAgent.."' -H 'Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8' -H 'Accept-Language: en-US,en;q=0.5' --compressed -H 'Cookie: tvfe_boss_uuid="..cookie_uuid.."' -H 'DNT: 1' -H 'Connection: keep-alive' --data 'ctime="..getUrlTime().."&val1=0&type=1&bi=0&step=201&bt=0&url="..UrlEncode(vurl).."&platform=1&vid="..vid.."&ran=0%2E37374923191964626&vt=0&pid="..pid_c.."&val=937&BossId=2577'"
SendCurlCmd(sendcurl)

sendcurl="curl 'https://btrace.video.qq.com/kvcollect' --2.0 -H 'Host: btrace.video.qq.com' -H 'User-Agent: "..userAgent.."' -H 'Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8' -H 'Accept-Language: en-US,en;q=0.5' --compressed -H 'Cookie: tvfe_boss_uuid="..cookie_uuid.."' -H 'DNT: 1' -H 'Connection: keep-alive' --data 'iformat=&vurl=&ispac=0&ctime="..getUrlTime().."&tpay=&pid="..pid_c.."&head%5Fref=&autoformat=1&val2=0&platform=1&ptime=0&idx=0&BossId=2577&emsg=&version="..UrlEncode(pversion).."&rcd%5Finfo=&dltype=1&defn=&exid=0&predefn=0&diaonlen=745&isfocustab=1&rid=&isvisible=1&preformat=0&ua=Mozilla%252F5%2E0%2520%28Windows%2520NT%252010%2E0%253B%2520WOW64%29%2520AppleWebKit%252F537%2E36%2520%28KHTML%252C%2520like%2520Gecko%29%2520Chrome%252F47%2E0%2E2526%2E73%2520Safari%252F537%2E36&clspeed=0&adid=4003&url="..UrlEncode(vurl).."&tpid=10&vt=0&cmid="..guid_c.."&cpay=0&pfversion=LNX%2E24%2E0&val=1&index=0&isvip=%2D1&level=0&encv=0&pversion=&v%5Fidx=0&val1=0&buffersize=0&type=0&bi=0&vid="..vid.."&loadwait=0&step=3&bt=0&bufferwait=0&ptag="..UrlEncode(ptag).."'"
SendCurlCmd(sendcurl)

sendcurl="curl 'https://btrace.video.qq.com/kvcollect?BossId=3487&Pwd=745225177&itype=0&idx=2&ptag="..ptag.."&qtag=x&refer=&url="..UrlEncode(url).."%3Fptag%3D"..ptag.."&type=10&_=137' --2.0 -H 'Host: btrace.video.qq.com' -H 'User-Agent: "..userAgent.."' -H 'Accept: */*' -H 'Accept-Language: en-US,en;q=0.5' --compressed -H 'Referer: "..vurl.."' -H 'Cookie: tvfe_boss_uuid="..cookie_uuid.."' -H 'DNT: 1' -H 'Connection: keep-alive'"
SendCurlCmd(sendcurl)

sendcurl="curl 'https://btrace.video.qq.com/kvcollect' --2.0 -H 'Host: btrace.video.qq.com' -H 'User-Agent: "..userAgent.."' -H 'Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8' -H 'Accept-Language: en-US,en;q=0.5' --compressed -H 'Cookie: tvfe_boss_uuid="..cookie_uuid.."' -H 'DNT: 1' -H 'Connection: keep-alive' --data 'iformat=%24%24&vurl=%24https%3A%2F%2Fimgcache%2Eqq%2Ecom%2Fminivideo%5Fv1%2Fvd%2Fres%2Fskins%2FTencentPlayerSkinV5%2Eswf%24&ispac=0%240%240&ctime="..getUrlTime().."%24"..getUrlTime().."%24"..getUrlTime().."&tpay=%24%24&pid="..pid_c.."&head%5Fref=&autoformat=1%241%241&val2=0%240%240&platform=1&ptime=0%240%240&idx=0%240%240&BossId=2577&emsg=%24%24&version="..UrlEncode(pversion).."&rcd%5Finfo=&dltype=1%241%241&defn=%24%24&exid=0%240%240&predefn=0%240%240&diaonlen=0%240%240&isfocustab=0%240%240&rid=%24%24&isvisible=0%240%240&preformat=0%240%240&ua=Mozilla%252F5%2E0%2520%28Windows%2520NT%252010%2E0%253B%2520WOW64%29%2520AppleWebKit%252F537%2E36%2520%28KHTML%252C%2520like%2520Gecko%29%2520Chrome%252F47%2E0%2E2526%2E73%2520Safari%252F537%2E36&clspeed=0%240%240&adid=4003&url="..UrlEncode(vurl).."&tpid=10&vt=0%240%240&cmid="..guid_c.."&cpay=0&pfversion=LNX%2E24%2E0&val=567%24262%24125&index=1%242%243&isvip=%2D1%24%2D1%24%2D1&level=0%240%240&encv=0&pversion=&v%5Fidx=0&val1=1%241%241&buffersize=0%240%240&type=0%240%240&bi=0%240%240&vid=%24%24&loadwait=0%240%240&step=402%24400%241043&bt=0&bufferwait=0%240%240&ptag="..UrlEncode(ptag).."'"
SendCurlCmd(sendcurl)
--开始根据得到的AD数据发送相关数据包
--统计AD总时间等信息

--第1个AD数据
--sendcurl="curl 'https://livep.l.qq.com/livemsg?pid2="..pid_c.."&aid_vid_drm=0&ev=233&t=0&axpheader=1&urlchid=0&live=0&ip_filter=0&oadid=4003&isthirdip=0&v="..pversion.."&imagemd5=f8f06f8c039261f66dfda355e6834d3c&use_axp=1&lcount=1&adtype=LD&aid_column=4379&isfloatindex=0&chid=0&aid_cid_drm=0&vptag="..ptag.."&tagid=&plugin=1.4.6&soid=B710066E003A586CBAD818444700&gf=2&mt=15000&from=0&aid_cover="..coverid.."&aver_flag=2052&si=587775242&ping_data=dXNlcl9pbmZvPXZRRGpnVGs3RmhTMQ&acpm=2&refluence=4003&aid_tpid=10&pf=in&aver=0&aid_dura=1772&coverid="..coverid.."&aid_copyright=94&requestl=4003&cid=1720141&fl=1&url="..UrlEncode(url).."&cip=183.16.6.110&iptype=0&ufc_filter=0&aid_tpid2=1001&l=4003&reqtime="..os.time().."&dura=1772&o=3070563&vid="..vid.."&imagelog=1&aid_subtype=4_24_1&pid="..pid_c.."&aid_tpid3=10001' -H 'Host: livep.l.qq.com' -H 'User-Agent: "..userAgent.."' -H 'Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8' -H 'Accept-Language: en-US,en;q=0.5' --compressed -H 'Referer: https://imgcache.qq.com/tencentvideo_v1/playerv3/TencentPlayer.swf?max_age=86400&v=20161228' -H 'Cookie: tvfe_boss_uuid="..cookie_uuid.."; LKBturn=672; Lturn=481; adid=0; appuser=DB87753C7027D28F; o_minduid=un95A5GgLr_zVHO5wMSvV-xgdAMneQ_D' -H 'DNT: 1' -H 'Connection: keep-alive'"
--SendCurlCmd(sendcurl)
--播放前发送
adcount = 0
for adi=1,6 do
if adTable["adList"]["item"][adi]["url"]~="" then
sendcurl="curl 'http://btrace.video.qq.com/kvcollect?sIp=&iQQ=&sBiz=&sOp=&iSta=0&iTy=2481&iFlow=0&sUrl="..UrlEncode(vurl).."&sRef=&sPageId=&sPos=&step=6&val="..tostring( math.random(100,300)).."&val1=1&val2=4&val3=&val4=&val5=&apid="..apid_c.."&pid="..pid_c.."&vid="..vid.."&platform=1&pversion="..pversion.."&version=1.4.6&bi=0&bt=0&idx=0&appid=0&ua=Mozilla%2F5.0%20(Windows%20NT%2010.0%3B%20WOW64)%20AppleWebKit%2F537.36%20(KHTML%2C%20like%20Gecko)%20Chrome%2F47.0.2526.73%20Safari%2F537.36&adtype=0&vurl="..UrlEncode(adTable["adList"]["item"][adi]["image"][1]["url"]).."&reporttime="..getUrlTime1().."&bdua=0&admtype=1&adid=4003&guid="..guid_c.."&ispip=1&random="..tostring( math.random(100,9999)).."' -H 'Host: btrace.video.qq.com' -H 'User-Agent: "..userAgent.."' -H 'Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8' -H 'Accept-Language: en-US,en;q=0.5' --compressed -H 'Cookie: tvfe_boss_uuid="..cookie_uuid.."' -H 'DNT: 1' -H 'Connection: keep-alive'"
SendCurlCmd(sendcurl)
--延时播放时长
stime = (tonumber(adTable["adList"]["item"][adi]["duration"]))/1000
os.execute("sleep " .. stime)
--播放后发送
sendcurl="curl 'http://btrace.video.qq.com/kvcollect?sIp=&iQQ=&sBiz=&sOp=&iSta=0&iTy=2481&iFlow=0&sUrl="..UrlEncode(url).."&sRef=&sPageId=&sPos=&step=7&val=15000&val1=4&val2=&val3=&val4=&val5=&apid="..apid_c.."&pid="..pid_c.."&vid="..vid.."&platform=1&pversion="..pversion.."&version=1.4.6&bi="..adTable["adList"]["item"][adi]["duration"].."&bt="..tostring(adsum).."&idx="..tostring(adcount).."&appid=0&ua=Mozilla%2F5.0%20(Windows%20NT%2010.0%3B%20WOW64)%20AppleWebKit%2F537.36%20(KHTML%2C%20like%20Gecko)%20Chrome%2F47.0.2526.73%20Safari%2F537.36&adtype=0&vurl="..UrlEncode(adTable["adList"]["item"][adi]["image"][1]["url"]).."&reporttime="..getUrlTime1().."&bdua=0&admtype=1&adid=4003&guid="..guid_c.."&ispip=0&random="..tostring( math.random(100,9999)).."' -H 'Host: btrace.video.qq.com' -H 'User-Agent: "..userAgent.."' -H 'Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8' -H 'Accept-Language: en-US,en;q=0.5' --compressed -H 'Cookie: tvfe_boss_uuid="..cookie_uuid.."' -H 'DNT: 1' -H 'Connection: keep-alive'"
SendCurlCmd(sendcurl)
adcount=adcount+1
--第2个AD数据
--第3个AD数据
--第4个AD数据
--第5个AD数据
--第6个AD数据
end
end
os.execute("sleep " .. 15)
--此处可能延时了15秒
sendcurl = "curl 'http://btrace.video.qq.com/kvcollect?sIp=&iQQ=&sBiz=&sOp=&iSta=0&iTy=2481&iFlow=0&sUrl="..UrlEncode(url).."&sRef=&sPageId=&sPos=&step=3&val=116&val1=1&val2=0&val3=&val4=&val5=&apid="..apid_c.."&pid="..pid_c.."&vid="..vid.."&platform=1&pversion="..pversion.."&version=1.4.6&bi=1&bt=0&idx=0&appid=0&ua=Mozilla%2F5.0%20(Windows%20NT%2010.0%3B%20WOW64)%20AppleWebKit%2F537.36%20(KHTML%2C%20like%20Gecko)%20Chrome%2F47.0.2526.73%20Safari%2F537.36&adtype=2&vurl=http%3A%2F%2Flivew.l.qq.com%2Flivemsg%3Fty%3Dweb%26ad_type%3DTP%26pf%3Din%26pt%3D0%26pc%3D0%26vid%3D"..vid.."%26coverid%3D"..coverid.."%26live%3D0%26from%3D0%26pu%3D0%26v%3D"..pversion.."%26plugin%3D1.4.6%26speed%3D3517%26vptag%3D"..ptag.."%26pid%3D"..pid_c.."%26adaptor%3D2%26musictxt%3D%26chid%3D0%26mbid%3D%26guid%3D"..guid_c.."%26url%3D"..UrlEncode(url).."%26refer%3D&reporttime="..getUrlTime1().."&bdua=0&admtype=0&adid=4003&guid="..guid_c.."&ispip=0&random="..tostring( math.random(100,9999)).."' -H 'Host: btrace.video.qq.com' -H 'User-Agent: "..userAgent.."' -H 'Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8' -H 'Accept-Language: en-US,en;q=0.5' --compressed -H 'Cookie: tvfe_boss_uuid="..cookie_uuid.."' -H 'DNT: 1' -H 'Connection: keep-alive'"
SendCurlCmd(sendcurl)
--结束循环
print("\n---------------------finish one loop!-----------------------",nn)
os.execute("sleep " .. 1)
until true
end
