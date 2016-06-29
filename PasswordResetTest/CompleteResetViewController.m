//
//  CompleteResetViewController.m
//  PasswordResetTest
//
//  Copyright © 2016年 Kii. All rights reserved.
//

#import "CompleteResetViewController.h"
#import <KiiSDK/Kii.h>

@interface CompleteResetViewController ()
@property (weak, nonatomic) IBOutlet UITextField *pinCodeText;
@property (weak, nonatomic) IBOutlet UITextField *passwordText;
@end

@implementation CompleteResetViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)onCompleteReset:(id)sender {
    NSString* pinCode = _pinCodeText.text;
    NSString* password = _passwordText.text;
    if ([password isEqualToString:@""]) {
        // To Test nil.
        password = nil;
    }
    //[KiiUser completeResetPassword:self.userIdentifier pinCode:pinCode password:nil block:^(NSError * _Nullable error) {
    [KiiUser completeResetPassword:@"0f2968a00022-a539-6e11-2dd3-04861df6"
                           pinCode:pinCode
                          password:password
                             block:^(NSError * _Nullable error) {
        UIAlertController* alert;
        if (error != nil) {
            alert = [UIAlertController alertControllerWithTitle:@"Failed to complete reset."
                                                        message:error.description
                                                 preferredStyle:UIAlertControllerStyleAlert];
        } else {
            alert = [UIAlertController alertControllerWithTitle:@"Reset succeeded!."
                                                        message:@"Congrats!"
                                                 preferredStyle:UIAlertControllerStyleAlert];

        }
        UIAlertAction* defaultAction = [UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault
                                                              handler:^(UIAlertAction * action) {}];
        [alert addAction:defaultAction];
        [self presentViewController:alert animated:YES completion:nil];
    }];
}


@end
