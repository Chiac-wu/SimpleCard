亦之趣实习测试题，三天写成这样没通过。
# 纸牌游戏demo

采用MVC架构，将视图、逻辑和数据分离

## 1. 功能：

### 关卡配置和卡牌ui资源配置json文件读取

`Resources/levels/levelx.json`存储关卡信息。

`Resources/card_res_config.json`配置卡牌ui资源路径。

### 手牌区顶牌替换

点击手牌区牌，平移到手牌区的顶部牌并替换它作为新的顶部牌。

### 桌面牌和手牌区顶部牌匹配

如桌面牌和顶牌点数相差1则可收入手牌并替换顶牌。

### 动作回退

点击back按钮撤回之前操作

## 2. 实现架构：

### configs

`configs/models`为配置文件类，存放从json中读取的初始数据。

`configs/loaders`json文件读取类。

### controllers

`GameController`负责游戏总业务逻辑，连接视图和模型。

`PlayFieldController`为子控制器，管理纸牌点击逻辑。

### managers

`UndoManager`为回退管理器，管理回退功能逻辑。

### models

游戏核心数据结构，存储游戏数据和状态

`CardModel`存储管理卡牌`id`, 花色, 位置等数据；

`GameModel`存储管理各牌堆卡牌数据；

`UndoModel`存储管理回退动作所需数据。

### services

`GameModelFromLevelGenerator`负责读取关卡数据`LevelConfig`来生成游戏数据`GameModel`。

### views

`CardGameScene`为初始界面，点击开始游戏；

`GameView`为游戏界面，由游戏数据绘制游戏界面；

`CardView`为卡牌组件，由卡牌数据调用对应ui资源生成单个卡牌节点。

### utils

`Shake`为第三方动作类，继承`cocos2d::ActionInterval`实现卡牌抖动效果。
