//
//  CustomFloatView.h
//  CustomSpecialModule
//
//  Created by 曾云 on 2020/5/16.
//  Copyright © 2020 曾云. All rights reserved.
//

#import <UIKit/UIKit.h>





NS_ASSUME_NONNULL_BEGIN

@protocol CustomFloatViewDataSource,CustomFloatViewDelegate;

@interface CustomFloatView : UIView


@property (nonatomic,strong) void (^clickItemBlock)(NSIndexPath *indexPath);

@property (nonatomic,weak) id <CustomFloatViewDataSource>dataSource;
@property (nonatomic,weak) id <CustomFloatViewDelegate>delegate;


- (void)scrollInitem:(NSInteger)index;

@end



#pragma mark - DataSource


@protocol CustomFloatViewDataSource <NSObject>

- (NSInteger)floatView:(CustomFloatView *)floatView numberOfItemsInSection:(NSInteger)section;

- (__kindof UICollectionViewCell *)floatView:(CustomFloatView *)floatView cellForItemAtIndexPath:(NSIndexPath *)indexPath;

@end


#pragma mark - Delegate

@protocol CustomFloatViewDelegate <NSObject>



@end



NS_ASSUME_NONNULL_END
