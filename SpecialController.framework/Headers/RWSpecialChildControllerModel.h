//
//  RWSpecialChildControllerModel.h
//  CustomSpecialModule
//
//  Created by 曾云 on 2020/5/21.
//  Copyright © 2020 曾云. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


NS_ASSUME_NONNULL_BEGIN

#define ChildControllerTag 1000

@interface RWSpecialChildControllerModel : NSObject

@property (nonatomic,assign) BOOL isload;/* 🐱 是否加载过 默认 NO */
@property (nonatomic,assign) BOOL isInit;/* 🐱 是否初始化 默认 NO */
@property (nonatomic,strong) UIViewController *childController;/* 🐱 子Controller 默认 nil*/
@property (nonatomic,copy)   NSString *childClassName;/* 🐱 子Controller类名 默认 @""*/
@property (nonatomic,strong) Class childClass;/* 🐱 子Controller类 默认 nil*/

@property (nonatomic,assign) NSInteger childControllerTag;


/// 根据Controller初始化
/// @param childController 子Controller
- (instancetype)initWithChildController:(UIViewController*)childController;


/// 根据Controller类名初始化
/// @param childClassName 子Controller类名
- (instancetype)initWithChildClassName:(NSString*)childClassName;


/// 初始化子Controller类
- (UIViewController *)rw_initChildController;

@end

NS_ASSUME_NONNULL_END
