# elasticsearch_plugin使用说明

##下载与安装
下载地址：https://github.com/eosforce/elasticsearch_plugin  
1.下载源码
```bash
git clone https://github.com/eosforce/elasticsearch_plugin
cd elasticsearch_plugin/
git submodule update --init --recursive
```
```注意
代码需要放到eosforce/plugin目录下
```
2.将组件添加到`plugins/CMakeLists.txt`中
```cmake
add_subdirectory(mongo_db_plugin)
add_subdirectory(login_plugin)
add_subdirectory(elasticsearch_plugin)       # add this line.
...
```
3.在nodeos上添加elasticsearch_plugin的注册（修改`programs/nodeos/CMakeLists.txt`文件）
```cmake
target_link_libraries( ${NODE_EXECUTABLE_NAME}
        PRIVATE appbase
        PRIVATE -Wl,${whole_archive_flag} login_plugin               -Wl,${no_whole_archive_flag}
        PRIVATE -Wl,${whole_archive_flag} history_plugin             -Wl,${no_whole_archive_flag}
        ...
        # add this line.
        PRIVATE -Wl,${whole_archive_flag} elasticsearch_plugin       -Wl,${no_whole_archive_flag}
        ...
```
4.重新编译eosfroce源码  
5.将elasticsearch_plugin的相关配置添加到`config.ini`中
```ini
plugin = eosio::elasticsearch_plugin
elastic-url=http://localhost:9200/
elastic-queue-size=512
elastic-abi-cache-size=8192
```
6.运行eosforce
##elasticsearch中的索引
eosforce的elasticsearch_plugin一共建立了8个索引，分别是  
accounts  
blocks  
block_states  
transactions  
transaction_traces  
action_traces  
vote_action  
transfer_action  
8个索引  
EosForce单独把投票(vote_action)和转账(transfer_action)信息分别落索引，方便这两个操作的查询和统计。

#elasticsearch的安装和使用
##下载与安装
1.从https://www.elastic.co/downloads/elasticsearch上面下载最新版本  
2.解压安装包，进入elasticsearch的文件目录中执行./bin/elasticsearch  
3.安装elasticsearch-head插件  
```bash
git clone git://github.com/mobz/elasticsearch-head.git
cd elasticsearch-head
npm install
npm run start
open http://localhost:9100/
```
4.kibana安装  
从 https://www.elastic.co/downloads/kibana上下载和elasticsearch相匹配的版本  
解压下载的安装包  
执行./bin/kibana &  
然后在浏览器上打开http://127.0.0.1:5601进行使用  
##Kibana做图表示例
此图表实现了统计每小时eosforce链上的交易总量信息
1.在浏览器上点击：Management->Index Patterns->Create Index Patterns添加索引模型 此处建立transfer_action的索引模型  
2.点击Visualize然后点击界面上的"+"按钮创建新的图像。此处选的是Line直线图  
3.选择transfer_action索引模型。  
4.设定Y坐标，Aggregation 部分选择 Sum,Field 选择data.quantity.amount。 Custom Label部分输入一个名字  
5.设定X坐标,Aggregation 选择Data Histogram  Field选择createAt Interal选择你需要的时间精度此处选择的是Hourly. Custom Label部分输入一个名字  
6.点击启动按钮启动画线。  

