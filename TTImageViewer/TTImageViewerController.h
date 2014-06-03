//
//  TTImageViewer.m
//  TTImageViewer
//
//  Created by Nicholas Shipes on 11/3/13.
//  Copyright (c) 2013 Urban10 Interactive. All rights reserved.
//
//  Modified by Ian Leitch on 5/29/14.
//  Copyright (c) 2014 Thumbtack. All rights reserved.
//

#import <UIKit/UIKit.h>

@class TTImageViewerController;

@protocol TTImageViewerControllerDelegate <NSObject>

- (NSUInteger)numberOfImagesInImageViewer:(TTImageViewerController *)imageViewer;
- (void)imageViewer:(TTImageViewerController *)imageViewer prepareImageView:(UIImageView *)imageView atIndex:(NSUInteger)index;
@end

@interface TTImageViewerController : UIViewController <UIDynamicAnimatorDelegate, UIGestureRecognizerDelegate>

@property (nonatomic, assign) BOOL shouldBlurBackground;
@property (nonatomic, assign) BOOL parallaxEnabled;

// determines whether or not view should be dismissed when the container view is tapped anywhere outside image bounds
@property (nonatomic, assign) BOOL shouldDismissOnTap;

// determines whether or not view should be dismissed when the container view is tapped within bounds of image view
@property (nonatomic, assign) BOOL shouldDismissOnImageTap;

//determines if view should rotate when the device orientation changes (default YES)
@property (nonatomic, assign) BOOL shouldRotateToDeviceOrientation;

@property (nonatomic, weak) id<TTImageViewerControllerDelegate> delegate;

//- (void)showFromView:(UIView *)fromView;
- (void)showFromView:(UIView *)fromView withInitialIndex:(NSUInteger)index;

//- (void)showImages:(NSArray *)images withInitialImage:(UIImage *)initialImage fromView:(UIView *)fromView;
//- (void)showImage:(UIImage *)image fromView:(UIView *)fromView;
//- (void)showImage:(UIImage *)image fromRect:(CGRect)fromRect;

@end

@interface UIImage (TTAnimatedGIF)
+ (UIImage *)tt_animatedImageWithAnimatedGIFData:(NSData *)data;
@end
