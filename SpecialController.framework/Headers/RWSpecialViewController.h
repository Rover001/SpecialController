//
//  RWSpecialViewController.h
//  CustomSpecialModule
//
//  Created by 曾云 on 2020/5/10.
//  Copyright © 2020 曾云. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

#define tableTag 1000


typedef NS_ENUM(NSInteger, RWSpecialControllerScrollDirection) {
    RWSpecialControllerScrollDirectionDefault,/* 🐱 默认 静止状态 */
    RWSpecialControllerScrollDirectionHorizontal,/* 🐱 水平滚动（移动） */
    RWSpecialControllerScrollDirectionVertical,/* 🐱 垂直滚动（移动） */
};

@protocol RWSpecialControllerDataSource,RWSpecialControllerDelegate;

@interface RWSpecialViewController : UIViewController


@property (nonatomic,weak) id<RWSpecialControllerDataSource>dataSource;
@property (nonatomic,weak) id<RWSpecialControllerDelegate>delegate;

//@property (nonatomic,assign,readonly) CGFloat rw_headerHeight;/* 🐱 头部View高度  默认 0*/
//@property (nonatomic,readonly) UIView *rw_headerView;/* 🐱 自定义headerView */
//@property (nonatomic,assign,readonly) CGFloat rw_floatHeight;/* 🐱 浮动View高度 默认 0*/
//@property (nonatomic,readonly) UIView *rw_floatView;/* 🐱 自定义floatView */

@property (nonatomic,readonly) NSInteger rw_count;/* 🐱 底部可滚动数量 默认 1 */
//@property (nonatomic,assign,readonly) NSInteger rw_childCount;/* 🐱 SpecialController底部Controller的数量*/

@property (nonatomic,readonly) UIViewController *rw_currentChildController;/* 🐱 SpecialController底部展示(选中)的子Controller */
@property (nonatomic,readonly) NSInteger rw_currentIndex;/* 🐱 SpecialController底部展示(选中)的第几个子Controller */



@property (nonatomic,readonly) NSMutableArray *rw_initViewControllers;


/// 切换底部Controller
/// @param index 需切换子Controller的下标
/// @param animated 是否动画
- (void)rw_scrollChildControllerToIndex:(NSInteger)index animated:(BOOL)animated;


/// 获取子Controller 如果没有初始化，自动初始化
/// @param index 子Controller下标
- (UIViewController *)rw_childControllerInIndex:(NSInteger)index;

/// 获取子Controller
/// @param index 子Controller下标

/// 获取子Controller
/// @param index 子Controller下标
/// @param isInit 是否初始化  YES，如果该对象没有初始化，会自动初始化. NO 如果该对象没有初始化，会返回nil
- (UIViewController *)rw_childControllerInIndex:(NSInteger)index isInit:(BOOL)isInit;

/// 获取 ChildController UITableView 或者 UIConllectionView
/// @param index ChildController下标
//- (UIScrollView *)rw_scrollViewToChildControllerInIndex:(NSInteger)index;


/// 更新SpecialController的底部全部子Controller 会删除以前的FloatView，加载新的FloatView
- (void)rw_reloadToChileControllerInSpecialController;

/// 更新SpecialController的FloatView 会删除以前的FloatView，加载新的FloatView
- (void)rw_reloadToFloatViewInSpecialController;

/// 更新SpecialController的HeaderView 会删除以前的HeaderView，加载新的HeaderView
- (void)rw_reloadToHeaderViewInSpecialController;


@end


#pragma mark - DataSource
@protocol RWSpecialControllerDataSource <NSObject>


/* 🐱
 返回SpecialController的底部控制器数量 默认值为：0
 Returns the number of bottom controllers of SpecialController The default value is: 0

*/
- (NSInteger)rw_numberOfBottomControllerInSpecialController:(RWSpecialViewController *)specialController;

/* 🐱
 返回SpecialController底部控制器的对象 默认值为：@[]
 Returns the object of the controller at the bottom of SpecialController The default value is: @ []

 
 底部控制器的对象的父类必须UIViewController
 The parent class of the bottom controller object must be UIViewController

 数组里面可以是UIViewController对象，也可以是类的字符串@“UIViewController”
 如：@[[[UIViewController alloc]init],@"UIViewController"]
 
 注意：底部控制器内部必须有'UITableView'或者'UICollectionView'，否则会出现意想不到的问题
 Note: There must be 'UITableView' or 'UICollectionView' inside the bottom controller, otherwise there will be unexpected problems
 
 */
- (NSArray *)rw_objectOfBottomControllerInSpecialController:(RWSpecialViewController *)specialController;

@optional

/* 🐱
 返回SpecialController的HeaderView的高度 默认值为：CGFLOAT_MIN
 The height of the HeaderView that returns the SpecialController The default value is: CGFLOAT_MIN
 
 如果rw_heightForHeaderViewInSpecialController 返回值为: CGFLOAT_MIN，也不会显示当前传入的HeaderView
 If the return value of rw_heightForHeaderViewInSpecialController is CGFLOAT_MIN, the currently passed HeaderView will not be displayed
 
*/

- (CGFloat)rw_heightForHeaderViewInSpecialController:(RWSpecialViewController *)specialController;

