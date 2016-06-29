//
//  ViewController.m
//  PasswordResetTest
//
//  Copyright © 2016年 Kii. All rights reserved.
//

#import "RequestResetViewController.h"
#import "CompleteResetViewController.h"
#import <KiiSDK/Kii.h>

@interface ViewController ()
@property NSString* userIdentifier;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

- (IBAction)onRequestReset:(id)sender {
    NSString* userIdentifier = self.userIdentifierText.text;
    NSString* identifierType = @"";
    NSInteger selected = self.identifierTypeSelector.selectedSegmentIndex;
    switch(selected) {
        case 0: // ID
            identifierType = @"";
            break;
        case 1: // Email
            identifierType = @"EMAIL";
            break;
        case 2: // Phone
            identifierType = @"PHONE";
            break;
        default:
            break;
    }
    userIdentifier = [NSString stringWithFormat:@"%@:%@",identifierType, userIdentifier];
    self.userIdentifier = userIdentifier;
    [KiiUser resetPassword:userIdentifier notificationMethod:KiiSMS_PIN block:^(NSError * _Nullable error) {
        if (error == nil) {
            [self performSegueWithIdentifier:@"resetComplete" sender:nil];
        } else {
            UIAlertController* alert = [UIAlertController alertControllerWithTitle:@"Failed to request reset."
                                                                           message:error.description
                                                                    preferredStyle:UIAlertControllerStyleAlert];

            UIAlertAction* defaultAction = [UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault
                                                                  handler:^(UIAlertAction * action) {}];
            [alert addAction:defaultAction];
            [self presentViewController:alert animated:YES completion:nil];
        }
    }];
}

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    CompleteResetViewController* vc = [segue destinationViewController];
    vc.userIdentifier = self.userIdentifier;
}

@end
