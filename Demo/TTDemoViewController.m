//
//  TTDemoViewController.m
//  TTImageViewer
//
//  Created by Ian Leitch on 5/29/14.
//  Copyright (c) 2014 Thumbtack. All rights reserved.
//

#import "TTDemoViewController.h"
#import "TTImageViewerController.h"

@interface TTDemoViewController ()
@property (nonatomic, strong) TTImageViewerController *viewer;
@property (nonatomic, strong) NSMutableArray *images;

@end

@implementation TTDemoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor lightGrayColor];

    UIImage *image;
    UIImageView *imageView;
    NSInteger i = 0;
    NSInteger initialOffset = 20;

    for (image in [self images]) {
        imageView = [[UIImageView alloc] initWithFrame:CGRectMake(100, initialOffset + (i * 130), 120, 120)];
        imageView.image = image;
        imageView.contentMode = UIViewContentModeScaleAspectFit;
        imageView.userInteractionEnabled = YES;

        UITapGestureRecognizer *gesture = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(openViewer:)];
        [imageView addGestureRecognizer:gesture];

        [self.view addSubview:imageView];
        i++;
    }
}

- (void)openViewer:(id)sender {
    UITapGestureRecognizer *gesture = sender;
    UIImageView *imageView = (UIImageView *)gesture.view;

    self.viewer = [[TTImageViewerController alloc] init];
    [self.viewer showImages:[self images] withInitialImage:imageView.image fromView:imageView];
}

- (NSArray *)images {
    if (_images) return _images;
    _images = [[NSMutableArray alloc] init];

    for (NSString *name in @[@"img1", @"img2", @"img3", @"img4"]) {
        [_images addObject:[UIImage imageNamed:name]];
    }

    return _images;
}

@end
