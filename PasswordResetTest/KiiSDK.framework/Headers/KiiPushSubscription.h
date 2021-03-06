//
//  KiiPushSubscription.h
//  KiiSDK-Private
//
//  Created by Riza Alaudin Syah on 1/21/13.
//  Copyright (c) 2013 Kii Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
@class KiiPushSubscription,KiiBucket;
@protocol KiiPrivateSubscribable,KiiSubscribable;

typedef void(^KiiSubscribableBlock)(id<KiiSubscribable> _Nonnull subscribable,BOOL result,NSError *_Nullable error);
typedef void (^KiiPushSubscriptionBlock)(KiiPushSubscription *_Nonnull subscription,NSError *_Nullable error);

/**
This class is responsible for the subscription of push notification.
 @warning Direct instatiations is prohibited, an exception will be thrown if [[KiiPushSubscription alloc] init] is called. 
 KiiPushSubscription should be constructed from <[KiiUser pushSubscription]> or <[KiiThing pushSubscription]> .
*/
@interface KiiPushSubscription : NSObject
NS_ASSUME_NONNULL_BEGIN
/** Synchronously subscribe a subscribable object.
 This is a blocking method.
 @param subscribable A subscribable object. Currently, <KiiBucket> and <KiiTopic> can be subscribed.
 @param error used to return an error by reference (pass NULL if this is not desired). It is recommended to set an actual error object to get the error information.
 @return YES if succeeded, NO otherwise.
 */
-(BOOL) subscribeSynchronous:(id<KiiSubscribable>) subscribable error:(NSError*_Nullable*_Nullable) error;

/** Synchronously unsubscribe a subscribable object.
 This is a blocking method.
 @param subscribable A subscribable object. Currently, <KiiBucket> and <KiiTopic> can be unsubscribed.
 @param error used to return an error by reference (pass NULL if this is not desired). It is recommended to set an actual error object to get the error information.
 @return YES if succeeded, NO otherwise.
 */
-(BOOL) unsubscribeSynchronous:(id<KiiSubscribable>) subscribable error:(NSError*_Nullable*_Nullable) error;

/** Synchronously check whether subscribable object is already subscribed or not
 This is a blocking method.
 
 @param subscribable A subscribable object. Currently, <KiiBucket> and <KiiTopic> can be checked for subscription.
 @param error used to return an error by reference (pass NULL if this is not desired). It is recommended to set an actual error object to get the error information.
 @return BOOL YES if the subscribable object is already subscribed, NO if there is no subscription or there is an error during the calls.
 */
-(BOOL) checkIsSubscribedSynchronous:(id<KiiSubscribable>) subscribable error:(NSError*_Nullable*_Nullable) error;

/** Asynchronously subscribe a subscribable object using block.
 This is a non-blocking method.    

     KiiPushSubscription *aPushSubscription = [[KiiUser currentUser] pushSubscription];
     [aPushSubscription subscribe:aBucket block:^(KiiPushSubscription *subscription, NSError *error) {
         if (nil == error) {
             NSLog(@"Subscribed");
         }
     }];
     
 @param subscribable A subscribable object. Currently, <KiiBucket> and <KiiTopic> can be subscribed.
 @param completion block to handle after process completed
 */
-(void) subscribe:(id<KiiSubscribable>) subscribable block:(KiiPushSubscriptionBlock) completion;

/** Asynchronously unsubscribe a subscribable object using block
 This is a non-blocking method.

     KiiPushSubscription *aPushSubscription = [[KiiUser currentUser] pushSubscription];
    [aPushSubscription unsubscribe:aBucket block:^(KiiPushSubscription *subscription, NSError *error) {
        if (nil == error) {
            NSLog(@"Unsubscribed");
        }
    }];
 
 @param subscribable A subscribable object. Currently, <KiiBucket> and <KiiTopic> can be unsubscribed.
 @param completion block to handle after process completed
 */
-(void) unsubscribe:(id<KiiSubscribable>) subscribable block:(KiiPushSubscriptionBlock) completion;

/** Asynchronously check whether subscribable object is already subscribed or not using block.
 This is a non-blocking method. 

      KiiPushSubscription *aPushSubscription = [[KiiUser currentUser] pushSubscription];
     [aPushSubscription checkIsSubscribed:bucket block:^(id<<KiiSubscribable>> subscribable, BOOL result, NSError *error) {
         if (result) {
          NSLog(@"subscribed");
         }
     }];
 
 @param subscribable A subscribable object. Currently, <KiiBucket> and <KiiTopic> can be checked for subscription.
 @param completion block to handle after process completed
 */
-(void) checkIsSubscribed:(id<KiiSubscribable>) subscribable block:(KiiSubscribableBlock) completion;

/** Asynchronously subscribe a subscribable object using block.
 This is a non-blocking method.    
     [KiiPushSubscription subscribe:aBucket withBlock:^(KiiPushSubscription *subscription, NSError *error) {
         if (nil == error) {
             NSLog(@"Subscribed");
         }
     }];
     
 @param subscribable A subscribable object. Currently, <KiiBucket> and <KiiTopic> can be subscribed.
 @param completion block to handle after process completed
 @deprecated Use instance method instead.
 */
