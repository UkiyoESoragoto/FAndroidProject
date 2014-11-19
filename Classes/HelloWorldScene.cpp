#include "HelloWorldScene.h"
#include "DropDownList.cpp"
#include <UISlider.h>

using namespace cocos2d::ui;
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    auto layer = LayerColor::create(Color4B(255,
                                            255,
                                            255,
                                            255));
    layer->setContentSize(visibleSize);
    layer->setPosition(origin);
    
    this->addChild(layer,
                   0);
    
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create("CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback,
                                                         this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
                                origin.y + closeItem->getContentSize().height / 2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem,
                             NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu,
                   1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("Hello World",
                                  "Arial",
                                  24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    

    // add the label as a child to this layer
    this->addChild(label,
                   1);

    // add "HelloWorld" splash screen"
    auto fighterIos = Sprite::create("FighterIos.png");

    // position the sprite on the center of the screen
    fighterIos->setPosition(Vec2(origin.x + fighterIos->getContentSize().width / 2,
                                 origin.y + visibleSize.height / 2));

    // add the sprite as a child to this layer
    this->addChild(fighterIos,
                   0);
    
    this->schedule(schedule_selector(HelloWorld::gameLogic),
                   1.0);
    
    return true;
}// HelloWorld::init


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}// HelloWorld::menuCloseCallback

void HelloWorld::addTarget()
{
    auto *target = Sprite::create("FighterAnd.png");
    auto winSize = Director::getInstance()->getVisibleSize();
    
    auto minY = target->getContentSize().height / 2;
    auto maxY = winSize.height - target->getContentSize().height / 2;
    
    auto rangeY = maxY - minY;
    auto actualY = (rand() % (int)rangeY) + minY;
    
    target->setPosition(Vec2(winSize.width + (target->getContentSize().width / 2),
                             actualY));
    this->addChild(target);
    
    auto minDuration = (int)2.0;
    auto maxDuration = (int)4.0;
    
    auto rangeDuration = maxDuration - minDuration;
    auto acturalDuration = (rand() % rangeDuration) + minDuration;
    
    auto *actionMove = MoveTo::create((float)acturalDuration,
                                      Vec2(0 - target->getContentSize().width / 2,
                                           actualY));
    auto *actionMoveDone = CallFuncN::create(this,
                                             callfuncN_selector(HelloWorld::spriteMoveFinished));
    target->runAction(Sequence::create(actionMove,
                                       actionMoveDone,
                                       NULL));
}//HelloWorld::addTarget

void HelloWorld::spriteMoveFinished(Node *sender)
{
    auto *sprite = (Sprite *)sender;
    this->removeChild(sprite,
                      true);
}//HelloWorld::spreiteMoveFinshed

void HelloWorld::gameLogic(float dt)
{
    this->addTarget();
}//HelloWorld::gameLogic