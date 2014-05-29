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
@optional

/**
 *  Tells the delegate that the controller's view is visisble. This is called after all presentation animations have completed.
 *
 *  @param mediaFocusViewController The instance that triggered the event.
 */
- (void)mediaFocusViewControllerDidAppear:(TTImageViewerController *)mediaFocusViewController;

/**
 *  Tells the delegate that the controller's view has been removed and is no longer visible. This is called after all dismissal animations have completed.
 *
 *  @param mediaFocusViewController The instance the triggered the event.
 */
- (void)mediaFocusViewControllerDidDisappear:(TTImageViewerController *)mediaFocusViewController;

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

/**
 *  Convenience method for not using a parentViewController.
 *  @see showImage:fromView:inViewController
 */
- (void)showImage:(UIImage *)image fromView:(UIView *)fromView;

/**
 *  Presents focus view from a specific CGRect, useful for using with images located within UIWebViews.
 *
 *  @param image    The full size image to show, which should be an image already cached on the device or within the app's bundle.
 *  @param fromRect The CGRect from which the image should be presented from.
 */
- (void)showImage:(UIImage *)image fromRect:(CGRect)fromRect;

/**
 *  Shows a full size image over the current view or main window. The image should be cached locally on the device, in the app
 *	bundle or an image generated from `NSData`.
 *
 *  @param image                The full size image to show, which should be an image already cached on the device or within the app's bundle.
 *  @param fromView             The view from which the presentation animation originates.
 *  @param parentViewController The parent view controller containing the `fromView`. If `parentViewController` is `nil`, then the focus view will be added to the main `UIWindow` instance.
 */
- (void)showImage:(UIImage *)image fromView:(UIView *)fromView inViewController:(UIViewController *)parentViewController;

@end

@interface UIImage (TTAnimatedGIF)
+ (UIImage *)tt_animatedImageWithAnimatedGIFData:(NSData *)data;
@end