+(void) subscribe:(id<KiiSubscribable>) subscribable withBlock:(KiiPushSubscriptionBlock) completion __attribute__((deprecated("Use instance method instead.")));
/** Asynchronously subscribe a subscribable object using delegate and callback.
 This is a non-blocking method. 
 @param subscribable A subscribable object. Currently, <KiiBucket> and <KiiTopic> can be subscribed.
 @param delegate The object to make any callback requests to
 @param callback The callback method to be called when the request is completed. The callback method should have a signature similar to:
 
    - (void)bucketSubscribed:(KiiPushSubscription*)subscription withError:(NSError*)error {
        // check whether the request was successful
        if (error == nil) {
            // do something
        } else {
            // there was a problem
        }
    }
 
 */
+(void)subscribe:(id<KiiSubscribable>) subscribable withDelegate:(id) delegate andCallback:(SEL) callback __attribute__((deprecated("Use instance method instead.")));


/** Synchronously subscribe a subscribable object.
 This is a blocking method.
 @param subscribable A subscribable object. Currently, <KiiBucket> and <KiiTopic> can be subscribed.
 @param error used to return an error by reference (pass NULL if this is not desired). It is recommended to set an actual error object to get the error information.
 @deprecated Use instance method instead.
 */
+(nullable KiiPushSubscription*) subscribeSynchronous:(id<KiiSubscribable>) subscribable withError:(NSError*_Nullable*_Nullable) error __attribute__((deprecated("Use instance method instead.")));

/** Asynchronously unsubscribe a subscribable object using block
 This is a non-blocking method.
    [KiiPushSubscription unsubscribe:aBucket withBlock:^(KiiPushSubscription *subscription, NSError *error) {
        if (nil == error) {
            NSLog(@"Unsubscribed");
        }
    }];
 
 @param subscribable A subscribable object. Currently, <KiiBucket> and <KiiTopic> can be unsubscribed.
 @param completion block to handle after process completed
 @deprecated Use instance method instead.
 */
+(void) unsubscribe:(id<KiiSubscribable>) subscribable withBlock:(KiiPushSubscriptionBlock) completion __attribute__((deprecated("Use instance method instead.")));


/** Asynchronously unsubscribe a subscribable object using delegate and callback
 This is a non-blocking method.
 @param subscribable A subscribable object. Currently, <KiiBucket> and <KiiTopic> can be unsubscribed.
 @param delegate The object to make any callback requests to
 @param callback The callback method to be called when the request is completed. The callback method should have a signature similar to:
 
    - (void)bucketUnsubscribed:(KiiPushSubscription*)subscription withError:(NSError*)error {
         // check whether the request was successful
         if (error == nil) {
             // do something
         } else {
             // there was a problem
         }
     }

 */
+(void) unsubscribe:(id<KiiSubscribable>) subscribable withDelegate:(id) delegate andCallback:(SEL) callback;

/** Synchronously unsubscribe a subscribable object.
 This is a blocking method.
 @param subscribable A subscribable object. Currently, <KiiBucket> and <KiiTopic> can be unsubscribed.
 @param error used to return an error by reference (pass NULL if this is not desired). It is recommended to set an actual error object to get the error information.
 @deprecated Use instance method instead.
 */
+(nullable KiiPushSubscription*) unsubscribeSynchronous:(id<KiiSubscribable>) subscribable withError:(NSError*_Nullable*_Nullable) error __attribute__((deprecated("Use instance method instead.")));



/** Asynchronously check whether subscribable object is already subscribed or not using block.
 This is a non-blocking method. 
 
     [KiiPushSubscription checkSubscription:bucket withBlock:^(id<KiiSubscribable> subscribable, BOOL result, NSError *error) {
         if (result) {
          NSLog(@"subscribed");
         }
     }];
 
 @param subscribable A subscribable object. Currently, <KiiBucket> and <KiiTopic> can be checked for subscription.
 @param completion block to handle after process completed
 @deprecated Use instance method instead.
 */
+(void) checkSubscription:(id<KiiSubscribable>) subscribable withBlock:(KiiSubscribableBlock) completion __attribute__((deprecated("Use instance method instead.")));

/** Synchronously check whether subscribable object is already subscribed or not
 This is a blocking method.
 
 @param subscribable A subscribable object. Currently, <KiiBucket> and <KiiTopic> can be checked for subscription.
 @param error used to return an error by reference (pass NULL if this is not desired). It is recommended to set an actual error object to get the error information.
 @return BOOL YES if the subscribable object is already subscribed, NO if there is no subscription or there is an error during the calls. 
 @deprecated Use instance method instead.
 */
+(BOOL) checkSubscriptionSynchronous:(id<KiiSubscribable>) subscribable withError:(NSError*_Nullable*_Nullable) error __attribute__((deprecated("Use instance method instead.")));

/** Asynchronously check whether subscribable object is already subscribed or not  using delegate and callback.
 This is a non-blocking method. 
 
 @param subscribable A subscribable object. Currently, <KiiBucket> and <KiiTopic> can be checked for subscription.
 @param delegate The object to make any callback requests to.
 @param callback The callback method to be called when the request is completed. The callback method should have a signature similar to:
 
     - (void)subscribableObject:(id<KiiSubscribable>) subscribable isSubscribed:(BOOL) isSubscribed withError:(NSError*)error {
         // check whether the request was successful
         if (error == nil) {
         // do something
         } else {
         // there was a problem
         }
     }
 @deprecated Use instance method instead.
 */
+(void) checkSubscription:(id<KiiSubscribable>) subscribable withDelegate:(id) delegate andCallback:(SEL) callback __attribute__((deprecated("Use instance method instead.")));
NS_ASSUME_NONNULL_END
@end

@protocol KiiSubscribable <NSObject>



@end
