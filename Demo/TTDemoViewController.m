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
@property (nonatomic, strong) UIButton *button;
@property (nonatomic, strong) TTImageViewerController *viewer;

@end

@implementation TTDemoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor lightGrayColor];

    self.button = [UIButton buttonWithType:UIButtonTypeCustom];
    [self.button setTitle:@"Open Viewer" forState:UIControlStateNormal];
    [self.button setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    [self.button setBackgroundColor:[UIColor blackColor]];
    self.button.layer.cornerRadius = 10.f;
    self.button.translatesAutoresizingMaskIntoConstraints = NO;
    self.view.translatesAutoresizingMaskIntoConstraints = NO;

    [self.button addTarget:self action:@selector(openViewer:) forControlEvents:UIControlEventTouchUpInside];

    [self.view addSubview:self.button];
}

- (void)updateViewConstraints {
    NSDictionary *views = @{@"button" : self.button};
    [self.view addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:|[button(==60)]|" options:0 metrics:nil views:views]];
    [self.view addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"H:|[button(==200)]|" options:0 metrics:nil views:views]];

    [super updateViewConstraints];
}

- (void)openViewer:(id)sender {
    self.viewer = [[TTImageViewerController alloc] init];
    [self.viewer showImages:@[[UIImage imageNamed:@"img1"]] withInitialImage:[UIImage imageNamed:@"img1"] fromView:self.button];
}

@end
