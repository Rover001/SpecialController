//
//  UIViewController+RWScrollNotification.h
//  CustomSpecialModule
//
//  Created by 曾云 on 2020/5/17.
//  Copyright © 2020 曾云. All rights reserved.
//


#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

UIKIT_EXTERN NSNotificationName const RWBeginDraggingNotification;/*  开始拖拽（滚动） */
UIKIT_EXTERN NSNotificationName const RWDidScrollNotification;/* 🐱 滚动时 */
UIKIT_EXTERN NSNotificationName const RWDidEndDraggingWillDecelerateNotification;/* 🐱 拖拽（滑动）结束 */
UIKIT_EXTERN NSNotificationName const RWBeginDeceleratingNotification;/* 🐱 减速开始 */
UIKIT_EXTERN NSNotificationName const RWDidEndDeceleratingNotification;/* 🐱 减速结束（停止） */
UIKIT_EXTERN NSNotificationName const RWDidSelectSingleNotification;/* 🐱 点击事件 */

UIKIT_EXTERN NSNotificationName const RWOtherCustomEventsNotification;/* 🐱 其他自定制事件 */

UIKIT_EXTERN NSString *const RWNotificationScrollView;
UIKIT_EXTERN NSString *const RWNotificationController;
UIKIT_EXTERN NSString *const RWNotificationIndexPath;
UIKIT_EXTERN NSString *const RWNotificationDecelerate;


@interface UIViewController (RWScrollNotification)

/* 🐱   当开始滚动视图时，执行该方法。 */
- (void)rw_ScrollBeginDragging:(UIScrollView *)scrollView;

/* 🐱   scrollView滚动时，就调用该方法。  */
- (void)rw_ScrollDidScroll:(UIScrollView *)scrollView;

/* 🐱   滑动视图，当手指离开屏幕那一霎那，调用该方法。*/
- (void)rw_ScrollDidEndDragging:(UIScrollView *)scrollView willDecelerate:(BOOL)decelerate;

/* 🐱 动减速时调用该方法 */
- (void)rw_ScrollBeginDecelerating:(UIScrollView *)scrollView;

/* 🐱 滚动视图减速完成，滚动将停止时，调用该方法。 */
- (void)rw_ScrollDidEndDecelerating:(UIScrollView *)scrollView;


/* 🐱 UITableView点击Cell或者UICollectionView的Cell点击 */
- (void)rw_DidSelectSingleAtIndexPath:(NSIndexPath *)indexPath scrollView:(UIScrollView *)scrollView;

/* 🐱 其他自定制事件通知 */
- (void)rw_OtherCustomEventsInNotificationInfo:(nullable NSDictionary *)notificationInfo;

/* 🐱 移除通知 */
- (void)rw_RemoveNotification;





@end

NS_ASSUME_NONNULL_END