/* 🐱
 返回SpecialController的HeaderView，默认nil
 Return HeaderView of SpecialController, default nil

 如果实现此协议，必须实现 ‘rw_heightForHeaderViewInSpecialController：’协议方法
 If you implement this protocol, you must implement the ‘rw_heightForHeaderViewInSpecialController:’ protocol method
 
 如果rw_heightForHeaderViewInSpecialController 返回值为0，也不会显示当前传入的HeaderView
 If the return value of rw_heightForHeaderViewInSpecialController is CGFLOAT_MIN, the currently passed HeaderView will not be displayed

*/

- (UIView *)rw_viewForHeaderViewInSpecialController:(RWSpecialViewController *)specialController;


/* 🐱
 返回SpecialController的FloatView的高度 默认值为：CGFLOAT_MIN
 The height of the FloatView that returns the SpecialController The default value is: CGFLOAT_MIN
 
 如果rw_heightForHeaderViewInSpecialController 返回值为: CGFLOAT_MIN，也不会显示当前传入的FloatView
 If the return value of rw_heightForHeaderViewInSpecialController is CGFLOAT_MIN, the currently passed FloatView will not be displayed
 */
- (CGFloat)rw_heightForFloatViewInSpecialController:(RWSpecialViewController *)specialController;

/* 🐱
 返回SpecialController的FloatView，默认nil
 Return FloatView of SpecialController, default nil
 
 如果实现此协议，必须实现 ‘rw_heightForFloatViewInSpecialController：’协议方法
 If you implement this protocol, you must implement the ‘rw_heightForFloatViewInSpecialController:’ protocol method
 
 如果rw_heightForFloatViewInSpecialController 返回值为CGFLOAT_MIN，也不会显示当前传入的HeaderView
 If the return value of rw_heightForFloatViewInSpecialController is CGFLOAT_MIN, the currently passed HeaderView will not be displayed
 
 */
- (UIView *)rw_viewForFloatViewInSpecialController:(RWSpecialViewController *)specialController;




@end

#pragma mark - Delegate
@protocol RWSpecialControllerDelegate <NSObject>


@optional
/* 🐱
 scrollDirection == RWSpecialControllerScrollDirectionVertical，currentController为底部的子Controller
*/
/// 当开始滚动视图时，执行该方法
/// @param scrollView 当前正在操作的scrollView,可能是子Controller的scrollView
/// @param currentController 当前操作的Controller
/// @param scrollDirection 滚动方向

- (void)rw_scrollViewWillBeginDragging:(UIScrollView *)scrollView
                     currentController:(UIViewController *)currentController
                       scrollDirection:(RWSpecialControllerScrollDirection)scrollDirection;


/* 🐱
 scrollDirection == RWSpecialControllerScrollDirectionVertical，currentController为底部的子Controller
*/
/// 视图滚动时，就调用该方法
/// @param scrollView 当前正在操作的scrollView,可能是子Controller的scrollView
/// @param currentController 当前操作的Controller
/// @param scrollDirection 滚动方向
- (void)rw_scrollViewDidScroll:(UIScrollView *)scrollView
             currentController:(UIViewController *)currentController
               scrollDirection:(RWSpecialControllerScrollDirection)scrollDirection;


/* 🐱
 scrollDirection == RWSpecialControllerScrollDirectionVertical，currentController为底部的子Controller
*/
/// 滑动视图，当手指离开屏幕那一霎那，调用该方法。
/// @param scrollView 当前正在操作的scrollView，可能是子Controller的scrollView
/// @param decelerate 视图是否还将继续滚动
/// @param currentController 当前操作的Controller
/// @param scrollDirection 滚动方向

- (void)rw_scrollViewDidEndDragging:(UIScrollView *)scrollView
                     willDecelerate:(BOOL)decelerate
                  currentController:(UIViewController *)currentController
                    scrollDirection:(RWSpecialControllerScrollDirection)scrollDirection;


/* 🐱
 scrollDirection == RWSpecialControllerScrollDirectionVertical，currentController为底部的子Controller
*/
/// 动减速时调用该方法
/// @param scrollView 当前正在操作的scrollView，可能是子Controller的scrollView
/// @param currentController 当前操作的Controller
/// @param scrollDirection 滚动方向
- (void)rw_scrollViewWillBeginDecelerating:(UIScrollView *)scrollView
                         currentController:(UIViewController *)currentController
                           scrollDirection:(RWSpecialControllerScrollDirection)scrollDirection;

/* 🐱
 scrollDirection == RWSpecialControllerScrollDirectionVertical，currentController为底部的子Controller
*/
/// 滚动视图减速完成，滚动将停止时，调用该方法。
/// @param scrollView 当前正在操作的scrollView，可能是子Controller的scrollView
/// @param currentController 当前操作的Controller
/// @param scrollDirection 滚动方向
- (void)rw_scrollViewDidEndDecelerating:(UIScrollView *)scrollView
                      currentController:(UIViewController *)currentController
                        scrollDirection:(RWSpecialControllerScrollDirection)scrollDirection;



/// 其他全部事件回调
/// @param userInfo 通知信息
/// @param currentController 当前操作的Controller
- (void)rw_otherCustomEventsToInfo:(nullable NSDictionary *)userInfo
                 currentController:(UIViewController *)currentController;

/// 点击事件回调
/// @param indexPath 点击的第几个
/// @param scrollView 当前正在操作的scrollView，可能是子Controller的scrollView
/// @param currentController 当前操作的Controller
- (void)rw_didSelectSingleAtIndexPath:(NSIndexPath *)indexPath
                           scrollView:(UIScrollView *)scrollView
                    currentController:(UIViewController *)currentController;

@end

NS_ASSUME_NONNULL_END
